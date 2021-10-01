#include <iostream>
#include <vector>
#define N 4
 


class Matrix
{
private:
	int m_size;
	std::vector<std::vector<int>> m_matrix;
public:
	Matrix(int size)
	{
		m_size = size;
		m_matrix.resize(size);
		for(auto &m : m_matrix)
		{
			m.resize(size);
		}
	}

	Matrix(std::vector<std::vector<int>> mat)
	{
		m_size = mat.size();
		m_matrix = mat;
	}
	
	void fillMatrix(float seed = 0)
	{
		srand(seed);
		for(auto &col : m_matrix)
		{
			for(auto &elem : col)
			{
				int i = rand() % 20 - 10;
				elem = i;
			}
		}
	}

	void printMatrix(int width = 3)
	{
		for(auto col : m_matrix)
		{
			for(auto elem : col)
			{
				std::cout.width(width);
				std::cout << elem << " ";
			}
		std::cout << std::endl;
		}
	}

	int getDeterminant()
	{
		return detMatrix(m_matrix, m_size);
	}

private:
	int detMatrix(std::vector<std::vector<int>> &mat, int n)
	{
		
		std::vector<std::vector<int>> temp;
		temp.resize(m_size);
		for(auto &m : temp)
		{
			m.resize(m_size);
		}

		int determinant = 0;
	 
		if (n == 1)
			return mat[0][0];
	 
		int sign = 1; 

		for (int i = 0; i < n; i++)
		{
			getCofactor(mat, temp, i, n);
			determinant += sign * mat[0][i] * detMatrix(temp, n - 1);
			sign = -sign;
		}

		return determinant;
	}


	void getCofactor(std::vector<std::vector<int>> &mat, std::vector<std::vector<int>> &temp, int q, int n)
	{
		int i = 0, j = 0;
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				if (row != 0 && col != q)
				{
					temp[i][j++] = mat[row][col];

					if (j == n - 1)
					{
						j = 0;
						i++;
					}
				}
			}
		}
	}
};

