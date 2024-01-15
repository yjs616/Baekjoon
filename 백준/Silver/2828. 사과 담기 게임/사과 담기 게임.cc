#include <iostream>
using namespace std;

int n, m,tcnt, num, ret;

int main(){

    cin >> n >> m;

    int l = 1;
    int r = l+m-1;

    cin >> tcnt;
    for(int i=0; i<tcnt; i++){
        cin >> num;

        if(num >=l && num <= r) continue;
        else if(num > r){
            while(r != num){
                r++;
                l++;
                ret++;
            }
        }else if(num < l){
            while(l != num){
                r--;
                l--;
                ret++;
            }
        }
    }

    cout << ret;

    return 0;
}