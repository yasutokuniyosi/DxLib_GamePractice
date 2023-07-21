#include<stdio.h>

int main(void)
{
	int i, j;
	i = 0;
	j = 0;

	//C言語での宣言と初期化例（行と列）
	int ma[9][9];

	//内容の表示
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			ma[i][j] = (i + 1) * (j + 1);
			printf("%3d ", ma[i][j]);
		}
		printf("\n");
	}
}