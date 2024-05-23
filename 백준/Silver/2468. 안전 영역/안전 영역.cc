#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;

//비가 내렸을 때 물에 잠기지 않은 안전 영역 최대로 몇개 만들어지는지
//일정 높이 이하는 모두 잠긴다. 

//안전영역 connected component
//잠기는 부분은 다 0과 같은 의미, 안전지대는 1과 같은 의미

//안전 영역의 최대 갯수 구하기
//내가 안전 영역의 높이를 설정해야 한다.

int arr[103][103], visited[103][103];
int n, y, x, ny, nx, ret=1;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int y, int x, int h){
    visited[y][x] =1;

    queue<pair<int, int>> q;
    q.push({y, x});
    
    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();

        for(int i=0; i<4; i++){
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || ny >=n || nx<0 ||nx>=n || arr[ny][nx]<=h) continue;
            if(!visited[ny][nx]){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        
        }
    }
}

int main(){
    
    cin >> n;

    int max_hei = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            max_hei = max(max_hei, arr[i][j]);
        }
    }
    
    //높이는 1이상 100이하 정수
    //max_hei는 최대 높이임

    for(int h=1; h <= max_hei; h++){
        int cnt = 0;

        //visited 초기화
        memset(visited, 0, sizeof(visited));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]>h && !visited[i][j]){
                    bfs(i, j, h);
                    cnt++;
                }
            }
        }

        ret = max(ret, cnt);
    }
    
    cout << ret << "\n";

    return 0;
}