#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <tuple>
#include <optional>
#include <algorithm>

struct Person
{
	std::string family;
	std::string name;
	std::optional<std::string> surname;
	
};

struct PhoneNumber
{
	int country_code;
	int town_code;
	std::string number;
	std::optional<int> extension;

};

std::ostream& operator<<(std::ostream &out, const struct Person &pers)
{
	out << "Fam: " << pers.family << ", Name: " << pers.name;
	if(pers.surname)
	{
		out << ", Sur: " << pers.surname.value();
	}
	return out;
}

std::ostream& operator<<(std::ostream &out, const struct PhoneNumber &pn)
{

	out << "+" << pn.country_code << "(" << pn.town_code << ")" << pn.number;
	if(pn.extension)
	{
		out << " " << pn.extension.value();
	}
	return out;
}

class PhoneBook
{
private:
	std::vector<std::pair<struct Person, struct PhoneNumber>> m_data;

public:
	PhoneBook();

	PhoneBook(std::ifstream &file)
	{
		std::string tmp;
		char ch;
		struct Person pers;
		struct PhoneNumber num;
		
		int i = 0;
		do
		{

			tmp = "";
			while(!file.eof())
			{
				file.get(ch);

				if(ch == ';') 
				{
					i++;
					break;
				}
				if(ch == ' ') continue;
				if(ch == '\n') 
				{
					i = 0;
					tmp = "";
					continue;
					std::cout << "test";
				}
				tmp += std::string(1, ch);

				
			}
			
			if(tmp != "")
			{
				switch(i)
				{
					case 1:
						pers.family = tmp;
						break;
					case 2:
						pers.name = tmp;
						break;
					case 3:
						pers.surname = tmp;
						break;
					case 4:
						num.country_code = std::stoi(tmp.c_str());
						break;
					case 5:
						num.town_code = std::stoi(tmp.c_str());
						break;
					case 6:
						num.number = tmp;
						break;
					case 7:
						num.extension = std::stoi(tmp.c_str());
						break;
				}
				
			}
			if(i == 7)
			{
				
				m_data.push_back(std::make_pair(pers, num));
				pers = {};
				num = {};
			}

		}			
		while(!file.eof());
		
		file.close();
	}


	void SortByName()
	{
		std::sort(m_data.begin(), m_data.end(), 
			[](std::pair<struct Person, struct PhoneNumber> a, std::pair<struct Person, struct PhoneNumber> b)
			{
				return std::tie(a.first.family, a.first.name, a.first.surname) < std::tie(b.first.family, b.first.name, b.first.surname);
			});
	}
	
	void SortByPhone()
	{
		std::sort(m_data.begin(), m_data.end(), 
			[](std::pair<struct Person, struct PhoneNumber> a, std::pair<struct Person, struct PhoneNumber> b)
			{
				return std::tie(a.second.country_code, a.second.town_code, a.second.number, a.second.extension) < std::tie(b.second.country_code, b.second.town_code, b.second.number, b.second.extension);
			});
	}

	std::tuple<std::string, struct PhoneNumber> GetPhoneNumber(std::string family)
	{
		struct PhoneNumber phone;
		std::string tmp = "";
		int i = 0;
		for(const auto &f : m_data)
		{
			if(family == f.first.family)
			{
				phone = f.second;
				i++;
			}
		}
		switch(i)
		{
			case 0:
				tmp = "Not found";
				phone = {};
				break;

			case 2:
				tmp = "Found more than 1";
				phone = {};
				break;

		}

		return std::make_tuple(tmp, phone);
	}

	void ChangePhoneNumber(struct Person pers, struct PhoneNumber num)
	{
		for(auto &f : m_data)
		{
			if(pers.family == f.first.family)
			{
				f.second = num;
				
			}
		}
	}

	friend std::ostream& operator<<(std::ostream &out, const PhoneBook &pb);
};

std::ostream& operator<<(std::ostream &out, const PhoneBook &book)
{
	int i = 1;
	for(const auto &p:book.m_data)
	{
		out << i++ << " " << p.first << ", Phone: "<< p.second << std::endl;
	}
	return out;
}

std::ostream& operator<<(std::ostream &out, const std::tuple<std::string, struct PhoneNumber> &num)
{

	std::string str;
	struct PhoneNumber phone;
	std::tie(str, phone) = num;
	if(str != "") out << str;
	else out << phone;

	return out;
}
