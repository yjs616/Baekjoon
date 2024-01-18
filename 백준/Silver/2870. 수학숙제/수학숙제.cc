#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s;
string ret="";    //숫자 담는 곳
vector<string> v;

bool cmp(string a, string b){

    //2순위 : 아스키 코드 기반으로 비교
    if(a.size()== b.size()) return a < b;
    //1순위 : 사이즈
    return a.size() < b.size();
}
void go(){
    
    while(ret.size() && ret.front()=='0') ret.erase(ret.begin());

    if(ret.size()==0) v.push_back("0");
    else v.push_back(ret);
    ret="";
}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> s;

        ret="";

        for(int j=0; j<s.size(); j++){
            if(s[j] < 65) ret+= s[j];
            else{
                if(ret.size()) go();
            }
        }

        //마지막 원소 숫자일 때 처리 (아직 push 되지 않은 부분 처리)
        if(ret.size()) go();
    }

    sort(v.begin(), v.end(), cmp);

    for(string i: v){
        cout << i << "\n";
    }

    return 0;
}