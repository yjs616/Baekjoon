#include <iostream>
using namespace std;

int n, team, asum, bsum;
string s, pre;
char A, B;

string print(int a){
    string d = "00" + to_string(a/60);   //분
    string e = "00" + to_string(a%60);   //초

    return d.substr(d.size()-2, 2) + ":" + e.substr(e.size()-2, 2);
}

int changeToInt(string a){
    return atoi(a.substr(0,2).c_str())* 60 + atoi(a.substr(3, 5).c_str());
}

void go(int &sum, string s){
    sum += (changeToInt(s)- changeToInt(pre));
}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> team >> s;

        if(A>B) go(asum, s);
        else if(A<B) go(bsum, s);
        team == 1 ? A++ : B++; 
        pre = s;

    }

    if(A>B) go(asum, "48:00");
    else if(A<B) go(bsum, "48:00");

    cout << print(asum) << "\n";
    cout << print(bsum) << "\n";

    return 0;
}