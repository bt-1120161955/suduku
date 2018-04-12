#define _CRT_SECURE_NO_WARNINGS
#include"solveshudu.h"
#include "shuduzhongju.h"



int judge(char *argv);


int main(int argc, char *argv[])
{

	argc = 2;
	char c[3] = { 0 }, s[3] = { 0 };
	c[0] = '-', c[1] = 'c';
	s[0] = '-', s[1] = 's';

	if (argc > 3) {
		printf("Input is erro!");

	}
	else if (argc == 2)
	{
		if (!strcmp(argv[1], "-c"))
		{
			int num = judge(argv[2]);
			if (num == -1)
				printf("Input is erro");
			else
				creat_shudu(num);
		}
		else if (!strcmp(argv[1], s))
		{
			solve_shudu(argv[2]);
		}
	}
		
	return 0;
}

int judge(char *argv)
{
	int num=0;
	int len = strlen(argv);
	for (int i = 0; i < len; i++)
	{
		if (!(argv[i] >= '0'&&argv[i] <= '9'))
			return -1;
		else
			num = num * 10 + (int)(argv[i] - '0');
	}

	return num;
}