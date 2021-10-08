#pragma once

// Task 1
/*
Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов, 
и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то вывести его надо один раз). 
Продемонстрировать работу функции, передав итераторы различных типов.
*/

template<typename T>
void uni(T begin, T end)
{
	std::map<std::string, int> counter;
	for_each(begin, end, [&counter](std::string str)
	{
		++counter[str];
	});
	
	for(auto &c : counter)
	{
		std::cout << c.first << std::endl;
	}
}

// Task 2

/*
Используя ассоциативный контейнер, напишите программу, 
которая будет считывать данные введенные пользователем 
из стандартного потока ввода и разбивать их на предложения. 
Далее программа должна вывести пользователю все предложения, отсортировав их по длине.
*/
struct My_str
{
	std::string str;

	bool operator< (const struct My_str &a) const
	{
		return str.size() < a.str.size();
	}
};

std::string getDelims(const std::string &str, const int &start, int &pos)
{
	int tmp = str.size();
	std::string delims = ".!?";
	std::string delim = "";
	for(auto &s : delims)
	{
		int p = str.find(s, start);

		if(p < tmp && p != std::string::npos)
		{
			tmp = p;
			delim = s;

		}
	}
	return delim;
}

