#pragma once

// Task 1

void swap(int *a, int *b)
{
	auto tmp = *a;
	*a = *b;
	*b = tmp;
}

void insert_sorted(std::vector<int> &arr, int value)
{
	arr.resize(arr.size() + 1);
	for(auto i = arr.begin(); i < arr.end(); i++)
	{
		if(value <= *i || i == arr.end() - 1)
		{
			swap(&*i, &value);
		}
	}
}



// Task 2

float CalcError(std::vector<float> &vec)
{
	return std::accumulate(vec.begin(), vec.end(), 0.0, [](float x, float y)
		{
			return x + pow((y - floor(y)), 2);
		});
}

void PrintVectorF(std::vector<float> &vec)
{
	for(auto v : vec)
	{
		std::cout << v << ", ";
	}
	std::cout << std::endl;
}

void PrintVectorI(std::vector<float> &vec)
{
	for(auto v : vec)
	{
		std::cout << floor(v) << ", ";
	}
	std::cout << std::endl;
}

void PrintVector(std::vector<int> &vec)
{
	for(auto v : vec)
	{
		std::cout << v << ", ";
	}
	std::cout << std::endl;
}
