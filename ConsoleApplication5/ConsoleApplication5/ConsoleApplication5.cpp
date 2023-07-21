//第6章 例題6-2
//配列にデータを入力していき合計値を算出する
#include<stdio.h>
int main(void)
{
    int n, sum;
    double avg;

    n = 0;
    sum = 0;

    int data[51];
    data[50] = -1;

    //最大50件の整数を配列data[]に代入する。
    do {
        printf("配列 data[%d]にデータを入力してください　(-1で終了）\n", n);
        scanf_s("%d", &data[n]);
        n = n + 1;
        if (n == 50) {
            break;
        }
    } while (data[n - 1] != -1);

    n = 0;

    //sumに変数の値を足していく。
    while (data[n] != -1) {
        sum = sum + data[n];
        n = n + 1;
    }

    // int/intだと正しくでないのでキャスト変換している
    if (n > 0) {
        avg = (double)sum / n;
    }
    else {
        avg = 0;
    }

    printf("配列 data[]の合計値は%dです\n", sum);
    printf("平均値は%fです\n", avg);
}