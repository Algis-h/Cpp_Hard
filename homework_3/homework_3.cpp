#include <iostream>
#include <list>
#include "function.h"
#include "iterator.h"
#include "determinant.cpp"



	


int main(int argc, char const *argv[])
{
	// Task 1

	std::cout << "Задание №1" << std::endl;
	std::list<float> list;
	FillList(list, 25);
	std::cout << "Оригинал: " << std::endl;
	PrintList(list);

	std::cout << "Среднее в конце: " << std::endl;
	average(list);
	PrintList(list);

	std::cout << "______________________________" << std::endl;


	// Task 2

	std::cout << "Задание №2" << std::endl;

	Matrix mat4({ 	{ 1, 0, 2, -1 },
					{ 3, 0, 0,  5 },
					{ 2, 1, 4, -3 },
					{ 1, 0, 5,  0 } });

	mat4.printMatrix(3);
	std::cout <<"Определитель : " << mat4.getDeterminant() << std::endl;

	Matrix mat7({ 	{ 5, 3, 6, 8, 4, 2, 5 },
					{ 4, 8, 9, 6, 5, 4, 2 },
					{ 3, 2, 4, 5, 6, 8, 7 },
					{ 1, 2, 3, 6, 9, 8, 5 }, 
					{ 6, 6, 3, 2, 1, 1, 4 },
					{ 5, 4, 7, 8, 5, 6, 3 },
					{ 2, 5, 4, 7, 8, 9, 8 }});

	mat7.printMatrix(3);
	std::cout <<"Определитель : " << mat7.getDeterminant() << std::endl;

	Matrix mat3(3);
	mat3.fillMatrix();
	mat3.printMatrix();
	std::cout <<"Определитель : " << mat3.getDeterminant() << std::endl;

	// Проверка производилась на сайте https://ru.onlinemschool.com/math/assistance/matrix/determinant/
	
	std::cout << "______________________________" << std::endl;


	// Task 3

	std::cout << "Задание №3" << std::endl;
	
	int arr[5] = {5, 4, 3, 2, 1};
	Arr array(arr, 5);

	for(auto a: array)
	{
		std::cout << a;
	}
	std::cout << std::endl;

	std::cout << "______________________________" << std::endl;

	return 0;
}