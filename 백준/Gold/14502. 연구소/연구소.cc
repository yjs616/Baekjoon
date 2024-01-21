#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a[10][10], visited[10][10], ret, ny, nx;
int dy[]={-1,0, 1, 0};
int dx[]={0, 1, 0, -1};
vector<pair<int, int>> wallList, virusList;

void dfs(int y, int x){
    visited[y][x]=1;

    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny <0 || ny >=n || nx<0 || nx>=m || a[ny][nx]==1) continue;
        if(!visited[ny][nx]){
            dfs(ny, nx);
        }
    }
}

int solve(){
    fill(&visited[0][0], &visited[0][0]+ 10*10, 0);

    //바이러스 퍼뜨리기
    for(pair<int, int> b : virusList){
        dfs(b.first, b.second);
    }

    int cnt=0;
    //안전영역 세기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==0 && !visited[i][j]){
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];

            if(a[i][j]==0) wallList.push_back({i, j});
            if(a[i][j]==2) virusList.push_back({i,j});
        }
    }

    //조합을 이용해서 wallList에서 벽을 세울 3개 택하기
    for(int i=0; i<wallList.size(); i++){
        for(int j=0; j<i; j++){
            for(int k=0; k<j; k++){
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, solve());      //매 경우의 수에 대해서 계산 시작
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }

    cout << ret << "\n";

    return 0;
}