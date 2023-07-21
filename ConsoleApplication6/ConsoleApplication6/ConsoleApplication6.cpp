//第6章 6-5 最大、最小値
//配列にデータを入力していき合計値を算出する
#include<stdio.h>
int main(void)
{
    int k, max, min;
    int data[20];

    //最大20件の整数を配列data[]に代入する。
    for (k = 0; k < 20; k++) {
        printf("配列 data[%d]にデータを入力してください\n", k);
        scanf_s("%d", &data[k]);
    }

    // 1件目のデータを仮の最大値、最小値とする。
    max = data[0];
    min = data[0];

    for (k = 1; k < 20; k++) {
        //最大値をmaxに代入する
        if (data[k] > max) {
            max = data[k];
        }
        //最小値をminに代入する
        if (data[k] < min) {
            min = data[k];
        }
    }

    printf("最大値は%dです\n", max);
    printf("最小値は%dです\n", min);
}
