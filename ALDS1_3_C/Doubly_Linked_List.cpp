#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tagNode {
    int number;
    struct _tagNode * prev;
    struct _tagNode * next;
} node;

node * g_head;
node * g_tail;

void insert_Node(int x){
    node *newNode =(node *)malloc(sizeof(node));
    newNode->number=x;
    newNode->next = g_head;
    newNode->prev = NULL;
    g_head = newNode;
    return;
}

node *search_Node(int x){
    node * tmpNode = g_head;
    while(tmpNode) if(tmpNode->number==x) return tmpNode;
    return NULL;
}

void delete_Node(node *target) {
    target->next->prev=target->prev;
    target->prev->next=target->next;
    free(target);
}

void delete_FirstNode(){
    delete_Node(g_head);
}

void delete_LastNode(){
    delete_Node(g_tail);
}

int main(){
    int n, i;
    scanf("%d", &n);

    g_head = NULL;
    g_tail = NULL;

    for(i=0;i<n;i++){

        char command[11];
        int x = 0;
        scanf("%s", command);
        scanf("%d", &x);

        if(strcmp(command,"insert")==0){
            insert_Node(x);
            continue;
        }else if(strcmp(command,"delete")==0){
            delete_Node(search_Node(x));
            continue;
        }else if(strcmp(command,"deleteFirst")==0){
            delete_FirstNode();
            continue;
        }else{
            delete_LastNode();
            continue;
        }
    }

    node *tmpNode;
    tmpNode = g_head;
    while(tmpNode){

        printf("%d",tmpNode->number);

        if(tmpNode->next!=g_tail) printf(" ");

        tmpNode = tmpNode->next;

    }

    scanf("%d",&n);
    return 0;
}