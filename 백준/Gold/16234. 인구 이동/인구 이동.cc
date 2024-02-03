#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <string.h>
using namespace std;

int n, L, R, arr[53][53], visited[53][53], ny, nx, sum, ansCnt;
vector<pair<int, int>> v;
int dy[]={-1,0, 1, 0};
int dx[]={0, 1, 0, -1};
bool flag = 0;

void bfs(int y, int x){
    visited[y][x]=1;

    queue<pair<int, int>> q;
    q.push({y, x});

    while(q.size()){
        tie(y, x) = q.front(); q.pop();

        for(int i=0; i<4; i++){
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny<0 || ny >=n || nx <0 || nx>=n) continue;

            int distance = abs(arr[y][x]- arr[ny][nx]);

            if(distance < L || distance >R) continue;

            if(!visited[ny][nx]){
                visited[ny][nx]=1;
                q.push({ny, nx});
                v.push_back({ny, nx});
                sum+= arr[ny][nx];
            }          
        }
    }
}

int main(){

    cin >> n >> L >> R;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    while(true){
        flag = false; 
        memset(visited, 0, sizeof(visited));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    v.clear();
                    sum = arr[i][j];
                    v.push_back({i, j});
                    bfs(i, j);

                    if(v.size()==1) continue;    //v에 자기 자신밖에 없으면
                    for(pair<int, int> p : v){
                        arr[p.first][p.second] = sum/ v.size();
                        flag = true;
                    }
                }
            }
        }

        if(!flag) break;
        else ansCnt++;
    }

    cout << ansCnt << "\n";
    

    return 0;
}