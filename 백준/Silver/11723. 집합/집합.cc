#include <iostream>
#include <vector>
using namespace std;

int state;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;
    while(m--){
        string com;
        int x;
        cin >> com;
        if(com=="add"){
            cin >> x;
            state |= (1 << (x-1));
        }else if(com=="remove"){
            cin >> x;
            state &= ~(1 << (x-1));
        }else if(com=="check"){
            cin >> x;
            cout << (state >> (x-1) & 1) << "\n";

        }else if(com == "toggle"){
            cin >> x;
            state ^= (1 << (x-1));
        }else if(com =="all"){
            state = 0xfffff;
        }else{
            //empty
            state = 0;
        }
    }

    return 0;
}