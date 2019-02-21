#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

struct proc {
    int time;
    string name;
};

int head = 0, tail = 0;
struct proc queue[1000000];

struct proc dequeue() {
    return queue[head++];
}

void enqueue(proc p) {
    queue[tail++] = p;
}

int count(){
    return tail - head;
}

int main() {
    int n, q, i;
    scanf("%d", &n);
    scanf("%d", &q);

    for(i=0;i<n;i++){
        proc p;
        cin >> p.name;
        cin >> p.time;
        enqueue(p);
    }

    int time = i = 0;
    while (count()>0) {
        proc p = dequeue();
        if(p.time<=q){
            time += p.time;
            cout << p.name << " " << time << endl;
        }else{
            p.time -= q;
            enqueue(p);
            time += q;
        }
    }

    scanf("%d", &n);

}