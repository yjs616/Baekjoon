#include <iostream>
#include <vector>
using namespace std;

//1부터 N까지 자연수 중에서 중복없이 M개를 고른 수열
//조합 : nCr
int n, m;
int arr[10];
int visited[10];
vector<int> v; 

void solve(int start, int cnt){
    if(cnt == m){
        //출력
        for(int i=1; i<=n; i++){
            if(visited[i]) cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    //start부터 n까지 숫자선택
    for(int i=start; i<=n; i++){
        if(visited[i] ==0){
            visited[i] = 1;
            solve(i+1, cnt+1);
            visited[i] = 0;
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        arr[i] = i;
    }

    solve(1, 0);

    
    return 0;
}