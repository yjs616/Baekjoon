#include <iostream>
#include <tuple>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


//m : y
//n : x
//k개의 직사각형
//왼쪽 아래 x, y // 오른쪽 위 x, y

//ret이 0일리가 없다 ret=1로 초기화하고 시작하기

int m, n, k;
int arr[104][104], visited[104][104];
int sx, sy, ex, ey, connected_c;
int ny, nx, y, x;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> s;   //넓이 저장하는 백터

void bfs(int y, int x){
    int cnt = 0;
    visited[y][x] = 1;

    queue<pair<int, int>> q;
    q.push({y, x});

    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();
        cnt++;

        for(int i=0; i<4; i++){
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny<0 || ny >=m || nx <0 || nx>=n || !arr[ny][nx]) continue;
            if(!visited[ny][nx]){
                visited[ny][nx] =1;
                q.push({ny, nx});
            }   
        }

    }
    s.push_back(cnt);

}

int main(){

    cin >> m >> n >> k;

    fill(&arr[0][0], &arr[0][0] + 104*104, 1);

    for(int i=0; i<k; i++){
        cin >> sx >> sy >> ex >> ey;

        //해당 부분은 0으로 칠해버리기
        for(int a=sy; a<ey; a++){
            for(int b= sx; b<ex; b++){
                arr[a][b] = 0;
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] && !visited[i][j]){
                bfs(i,j);
                connected_c++;
            }
        }
    }

    //오름차순 정렬
    sort(s.begin(), s.end());

    cout << connected_c << "\n";
    for(int i : s){
        cout << i << " ";
    }

    return 0;
}