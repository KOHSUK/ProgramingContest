#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top, S[1000];

void push(int x) {
    S[++top] = x;
}

int pop() {
    top--;
    return S[top+1];
}

int main() {
    int a, b;
    top = 0;
    char S[1000];

    while( scanf("%s", S) != EOF ) {
        if ( S[0] == '+' ) {
            a = pop();
            b = pop();
            push(a + b);
        } else if ( S[0] == '-' ) {
            b = pop();
            a = pop();
            push(a - b);
        } else if ( S[0] == '*' ) {
            a = pop();
            b = pop();
            push(a * b);
        } else {
            push(atoi(S));
        }
    }

    printf("%d\n", pop());

    scanf("%d", &a);

    return 0;
}

