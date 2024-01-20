#include <iostream>
using namespace std;

int n;

int main(){
    
    cin >> n;
    int i=666;
    for(;;i++){
        if(to_string(i).find("666") != string::npos) n--;
        if(n==0) break;      //n번 다 찾으면 break;
    }

    cout << i << "\n";




    return 0;
}