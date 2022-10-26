#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NEW_LINE printf("\n");
// two-dimensional array = aTD_

int* get_aMemory(int size) 
{
	return (int*)malloc(sizeof(int) * size);
}

int** get_aTD_Memory(int row, int col)
{
	int** aData = (int**)malloc(sizeof(int*) * row);
	for (size_t i = 0; i < row; i++)
	{
		aData[i] = (int*)malloc(sizeof(int) * col);
	}
	return aData;
}

//Random flow
void fillZero_aTD(int** aData, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			aData[i][j] = 0;
		}
	}
}

void fillRand_aTD(int** aData, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			aData[i][j] = rand()%101-50;
		}
	}
}

void get_aTD_data(int** aData, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			printf("%d\t", aData[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	srand((unsigned int)time(NULL));  // NOLINT(cert-msc51-cpp)

	const int row = 5;
	const int col = 6;

	int** aTD_name = get_aTD_Memory(row, col);

	fillZero_aTD(aTD_name, row, col);
	get_aTD_data(aTD_name, row, col);

	fillRand_aTD(aTD_name, row, col);
	get_aTD_data(aTD_name, row, col);

}

