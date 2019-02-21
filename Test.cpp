#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    
    string input;
    cin >> input;
    
    input += " ";

    int a[n - 1];
    int i = 0;
    string temp;
    while(input != ""){
        string s;
        s = input.substr(0, 1);
        if (s == " "){
            
        }
        a[i] = atoi(s.c_str());
    }
    
    cout << "終了するには何かキーを押してください。"<< endl;
    cin >> n;
    return 0;
}