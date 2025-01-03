#include <iostream>
#include <string>
using namespace std;

//"pi", "ka", "chu"만 발음할 수 있음

string s;

int main(){

    cin >> s;

    //빈 문자열이 될 때까지
    while(s != ""){
        if(s[0]== 'p' && s[1]=='i'){
            s.erase(0, 2);

        }else if(s[0]=='k' && s[1]=='a'){
            s.erase(0,2);
        }else if(s[0]=='c' && s[1]=='h' && s[2]=='u'){
            s.erase(0,3);
        }else{
            //위 3조건에 만족되는게 없으면
            break;
        }
    }

    if(s=="") cout << "YES";
    else cout << "NO";

    return 0;
}