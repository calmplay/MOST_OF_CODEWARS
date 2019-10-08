#include "stdafx.h"

void func_shudu()
{

	int n, i, j, k;
	std::cin >> n >> k;
	for (i = 0; i<n; i++, std::cout << "\n")
	{
		for (j = 0; j<n; j++)
		{
			if (i == j)
			{
				printf("%d ", k);
			}
			else
			{
				printf("0 ");
			}
		}
	}



}


