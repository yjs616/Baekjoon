#include <iostream>
#include <algorithm>
using namespace std;

int n, number[10];
char op[13];
vector<string> ret;

bool isCal(char x, char y, char op){
    if(x < y && op=='<') return true;
    if(x > y && op=='>') return true;
    return false;
}

void go(int idx, string num){

    //끝
    if(idx == n+1){
        ret.push_back(num);
        return;
    }

    for(int i=0; i<=9; i++){
        if(number[i]) continue;
        //이전 숫자, 지금 비교할 숫자, 부등호
        if(idx==0 || isCal(num[idx-1], i+'0', op[idx-1])){
            number[i]=1;
            go(idx+1, num+ to_string(i));
            number[i]=0;
        }        
    }

}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> op[i];
    }

    go(0, "");

    sort(ret.begin(), ret.end());

    cout << ret[ret.size()-1] << "\n";
    cout << ret[0] << "\n";

    
}