#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

void outputResult(int a[], int b[], int const aLength, int const bLength){
    for (int i = 0; i < aLength; i++){
        if (i < bLength){
            cout << b[i];
        }else{
            cout << a[i];
        }
        if (i == aLength -1) cout << endl;
        else cout << " ";
    }    
}

void insertionSort(int a[], int const n){
    //要素数分の配列を作る
    int sorted[n - 1];
    //現在ソート済みの要素数
    int sortedN = -1;

    outputResult(a, sorted, n, 0);

    for (int i = 0; i < n; i++){
        
        if (sortedN == -1) {
            sorted[0] = a[i];
        }else{
            //入れ替えるための一時データ保存用の配列
            int tmpAry[sortedN + 1];
            for (int j = 0 , k = 0; j <= sortedN + 1; j++, k++){
                tmpAry[j] = sorted[j];
                if (a[i] < sorted[j]) {
                    sorted[j] = a[i];
                    k--;
                }else {
                    sorted[j] = tmpAry[k];
                }
            }
        }
        sortedN++;
        outputResult(a, sorted, n, i);
    }
}

int main(int argc, char const *argv[])
{
    int n, i;
    scanf("%d", &n);

    int a[n - 1];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    insertionSort(a, n);

    printf("実行終了");
    scanf("%d", &n);


    return 0;
}
