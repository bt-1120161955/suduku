#include"solveshudu.h"

FILE *solved_shudu = fopen("suduku.txt", "w");
int b[9][9];
bool IsPlaced(int count)
{
	/*�õ���ǰ������ֵ*/
	int row = count / 9;
	int col = count % 9;
	int j = 0;
	/*�м��*/
	for (j = 0; j < 9; j++)
	{
		if (b[row][col] == b[row][j] && j != col)
			return false;
	}
	/*�м��*/
	for (j = 0; j < 9; j++)
	{
		if (b[j][col] == b[row][col] && j != row)
			return false;
	}
	/*ģ����*/
	int tempRow = row / 3 * 3;
	int tempCol = col / 3 * 3;
	for (j = tempRow; j< tempRow + 3; ++j)
	{
		for (int k = tempCol; k < tempCol + 3; ++k) {
			if (b[j][k] == b[row][col] && j != row &&k != col) {
				return false;
			}
		}
	}
	return true;
}
void backtrace(int count)//����
{
	if (count == 81)
	{
		
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				
				fputc((char)(b[i][j]+'0'), solved_shudu);
				fputc(' ', solved_shudu);
			}
			fputc('\n', solved_shudu);
		}
		return;
	}//�������
	 /*�õ�����*/
	int row = count / 9;
	int col = count % 9;
	if (b[row][col] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			b[row][col] = i;//�������
			if (IsPlaced(count))
			{
				backtrace(count + 1);
			}
		}
		b[row][col] = 0;
	}
	else
	{
		backtrace(count + 1);
	}
}

void solve_shudu(char *path)
{
	FILE *unsolved_shudu = fopen(path, "r");
	if (unsolved_shudu == NULL)
		printf("Path is erro!");
	else
	{
		int i, j;
		while (fscanf(unsolved_shudu, "%d", &b[0][0]) != EOF)
		{
			for(i=0;i<9;i++)
				for (j = 0; j < 9; j++)
				{
					if (i == 0 && j == 0)
						continue;
					else
						fscanf(unsolved_shudu, "%d", &b[i][j]);
				}

			backtrace(0);
			memset(b, 0, sizeof(b));
		}
	}
}