#include <iostream>
using namespace std;

int a[103][103], b[103][103];
int N, L, num, ret;

void solve(int a[103][103]){
    for(int i=0; i<N; i++){
        int cnt=1;
        int j;
        for(j=0; j< N-1; j++){
            //가능한 경우 3가지
            //같을 때
            if(a[i][j]==a[i][j+1]) cnt++;
            else if(a[i][j]+1 == a[i][j+1] && cnt >=L) cnt=1;  //오르막길
            else if(a[i][j]-1 == a[i][j+1] && cnt >=0) cnt=-L+1; //내리막길
            else break;

        }
        if(j==N-1 && cnt>=0){
            ret++;
        }
        
    }
}



int main(){

    cin >>  N >> L;

    for(int i=0; i< N; i++){
        for(int j=0; j< N; j++){
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }

    solve(a); solve(b);

    cout << ret << "\n";

    return 0;
}