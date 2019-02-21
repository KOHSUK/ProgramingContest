#include <stdio.h>

void Answer(int A[], int N, int count){
    int i;
    for ( i = 0; i < N; i++ ){
        if ( i > 0 ) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);
}

void bubbleSort(int A[], int N){
    int i, j, temp, count;
    count = 0;
    for (i = N - 1; i >= 0; i-- ){
        for ( j = 0; j < i; j++ ){
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                count++;
            }
        }
    }
    Answer(A, N, count);
}

int main(){
    int N, i;
    int A[100];
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &A[i]);
    bubbleSort(A, N);
    scanf("%d", &N);
    return 0;
}