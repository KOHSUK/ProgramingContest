#include<stdio.h>
using namespace std;


int main(){
    int n, q;
    scanf("%d",&n);
    int S[10000], T[500];
    for(int i=0;i<n;i++) scanf("%d",&S[i]);
    scanf("%d",&q);
    for(int i=0;i<q;i++) scanf("%d",&T[i]);

    int count = 0;
    for(int i=0;i<q;i++){
        int t = T[i];
        for(int j=0;j<n;j++){
            int s = S[j];
            if(t==s) {
                count++;
                break;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}