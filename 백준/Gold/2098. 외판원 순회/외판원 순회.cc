#include <iostream>
#include <cstring>
using namespace std;

int n, arr[16][16];
int dp[16][1<<16];   //위치, 방문
const int INF = 987654321;

int tsp(int here, int visited){
    //기저사례
    if(visited == (1<<n)-1){
        return arr[here][0] ? arr[here][0] : INF;    //arr[here][0]의 값이 있다는 것은 모든 점을 방문했다는 것
    }

    //메모이제이션
    int &ret = dp[here][visited];
    if(ret != -1) return ret;
    ret = INF;    //최소 문제니까 최대값부터 시작함

    for(int i=0; i<n; i++){
        if(visited & (1 << i)) continue;   //만약 방문했다면
        if(arr[here][i]==0) continue;
        ret = min(ret, tsp(i, visited | (1 << i)) + arr[here][i]);
    }

    return ret;

}


int main(){

    cin >> n;


    for(int i=0; i <n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    //초기화
    memset(dp, -1, sizeof(dp));

    //0번부터 순회하면서 최소 저장
    cout << tsp(0, 1);


    return 0;
}