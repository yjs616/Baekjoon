#include <iostream>
#include <algorithm>
using namespace std;

int n, a[44], ret=987654321;
string s;

void go(int here){
    //기저 사례
    if(here == n+1){
        //행 뒤집/안뒤집어진 상태 -> 이미 결정되어 있는 열의 최적해 
        int sum = 0; 
        for(int i=1; i<= (1 << (n-1)); i*=2){  //1,2,4
            int cnt =0; //열에서 t의 갯수 
            for(int j=1; j<=n; j++){
                if(a[j] & i){ //t가 있는지 판단
                    cnt++;
                }
            }
            sum+= min(cnt, n-cnt);    //뒤집었을 때랑 안뒤집었을 때 t의 갯수 비교
        }
        ret = min(ret, sum);
        return;
    }


    //행 뒤집기
    go(here+1);  //그냥 가기도
    a[here] = ~a[here];
    go(here+1);  //뒤집어서 가기도
}

int main(){

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> s;
        int value = 1;
        for(int j=0; j<s.size(); j++){
            if(s[j]=='T') a[i]|= value;
            value *=2;
        }
    }

    go(1);
    cout << ret << "\n";
    return 0;
}