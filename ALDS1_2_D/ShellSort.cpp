#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int cnt;
void insertionSort(int n, int A[], int g){
    int i,j,v;
    for (i=g;i<n;i++){
        v=A[i];
        j=i-g;
        while(j>=0&&A[j]>v){
            A[j+g]=A[j];
            j=j-g;
            cnt++;
        }
        A[j+g]=v;
    }
}

void answer(int n, int A[]){
    int i;
    for(i=0;i<n;i++) cout << A[i] << endl;
}

void shellSort(int n, int A[]){
    int m;
    cnt=0;
    m = (int)(log(n<3?3:n)/log(3));
    int G[m],g,i;
    g=n;
    for(i=0;i<m;i++){
        g = (int)g/3;
        if(i==m-1)g=1;
        G[i]=g;
        insertionSort(n,A,g);
    }
    cout << m << endl;
    for(i=0;i<m;i++) cout << (i!=0?" ":"") << G[i];
    cout << endl << cnt << endl;
    answer(n,A);
}

int main(){
    int n;
    cin >> n;
    int A[n-1],i;
    for(i=0;i<n;i++) cin >> A[i];
    shellSort(n,A);
    scanf("%d",&n);
    return 0;
}