class Arr
{

private:
	int * m_arr;
	int m_size;
public:
	class Iter
	{
	private:
		int * m_ptr;
	public:
		Iter(int *arr)
			:m_ptr(arr)
			{}

		int &operator++ ()
		{
			return *++m_ptr;
		}


		bool operator!= (Iter & pos)
		{
			return m_ptr != pos.m_ptr;
		}

		int &operator*()
		{
			return *m_ptr;
		}
	};
	
	Iter begin()
	{
		return m_arr;
	}

	Iter end()
	{
		return m_arr + m_size;
	}

	Arr(int * arr, int size)
		:m_arr(arr), m_size(size){}
};