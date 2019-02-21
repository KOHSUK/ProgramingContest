#include<stdio.h>
#include<iostream>
#include<string>

const int PRIMES = 1046527;
char HashTable[PRIMES][14] = {'\0'};

int uniqueCode(char key){
    if(key=='A'){
        return 1;
    }else if(key=='C'){
        return 10;
    }else if(key=='G'){
        return 100;
    }else{
        return 1000;
    }
}

void insert(char key[]){
    int i=0, code=0;

    while(key[i]){
        code += uniqueCode(key[i]);
        i++;
    }

    int hash1 = code % PRIMES;
    int hash2 = (PRIMES - hash1) % PRIMES;
    int hashVal = hash1;

    i = 1;
    while(HashTable[hashVal][14]!='\0') hashVal = (hash1 + hash2 * ++i) % PRIMES;

    for(i=0;i<14;i++){
        HashTable[hashVal][i] = key[i];
    }
    HashTable[hashVal][14] = '1';
}

bool find(char key[]){
    int i=0, code=0;
    while(key[i]){
        code += uniqueCode(key[i]);
        i++;
    }

    int hash1 = code % PRIMES;
    int hash2 = (PRIMES - hash1) % PRIMES;
    int hashVal = hash1;

    int found = 0;
    i = 1;
    while(HashTable[hashVal][14]!='\0') {
        hashVal = (hash1 + hash2 * ++i) % PRIMES;
        for(int j=0;j<14;j++){
            if(HashTable[hashVal][j]!=key[j]) found = 1;
        }
        if(found) return true;
    }

    return false;
}

int main(){
    int n;
    scanf("%d",&n);

    std::string ans[5000];

    int index = 0;
    for(int i=0;i<n;i++){
        char command[10];
        scanf("%s",command);
        char key[12];
        if(command[0]=='i'){
            scanf("%s",key);
            insert(key);
        }else{
            scanf("%s",key);
            if (find(key)){
                ans[index] = "yes\n";
            }else{
                ans[index] = "no\n";
            }
            index++;
        }
    }

    for(int i=0;i<index;i++) std::cout << ans[i];
    scanf("%d",&n);

    return 0;
}