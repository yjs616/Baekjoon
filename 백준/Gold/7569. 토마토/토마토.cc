#include <iostream>
#include <queue>
using namespace std;

int M, N, H, arr[103][103][103], visited[103][103][103], nh, ny, nx, days;
bool isUnripe = false;
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};
int dh[]={0, 1, -1};

struct elem{
    int hei, col, row;
};

queue<elem> q;

int main(){

    cin >> M >> N >> H;     //M은 x(행), N은 y(열), H는 h(높이)

    for(int h=1; h<= H; h++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> arr[h][i][j];

                if(!isUnripe){
                    if(arr[h][i][j]==0) isUnripe = true;
                }
                if(arr[h][i][j]==1 && !visited[h][i][j]){
                    q.push({h, i, j});
                    //cout << "현재 q.push하는 h, i, j " << q.front().hei << q.front().col << q.front().row << "\n"; 
                    visited[h][i][j]=1;
                }
            }
        }
    }

    if(isUnripe){ //안익은 토마토가 있을 때
        while(q.size()){
            auto cur = q.front(); q.pop();

            for(int i=0; i<3; i++){
                if(i==0){
                    for(int j=0; j<4; j++){
                        ny = cur.col + dy[j];
                        nx = cur.row + dx[j];

                        if(ny<0 || ny>=N || nx <0 || nx>=M  || arr[cur.hei][ny][nx]==-1) continue;
                        if(arr[cur.hei][ny][nx]==0 && !visited[cur.hei][ny][nx]){
                            visited[cur.hei][ny][nx] = visited[cur.hei][cur.col][cur.row] + 1;
                            q.push({cur.hei, ny, nx});

                            //최소일수 
                            if(days < visited[cur.hei][ny][nx]) days = visited[cur.hei][ny][nx];
                        }
                    }
                }else{//위 아래로 움직이는 경우
                    nh = cur.hei + dh[i];
                    if(nh<1 || nh>H || arr[nh][cur.col][cur.row]==-1) continue;
                    if(arr[nh][cur.col][cur.row]==0 && !visited[nh][cur.col][cur.row]){
                        visited[nh][cur.col][cur.row] = visited[cur.hei][cur.col][cur.row] + 1;
                        q.push({nh, cur.col, cur.row});

                        //최소일수 
                        if(days < visited[nh][cur.col][cur.row]) days = visited[nh][cur.col][cur.row];
                    }
                }
            }

        }

        for(int h=1; h<= H; h++){
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if(arr[h][i][j]==0 && !visited[h][i][j]) days = -1;
                }            
            }
        }

        if(days == -1) cout << -1 << "\n";
        else cout << days-1 << "\n";

    }else{ //안익은게 없을 때
        cout << 0 << "\n";
    }
    return 0;
}