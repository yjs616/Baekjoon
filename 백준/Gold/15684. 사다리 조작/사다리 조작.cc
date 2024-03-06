#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int n, m, h, a, b, visited[34][34];
int ret = INF;

//i번째가 i번째로 나오는지 체크
bool check(){
    for(int i=1; i<=n; i++){
        int start = i;
        for(int j=1; j<=h; j++){
            if(visited[j][start]) start++;
            else if(visited[j][start-1]) start--;
        }

        if(start != i) return false;
    }

    return true;
}


//here은 h 위치
void go(int here, int cnt){
    if(cnt > 3 || cnt >= ret) return;
    if(check()){
        ret = min(ret, cnt);   //성공
        return;
    }

    //백트래킹
    for(int i= here; i<=h; i++){
        for(int j=1; j<n; j++){
            if(visited[i][j] || visited[i][j+1] || visited[i][j-1]) continue;
            visited[i][j] =1;
            go(i, cnt+1);
            visited[i][j]=0;
        }
    }
}

int main(){

    cin >> n >> m >> h;
    
    //주어진 가로선에 대한 정보
    for(int i=0; i<m; i++){
        cin >> a >> b;
        visited[a][b] = 1;      //입력으로 주어진 것 최대한 그대로 넣기
    }
 
    go(1, 0);
    
    cout << ((ret == INF) ? -1 : ret) << "\n";


    return 0;
}