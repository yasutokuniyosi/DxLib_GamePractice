//配列にデータを入力していき合計値を算出する
#include<stdio.h>
int main(void)
{
    int n, sum;
    n = 0;
    sum = 0;

    int data[10];

    //10件の整数を配列data[]に代入する。
    for (n = 0; n < 10; n++) {
        printf("配列 data[%d]にデータを入力してください\n", n);
        scanf_s("%d", &data[n]);
    }

    //sumに変数の値を足していく。
    for (n = 0; n < 10; n++) {
        sum = sum + data[n];
    }

    printf("配列 data[0]からdata[9]の合計値は%dです\n", sum);

}