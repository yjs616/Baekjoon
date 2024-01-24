#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, arr[103][103], visited[103][103], cnt;
vector<pair<int, int>> melt;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int ny, nx;

void dfs(int y, int x){
    visited[y][x]=1;

    if(arr[y][x]==1){
        melt.push_back({y, x});
        return;
    }

    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny <0|| ny >=n || nx<0 || nx>=m) continue;
        if(!visited[ny][nx]){
            dfs(ny, nx);
        }
        
    }

}

int main(){
    cin >> n >> m;  //n : 열

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    while(true){
        fill(&visited[0][0], &visited[0][0] + 103*103, 0);   //visited 초기화
        melt.clear();    //vector 초기화
        dfs(0,0);

        //dfs 종료되면
        for(auto b : melt){
            arr[b.first][b.second]=0;
        }
        cnt++;

        int flag =0;
        //언제 반복문 나가? 맵에서 1 없으면
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1){
                    flag = 1;
                }
            }
        }

        if(!flag) break;     
    }

    cout << cnt << "\n";
    cout << melt.size() << "\n";
    
    return 0;
}