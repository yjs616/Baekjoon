#include <iostream>
using namespace std;

long long n, dp[31][31];

long long go(int whole, int not_whole){
    if(whole == 0 && not_whole == 0) return 1;  
    long long &ret = dp[whole][not_whole]; 
    if(ret) return ret;
    if(whole > 0) ret += go(whole - 1, not_whole + 1); 
    if(not_whole > 0) ret += go(whole, not_whole - 1);
    return ret;   
}
int main(){ 
    while(true){
        cin >> n; if(n == 0)break; 
        cout << go(n, 0) << "\n";
    }
    return 0;
}