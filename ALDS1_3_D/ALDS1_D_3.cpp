#include <stdio.h>
#include <string.h>

using namespace std;

enum lineType{
    Up,
    Down,
    Horiontal
};

typedef struct p{
    int x;
    int y;
}Pos;

typedef struct line{
    Pos startPos;
    Pos endPos;
    int type;
}Line;

int main(){
    char c[200000];
    
    scanf("%s",c);

    // int totalArea = 0;
    // int puddleCount = 0;
    int len = strlen(c);
    for(int i=0;i<len-1;i++){
        if(strncmp(&c[i],"\\",1)==0){
            printf("a\n");
        }
    }

    // printf("%s\n",&c[0]);
    // printf("%s\n",&c[1]);
    // printf("%s\n",&c[2]);


    scanf("%d",&len);

    return 0;
}