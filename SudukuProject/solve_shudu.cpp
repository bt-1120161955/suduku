#include"solveshudu.h"

FILE *solved_shudu = fopen("suduku.txt", "w");
int b[9][9];
bool IsPlaced(int count)
{
	/*得到当前的坐标值*/
	int row = count / 9;
	int col = count % 9;
	int j = 0;
	/*行检测*/
	for (j = 0; j < 9; j++)
	{
		if (b[row][col] == b[row][j] && j != col)
			return false;
	}
	/*列检测*/
	for (j = 0; j < 9; j++)
	{
		if (b[j][col] == b[row][col] && j != row)
			return false;
	}
	/*模块检测*/
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
void backtrace(int count)//回溯
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
	}//输出数据
	 /*得到坐标*/
	int row = count / 9;
	int col = count % 9;
	if (b[row][col] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			b[row][col] = i;//填充数字
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