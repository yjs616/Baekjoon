#include <iostream>
#include <algorithm>
using namespace std;


//점선: 다닐 수 있음
//실선: 못다님

int n, m;              //n이 열이고, m이 행임
int arr[51][51];       //성
int visited[51][51];   //성 방문 여부 
int room_cnt;          //방 갯수
int room_size[2503];    //방 넓이 저장 배열
int max_room_size;     //가장 넓은 방 넓이
int new_big_room;      //합친 방 큰 넓이
int current_room_size=1; //현재 계산하고 있는 방 넓이

//서, 북, 동, 남
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int dfs(int y, int x, int room_id){ //룸 사이즈 리턴해야됨
    visited[y][x]=room_id;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        //벽이 없고, 방문하지 않았는지 체크
        if((arr[y][x] & (1<<i))) continue;
        if(!visited[ny][nx]){
            current_room_size++;
            dfs(ny, nx, room_id);
        }
    }

    return current_room_size;
}

int main(){

    cin >> n >> m;  

    //입력 받기
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    //dfs 탐색
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            //방문여부에 따라 탐색
            if(!visited[i][j]){
                room_cnt++;        //방 갯수
                room_size[room_cnt] = dfs(i, j, room_cnt);   //room_cnt를 넣는 이유는 넓은 방 만들 때 처리하기 위함
                current_room_size=1;  //초기화
            }

            //dfs 탐색 끝났으면 기존 max값하고 비교
            max_room_size = max(max_room_size, room_size[room_cnt]);   //가장 큰 방 업데이트
        }
    }

    //벽 하나 제거했을 때 가장 큰 방
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i+1 < m){
                int a = visited[i+1][j];
                int b = visited[i][j];

                if(a != b) new_big_room = max(new_big_room, room_size[a] + room_size[b]);
            }

            if(j+1 < n){
                int a = visited[i][j+1];
                int b = visited[i][j];

                if(a != b) new_big_room = max(new_big_room, room_size[a] + room_size[b]);
            }
        }
    }

    cout << room_cnt << "\n";
    cout << max_room_size << "\n";
    cout << new_big_room << "\n";


    return 0;
}