#include <iostream>
#include <algorithm>
using namespace std;

string A0[36];

void isStable(string A[], int N){
    string check[36][4], check2[36][4], mark; 
    int i, j, index;
    for (i=0;i<N;i++){
        index = atoi(A[i].substr(1).c_str());
        mark = A[i].substr(0);
        for (j=0;j<4;j++){
            if (check[index][j]=="") {
                check[index][j] = mark;
                mark = "";
            }
        }
    }
    for (i=0;i<N;i++){
        index = atoi(A0[i].substr(1).c_str());
        mark = A0[i].substr(0);
        for (j=0;j<4;j++){
            if (check2[index][j]=="") {
                check2[index][j] = mark;
                mark = "";
            }
        }
    }
    string result = "Stable";
    for (i=0;i<36;i++){
        for(j=0;j<4;j++){
            if (check[i][j] != check2[i][j] ) result = "Not stable";
        }
    }
    cout << result << endl;
}

void Output(string A[], int N){
    int i;
    for(i=0;i<N;i++) cout << (i!=0?" ":"") << A[i];
    cout << endl;
    isStable(A, N);
}

void SelectionSort(string A[], int N){
    int i, j, min;
    for(i=0;i<N;i++){
        min = i;
        for(j=i;j<N;j++){
            if ( atoi(A[j].substr(1).c_str())<atoi(A[min].substr(1).c_str())) min = j;
        }
        swap(A[i], A[min]);
    }
    Output(A, N);
}

void BubbleSort(string A[], int N){
    int i, j;
    for (i=N-1;i>0;i--){
        for(j=0;j<i;j++){
            if ( atoi(A[j].substr(1).c_str())>atoi(A[j+1].substr(1).c_str()) ) swap(A[j],A[j+1]);
        }
    }
    Output(A, N);
}

int main(){
    int N, i;
    string temp, A1[36], A2[36];
    cin >> N;
    for (i=0;i<N;i++) {
        cin >> temp;
        A0[i] = A1[i] = A2[i] = temp;
    }
    BubbleSort(A1, N);
    SelectionSort(A2, N);
    scanf("%d",&N);
    return 0;
}





