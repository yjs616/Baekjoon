#include <iostream>
#include <string>
#include <map>
using namespace std;

int arr[7][7], cnt, ret, ny, nx;
string s;
map<string, int> mp;

int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

void dfs(int y, int x, int cnt){
    if(cnt == 5){
        mp[s]++;   //map에 넣어서 중복 경우 방지
        return;
    }

    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny<0 || ny>=5 || nx <0 || nx>=5 ) continue;

        s += to_string(arr[ny][nx]);
        dfs(ny, nx, ++cnt); 
        s.pop_back();
        cnt-=1;
    }
}

int main(){

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cnt = 0;
            s = to_string(arr[i][j]);
            dfs(i, j, cnt);
        }
    }

    cout << mp.size() << "\n";

    return 0;
}