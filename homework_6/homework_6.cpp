#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <cmath>
#include "homework_6.h"

int main(int argc, char const *argv[])
{
	
	std::cout << "Задание №1" << std::endl;

	std::thread th1(pcout, 10);
	std::thread th2(pcout, 11);
	std::thread th3(pcout, 12);
	th1.join();
	th2.join();
	th3.join();

	std::cout << "_______________________" << std::endl;

	std::cout << "Задание №2" << std::endl;

	int index = 0;

	// std::cout << "Введите прядковый номер простого числа: " << std::endl;
	// std::cin >> index;
	
	int result = 0;
	std::thread pr([&]()
		{
			result = prime(index);
		});
	pr.join();

	std::cout << "Порядковый номер "<< index << " принадлежит простому числу: " << result << std::endl;
	std::cout << "_______________________" << std::endl;

	std::cout << "Задание №3" << std::endl;

	

	// std::thread ow;
	// std::thread th;

	std::vector<int> thing;
	thing.resize(10);
	
	int count = 10;

	srand(2); // Сид случайных чисел
	
	while(thing.size() > 0 && count != 0)
	{
		
		std::thread ow(owner ,ref(thing));
		std::thread th(thief ,ref(thing));

		--count;

		ow.join();
		th.join();

	}

	std::cout << "_______________________" << std::endl;

	
	return 0;
}