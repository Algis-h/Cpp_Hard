#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include "function.h"


int main(int argc, char const *argv[])
{
	
	// Task 1

	std::cout << "Задание №1" << std::endl;

	std::vector<int> arr(10);

	generate(arr.begin(), arr.end(), []{return (static_cast<float>(rand())/RAND_MAX - 0.5) * 2 * 10;});
	sort(arr.begin(), arr.end());

	std::cout << "Оригинальный массив" << std::endl;
	PrintVector(arr);
	
	int insert = 3;
	std::cout << "Вставлено число: "<< insert << std::endl;
	insert_sorted(arr, insert);
	PrintVector(arr);

	std::cout << "____________________________________________" << std::endl;

	
	// Task 2

	std::cout << "Задание №2" << std::endl;

	std::vector<float> input(100);

	generate(input.begin(), input.end(), []{return (static_cast<float>(rand())/RAND_MAX - 0.5) * 2 * 100;});

	std::cout << "Аналоговый сигнал:" << std::endl;
	PrintVectorF(input);
	std::cout << "Цифровой сигнал:" << std::endl;
	PrintVectorI(input);
	
	float result = CalcError(input);

	std::cout << "Погрешность составляет: " << result << std::endl;
	std::cout << "____________________________________________" << std::endl;
	return 0;
}