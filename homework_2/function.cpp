#pragma once

template<typename T>
void swap(T *a, T *b)
{
	auto tmp = *a;
	*a = *b;
	*b = tmp;
}

void FillVector(std::vector<int*> &vec, unsigned int size)
{
	for (int i = 0; i < size; ++i)
	{
		int *j = new int(rand()%100);
		vec.push_back(std::move(j));
	}
}

void PrintVector(std::vector<int*> &vec)
{
	for(auto v:vec)
	{
		std::cout << *v << " ";
	}
	std::cout << std::endl;
}

void SortPoiner(std::vector<int*> &vec)
{
	std::sort(vec.begin(), vec.end(), [](int* a, int* b)
		{
			return *a < *b;
		});
}

int FindVowel_a(std::ifstream &file)
{
	std::string vowel = "AaEeOoUuIiYy";

	int num = std::count_if(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), [&vowel](char ch)
		{
;

			return vowel.find(ch, 0) != std::string::npos;
		});

	return num;
}

int FindVowel_b(std::ifstream &file)
{
	std::string vowel = "AaEeOoUuIiYy";

	int num = std::count_if(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), [&vowel](char ch)
		{
			for (int i = 0; i < vowel.size(); ++i)
			{
				if(ch == vowel[i]) return true;
			}

			return false;
		});

	return num;
}

int FindVowel_c(std::ifstream &file)
{
	std::string vowel = "AaEeOoUuIiYy";
	int num = 0;
	std::string str(std::istreambuf_iterator<char>{file}, {});
	for(auto ch: str)
	{
		num += (vowel.find(ch, 0) != std::string::npos);
	}

	return num;
}

int FindVowel_d(std::ifstream &file)
{
	std::string vowel = "AaEeOoUuIiYy";
	int num = 0;
	std::string str(std::istreambuf_iterator<char>{file}, {});
	for(auto ch: str)
	{
		for (int i = 0; i < vowel.size(); ++i)
			{
				if(ch == vowel[i]) num++;
			}
	}
	return num;
}