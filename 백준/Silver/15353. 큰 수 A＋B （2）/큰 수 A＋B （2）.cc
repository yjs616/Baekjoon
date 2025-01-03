#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;

string cal(string n1, string n2){

    int sum = 0;
    string ret;
    while(n1.size() || n2.size() || sum){  //sum은 올림 처리
        if(n1.size()){
            sum += n1.back() - '0';
            n1.pop_back();
        }

        if(n2.size()){
            sum += n2.back() - '0';
            n2.pop_back();
        }

        //최종 저장
        ret += (sum % 10) + '0';
        sum /= 10;

    }

    reverse(ret.begin(), ret.end());

    return ret;
}

int main(){

    cin >> a >> b;

    cout << cal(a, b);
    

    return 0;
}