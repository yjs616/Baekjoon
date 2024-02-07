#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, a[3], visited[64][64][64]; 
int _a[6][3]={
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,3,9},
    {1,9,3}
};

struct A{
    int a, b, c;
};

int solve(int a, int b, int c){
    visited[a][b][c]=1;
    queue<A> q;
    q.push({a, b, c});

    while(true){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        if(a==0 && b==0 && c==0) break;
        for(int i=0; i<6; i++){
            int na = max(0, a-_a[i][0]);
            int nb = max(0, b-_a[i][1]);
            int nc = max(0, c-_a[i][2]);

            if(!visited[na][nb][nc]){
                visited[na][nb][nc] = visited[a][b][c]+1;
                q.push({na, nb, nc});
            }
        }
    }
    return visited[0][0][0]-1;
}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << solve(a[0], a[1], a[2]);    //입력을 못받으면 자동적으로 0으로 저장됨.

    return 0;
}