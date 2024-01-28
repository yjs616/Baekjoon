#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

int n, visited[103][103], ny, nx;
char arr[103][103];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
char cur;
int ret1, ret2;
bool isRGsame;

//일반적
void bfs(int y, int x){
    visited[y][x] = 1;

    queue<pair<int, int>> q;
    q.push({y, x});

    while (q.size()){
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n )
                continue;

            if(!isRGsame){//색약 x
                if (arr[ny][nx] == cur && !visited[ny][nx]){
                visited[ny][nx] = 1;
                q.push({ny, nx});
                }
            }else{ //색약
                if(cur=='R' || cur=='G'){
                    if (arr[ny][nx] == 'B' || visited[ny][nx]) continue;
                }else{
                    if (arr[ny][nx] != cur || visited[ny][nx]) continue;
                }
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                cur = arr[i][j];
                bfs(i, j);
                ret1++;
            }
        }
    }

    //visited 초기화 하기
    memset(visited, 0, sizeof(visited));
    isRGsame= true;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                cur = arr[i][j];
                bfs(i,j);
                ret2++;
            }
        }
    }

    cout << ret1 << " " << ret2 << "\n";

    return 0;
}