#include <iostream>
using namespace std;

int n;
int cnt=0;
string s1="\"재귀함수가 뭔가요?\"";
string s2="\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
string s3="마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
string s4="그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
string s5 ="라고 답변하였지.";

void solve(string s , int n){
    cout << s << s1 << "\n";
    if(cnt == n){
        cout << s << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << "\n";
        return;
        
    }else{
        cout << s << s2 <<"\n";
        cout << s << s3 <<"\n";
        cout << s << s4 <<"\n";
    }

    s += "____";
    cnt+=1;
    solve(s, n);
    cout << s << s5 << "\n";
}


int main(){

    cin >> n; 

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    solve("", n);
    cout << s5;

    return 0;
}