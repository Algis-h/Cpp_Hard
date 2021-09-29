#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "function.h"
#include "timer.h"



int main(int argc, char const *argv[])
{
	
	// Task 1

	std::cout << "Задание №1" << std::endl;
	int a = 10;
	int b = 5;

	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << "Swap" << std::endl;
	swap(&a, &b);

	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << "_______________________" << std::endl;

	
	// Task 2

	std::cout << "Задание №2" << std::endl;

	std::vector<int*> vec;

	std::cout << "Оригинальный вектор" << std::endl;
	FillVector(vec, 25);
	PrintVector(vec);
	std::cout << "Отсортированный вектор" << std::endl;
	SortPoiner(vec);
	PrintVector(vec);

	// std::cout << "a: " << a << " b: " << b << std::endl;

	std::cout << "_______________________" << std::endl;

	
	// Task 3

	std::cout << "Задание №3" << std::endl;

	Timer timer;


	std::string path = "War and peace.txt";
	std::ifstream file(path);
	if(!file.is_open())
	{
		std::cout << "Файл не может быть открыт!!!" << std::endl;
		return 1;
	}
	
	int num = 0;

	timer.start("count_if, find");
	num = FindVowel_a(file);
	timer.print();
	std::cout << "Количество гласных в файле '" << path << "' равно: " << num << std::endl;
	std::cout << std::endl;

	file.seekg(0);
	timer.start("count_if, for");
	num = FindVowel_b(file);
	timer.print();
	std::cout << "Количество гласных в файле '" << path << "' равно: " << num << std::endl;
	std::cout << std::endl;


	file.seekg(0);
	timer.start("for, find");
	num = FindVowel_c(file);
	timer.print();
	std::cout << "Количество гласных в файле '" << path << "' равно: " << num << std::endl;
	std::cout << std::endl;


	file.seekg(0);
	timer.start("for, for");
	num = FindVowel_d(file);
	timer.print();
	std::cout << "Количество гласных в файле '" << path << "' равно: " << num << std::endl;
	std::cout << std::endl;


	std::cout << "_______________________" << std::endl;

	return 0;
}