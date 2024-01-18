#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int m, n, ny, nx, arr[1003][1003], visited[1003][1003], days, ret;
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};
bool isUnripe= false;
queue<pair<int, int>> q;

int main(){

    cin >> m >> n;      //m은 x, n은 y

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];

            if(!isUnripe){
                if(arr[i][j]==0){
                    isUnripe = true;     //익지 않은게 존재한다는거
                }
            }
        }
    }

    if(isUnripe){ //익지 않은 토마토가 존재할 때만 진행
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1 && !visited[i][j]){
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }

        while(q.size()){
            auto cur = q.front(); q.pop();

            for(int i=0; i<4; i++){
                ny = cur.first + dy[i];
                nx = cur.second + dx[i];

                if(ny <0 || ny>= n || nx<0 || nx>=m || arr[ny][nx]==-1) continue;
                if(!visited[ny][nx] && arr[ny][nx]==0){
                    visited[ny][nx] = visited[cur.first][cur.second] + 1;
                    q.push({ny, nx});

                    if(days < visited[ny][nx]) days = visited[ny][nx];
                }
            }

        }

        //0이 남아있는 지 확인 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==0 && !visited[i][j]){
                    days = -1;
                    break;
                }
            }
        }

        if(days == -1) cout << days <<"\n";
        else cout << days-1 << "\n";

    }else{//익은 토마토 밖에 없을 때
        cout << 0 <<"\n";
    }

    return 0;
}
