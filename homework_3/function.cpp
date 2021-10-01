#pragma once

template<typename T1, typename T2, typename T3>
T1 fit01(T1 x, T2 new_min, T3 new_max)
{
	static_cast<T1>(new_min);
	static_cast<T1>(new_max);
	return x * (new_max - new_min) + new_min;
}

void FillList(std::list<float> &list, unsigned int size)
{
	for (int i = 0; i < size; ++i)
	{
		float j = (fit01(static_cast<float>(rand())/RAND_MAX, -1, 1)) * 100;
		list.push_back(j);
	}
}

void PrintList(std::list<float> &list)
{
	for(auto l:list)
	{
		std::cout << l << " ";
	}
	std::cout << std::endl;
}

void average(std::list<float> &list)
{
	float sum = 0;
	int size = list.size();
	for(float l:list)
	{
		sum += l;
	}
	list.push_back(sum/size);
}

