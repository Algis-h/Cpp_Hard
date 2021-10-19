#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>

// Task 3

class FullName
{
// Для удобства тестирования сделал публичными, лучше конечно получать через функции
public:
	std::string m_name;
	std::string m_sname;
	std::string m_family;

	FullName(){};

	FullName(std::string name, std::string sname, std::string family)
		:m_name(name), m_sname(sname), m_family(family)
		{

		}

	// Прегрузка оператора сравнения для поиска
	
	bool operator == (const FullName &fn)
	{
		return tie(m_name, m_sname, m_family) == tie(fn.m_name, fn.m_sname, fn.m_family);
	}
	
};

class IRepository {
    virtual void Open() = 0; // бинарная десериализация в файл
    virtual void Save() = 0; // бинарная сериализация в файл
};


class IMethods {
    virtual double GetAverageScore(const FullName& name) = 0;
    virtual std::string GetAllInfo(const FullName& name) = 0;
    virtual std::string GetAllInfo() = 0;
};




class StudentsGroup:IRepository, IMethods
{
private:
	std::vector<FullName> m_student;
public:
	
	StudentsGroup(){}

	StudentsGroup(FullName name)
		{
			m_student.push_back(name);
		}
	~StudentsGroup()
	{

	}

	void addStudent(FullName name)
	{
		m_student.push_back(name);
	}

	std::string GetAllInfo()
	{
		std::string tmp;
		for(auto &s: m_student)
		{
			tmp += s.m_name + " " + s.m_sname + " " + s.m_family + "\n";

		}
		return tmp;
	}


	std::string GetAllInfo(const FullName& name)
	{
		auto result = std::find(m_student.begin(), m_student.end(), name);

		return (result -> m_name + " " + result -> m_sname + " " + result -> m_family);
	}

	void Open()
	{
		std::string path = "StudentsGroup.txt";
		std::ifstream in(path);

		while(!in.eof())
		{
			FullName tmp;
			in >> tmp.m_name;
			in >> tmp.m_sname;
			in >> tmp.m_family;
			m_student.push_back(tmp);


		}

	}

	void Save()
	{
		std::string path = "StudentsGroup.txt";
		std::ofstream out(path, std::ios::binary);
		for(FullName &s: m_student)
		{
			
			out.write(s.m_name.c_str(), s.m_name.size());
			out.write("\n", 1);
			out.write(s.m_sname.c_str(), s.m_sname.size());
			out.write("\n", 1);
			out.write(s.m_family.c_str(), s.m_family.size());
			out.write("\n", 1);

		}
	}

	// Не реализовано
	
	double GetAverageScore(const FullName& name)
	{
		return 0.2;
	}
	
};

int main(int argc, char const *argv[])
{
	FullName v("Vasia", "Ivanovich", "Petrov");
	FullName p("Petia", "Viktorovich", "Vasin");

	StudentsGroup grp; 	// Класс для сохранения
	StudentsGroup read;	// Класс для чтения

	grp.addStudent(v);
	grp.addStudent(p);

	

	grp.Save();
	read.Open();
	std::cout << read.GetAllInfo() << std::endl;



	return 0;
}