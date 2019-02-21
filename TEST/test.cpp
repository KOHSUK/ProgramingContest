#include <stdio.h>
#include <stddef.h>
#include <string.h>

using namespace std;

typedef struct _tagNode {

    //ID
    int number;

    struct _tagNode * prev;
    struct _tagNode * next;

} node;

node * g_head;
node * g_tail;

node insert_Node(int x){
    node newNode;
    newNode.number=x;
    newNode.next = g_head;
    newNode.prev = NULL;
    g_head = &newNode;
    return newNode;
}

void delete_Node(int x){
    node *tmpNode;
    tmpNode = g_head;
    while(tmpNode->next==NULL){
        if(tmpNode->number==x){
            //次のノードに接続する
            tmpNode->next->prev=tmpNode->prev;
            tmpNode->prev->next=tmpNode->next;
            break;
        }
        tmpNode = tmpNode->next;
    }
}

void delete_FirstNode(){
    if(g_head!=NULL) g_head=g_head->next;
}

void delete_LastNode(){
    if(g_tail!=NULL) g_tail=g_tail->prev;
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

        if(strncmp(command,"insert",6)){
            printf("test");

            insert_Node(x);
            continue;
        }else if(strncmp(command,"delete",6)){
            delete_Node(x);
            continue;
        }else if(strncmp(command,"deleteFirst",11)){
            delete_FirstNode();
            continue;
        }else if(strncmp(command,"deleteLast",10)){
            delete_LastNode();
            continue;
        }
    }

    node tmpNode;
    tmpNode = *g_head;
    printf("%d",tmpNode.number);

    scanf("%d",&n);
    return 0;

}