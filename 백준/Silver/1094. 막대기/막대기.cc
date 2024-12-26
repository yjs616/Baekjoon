#include <iostream>
using namespace std;


int x, cnt=1;

int main(){

    cin >> x;

    int sum = 64;
    for(int i = 32; i>0; (i >>= 1)){

        if(sum == x) break;

        //---------------------

        //업데이트
        if(sum > x){
            sum=i;
            continue;
        }else if(sum < x){
            if(sum + i > x) continue;
            else sum += i;
        }

        cnt++;

    }

    cout << cnt << "\n";
    return 0;
}