#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;  

vector<int> number; 
vector<char> oper; 
int n, ret = -987654321;
string s; 

int cal(int a, char b, int c){
    if(b == '+') return a + c; 
    if(b == '-') return a - c; 
    if(b == '*') return a * c;  
} 

void go(int here, int _num){
    if(here == number.size() - 1){ 
        ret = max(ret, _num); 
        return;
    }  
    go(here + 1, cal(_num, oper[here], number[here + 1]));

    if(here + 2 <= number.size() - 1){
        int temp = cal(number[here + 1], oper[here + 1], number[here + 2]); 
        go(here + 2, cal(_num, oper[here], temp));  
    } 
    return;
} 
int main(){
    cin >> n;  
    cin >> s; 
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) number.push_back(s[i] - '0');
        else oper.push_back(s[i]);
    } 
    go(0, number[0]);  
    cout << ret << "\n";
    return 0;
} 