#include <iostream>
using namespace std;

string s;
int alpabet[27];

int main(){

    cin >> s;
    for(int i=0; i<s.size(); i++){
        alpabet[s[i]-'a'] +=1;
    }

    for(int i=0; i<26; i++){
        cout << alpabet[i] << " ";
    }

    return 0;
}