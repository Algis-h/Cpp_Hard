// Task 1
/*
Создайте потокобезопасную оболочку для объекта cout. 
Назовите ее pcout. Необходимо, чтобы несколько потоков могли обращаться к 
pcout и информация выводилась в консоль. Продемонстрируйте работу pcout.
*/

std::mutex m;


void pcout(const int value)
{
	for(int i = 0; i < 100; ++i)
	{
		m.lock();
		std::cout << i << " " << value << " " << std::this_thread::get_id() << std::endl;
		m.unlock();
	}	
}

// Task 2

/*
Реализовать функцию, возвращающую i-ое простое число 
(например, миллионное простое число равно 15485863). 
Вычисления реализовать во вторичном потоке. 
В консоли отображать прогресс вычисления.
*/

int prime(const int &index)
{
	int count = 3;
	int prime = 1;
	int i = 2;

	if(index < 3 && index > 0)
	{
		return index + 1;
	}
	
	while(count <= index)
	{
		for(int j = 2; pow(j, 2) < i; ++j)
		{
			if(i % j == 0)
			{
				break;
			}
			else if(j + 1 > sqrt(i))
			{
				++count;
				prime = i;
			}
		}
		++i;
	}
	return prime;
}


// Task 3

/*
Промоделировать следующую ситуацию. 
Есть два человека (2 потока): хозяин и вор. 
Хозяин приносит домой вещи. При этом у каждой вещи есть своя ценность. 
Вор забирает вещи, каждый раз забирает вещь с наибольшей ценностью.
*/

int offset(const std::vector<int> &v)
{
	return rand()%v.size();
}

void owner(std::vector<int> &v)
{
	int price = rand() % 100;
	m.lock();
	v.insert(v.begin() + offset(v), price);
	m.unlock();
	std::cout << "Добавлена вещь стоимостью: " << price << std::endl;

}

void thief(std::vector<int> &v)
{
	if((float(rand())/RAND_MAX) < 0.35) // 35% вероятность воровства
	{
		auto price = std::max_element(v.begin(), v.end());
		std::cout << "Украдена вещь стоимостью: " << *price << std::endl;
		m.lock();
		v.erase(price);
		m.unlock();
	}
}