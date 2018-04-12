#include "shuduzhongju.h"


FILE *out_shudu=fopen("shuduzhongju.txt", "w");
int shift[9] = { 3,6,1,4,7,2,5,8 };
struct node {
	int n;
	int m;
}pix1[4] = { {0,0}, {2,3},{2,4},{3,4} };
struct node1{
	int n;
	int m;
}pix2[4] = { {0,0}, { 5,6 },{ 5,7 },{ 6,7 } };
int jiaohuan(char shudu_bian[10][10],int num,int n)
{
	int ii,jj;
	for (jj = 0; jj < 4; jj++)
	{
		for (ii = 0; ii < 6; ii++)
		{
			if (!ii && !jj)
				;
			else
				if(num<n)
				{
					int temp = shift[pix1[ii].n];
					shift[pix1[ii].n] = shift[pix1[ii].m];
					shift[pix1[ii].m] = temp;
					temp = shift[pix2[jj].n];
					shift[pix2[jj].n] = shift[pix2[jj].m];
					shift[pix2[jj].m] = temp;
					int k = 0;
					for (int i = 0; i < 9; i++)
					{
						if (k)
						{
							for (int l = 0; l < 9; l++)
								shudu_bian[k][(l + shift[i - 1]) % 9] = shudu_bian[0][l];
						}
						for (int c = 0; c < 9; c++)
						{
							if (c) fputc(' ', out_shudu);
							fputc(shudu_bian[k][c], out_shudu);
						}
						fputc('\n', out_shudu);
						k++;
					}
					fputc('\n', out_shudu);
					temp = shift[pix1[ii].n];
					shift[pix1[ii].n] = shift[pix1[ii].m];
					shift[pix1[ii].m] = temp;
					temp = shift[pix2[jj].n];
					shift[pix2[jj].n] = shift[pix2[jj].m];
					shift[pix2[jj].m] = temp;
					num++;
				}	
		}
	}
	
	return num;
}
void permutation(int* a, int k, int m,int *Num,int n)
{
	char shudu[10][10];
	int shu[8];
	
	memset(shudu, 0, sizeof(shudu));
	int tmp;
	int i, j;
	if (k == m)
	{
		if (*Num < n) {
			for (i = 0; i <= m; i++)
			{
				shu[i] = a[i];
			}
			*Num = *Num + 1;          
			//通过变换生成数独
			int k = 0, l = 0;
			shudu[0][0] = '2';
			for (i = 0; i < 8; i++)
			{
				shudu[0][i + 1] = shu[i] + '0';
			}
			for (i = 0; i < 9; i++)
			{
				if (k)
				{
					for (l = 0; l < 9; l++)
						shudu[k][(l + shift[i-1]) % 9] = shudu[0][l];
				}
				for (int c = 0; c < 9; c++)
				{
					if (c) fputc(' ', out_shudu);
					fputc(shudu[k][c], out_shudu);
				}
				fputc('\n', out_shudu);
				k++;
			}
			fputc('\n', out_shudu);
			char shudu_bian[10][10];
			strcpy(shudu_bian[0], shudu[0]);
			*Num=jiaohuan(shudu_bian, *Num, n);
		}
	}
	else
	{
		for (j = k; j <= m; j++)
		{
			//交换
			tmp = a[j];
			a[j] = a[k];
			a[k] = tmp;
			permutation(a, k + 1, m, Num,n);
			//交换
			tmp = a[j];
			a[j] = a[k];
			a[k] = tmp;
		}
	}
}
void creat_shudu(int n)
{
	int a[9] = { 1,3,4,5,6,7,8,9 };
	int len = 8;

	int Num;
	Num = 0;
	permutation(a, 0, len - 1, &Num,n);
	fclose(out_shudu);
}
