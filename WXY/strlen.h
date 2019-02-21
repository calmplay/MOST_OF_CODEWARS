using namespace std;
#include "stdio.h"

int Strlen(const char *str)
{
	if (str[0] == NULL)
	{
		return 0;
	}
	else
		return Strlen(++str) + 1;
}