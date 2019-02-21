#include<stdio.h>
using namespace std;

int binarySearch(int t, int S[], int n){
    int left, right, mid;
    left = 0;
    right = n;
    while(left < right){
        mid = (left + right) / 2;
        if(t > S[mid]){
            left = mid + 1;
        }else if(t < S[mid]){
            right = mid;
        }else{
            return t == S[mid];
        }
    }
    return 0;
}

int main(){
    int n, q, t, cnt = 0;
    scanf("%d",&n);
    int S[1000000];
    for(int i=0;i<n;i++) scanf("%d",&S[i]);
    scanf("%d",&q);

    for(int i=0;i<q;i++){
        scanf("%d",&t);
        if(binarySearch(t,S,n)) cnt++;
    }

    printf("%d\n",cnt);

    scanf("%d",&n);
    return 0;
}