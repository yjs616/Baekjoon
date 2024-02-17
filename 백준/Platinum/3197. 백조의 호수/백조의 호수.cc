#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int r, c, swanY, swanX, cnt, y, x, ny, nx;
char a[1503][1503];
int water_visited[1503][1503], swan_visited[1503][1503];
queue<pair<int, int>> waterQ, temp_waterQ, swanQ, temp_swanQ;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void tempQclear(queue<pair<int, int>>& q){
    queue<pair<int, int>> empty;
    swap(q, empty);
}

//빙하를 녹이자
void waterMelting(){
    while(waterQ.size()){
        tie(y, x) = waterQ.front(); waterQ.pop();

        for(int i=0; i<4; i++){
            ny = y +dy[i];
            nx = x +dx[i];

            if(ny <0 || ny >=r || nx<0 || nx>=c) continue;
            if(!water_visited[ny][nx]){
                if(a[ny][nx]=='X'){
                    water_visited[ny][nx]=1;
                    a[ny][nx]='.';
                    temp_waterQ.push({ny, nx});
                }
            }
        }
    }
}


//L 둘다 bfs로 움직여야 한다. -> 복잡
//백조 한마리를 기준으로 생각한다.
bool moveSwan(){ //백조들이 만날 수 있는가?
    while(swanQ.size()){
        tie(y, x) = swanQ.front(); swanQ.pop();

        for(int i=0; i<4; i++){
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || ny >= r || nx <0 || nx>=c) continue;
            if(!swan_visited[ny][nx]){
                swan_visited[ny][nx]=1;
                if(a[ny][nx]=='X'){
                    //일시정지
                    temp_swanQ.push({ny, nx});
                }else if(a[ny][nx]=='.'){
                    swanQ.push({ny, nx});
                }else if(a[ny][nx]=='L'){
                    //만났다.
                    return true;
                }
            }
        }
    }
    return false;
} 



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> a[i][j];

            if (a[i][j] == 'L'){
                swanY=i; swanX=j;
            }
            if(a[i][j]=='.' || a[i][j]=='L'){
                water_visited[i][j]=1;
                waterQ.push({i, j});
            } 
        }
    }

    swan_visited[swanY][swanX] = 1;
    swanQ.push({swanY, swanX});

    while(true){
        //백조가 움직일 수 있는지
        if(moveSwan()) break;
        //빙하를 녹여보자
        waterMelting();
        //잠시 멈춘 부분 이어서 
        waterQ = temp_waterQ;
        swanQ = temp_swanQ;
        //다시 새로 담아가야 하니까 임시 큐들 초기화 
        tempQclear(temp_waterQ);
        tempQclear(temp_swanQ);
        cnt++;   
    }

    cout << cnt << "\n";

    return 0;
}