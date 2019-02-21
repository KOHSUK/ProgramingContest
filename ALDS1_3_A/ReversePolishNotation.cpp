#include <iostream>
#include <string>

using namespace std;

int top;

const int MAX = 200;
int stack[MAX];

void initialize(){
    top = 0;
}

bool isEmpty(){
    return top == 0;
}

bool isFull(){
    return top >= MAX -1;
}

bool push(int x){
    if (isFull()) return false;
    top++;
    stack[top] = x;
    return true;
}

int pop(){
    if (isEmpty()) return 0;
    top--;
    return stack[top+1];
}

int main(){

    initialize();

    string s , input;

    getline(cin,input);
    input += " ";

    std::string::size_type pos1 = 0, pos2 = input.find(" ");

    int result;
    while(pos2 != std::string::npos){
        s = input.substr(pos1, pos2-pos1);

        int n, m;
        if(s=="+") {
            n = pop();
            m = pop();
            result = m + n;
        }else if(s=="-"){
            n = pop();
            m = pop();
            result = m - n;
        }else if(s=="*"){
            n = pop();
            m = pop();
            result = m * n;
        }else{
            result = atoi(s.c_str());
        }
        push(result);
        pos1 = pos2 + 1;
        pos2 = input.find(" ", pos1);
    }

    cout << pop() << endl;
    int n;
    scanf("%d", &n);
    return 0;
}