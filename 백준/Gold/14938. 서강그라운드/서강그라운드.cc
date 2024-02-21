#include <iostream>
#include <algorithm>
using namespace std;

int dist[103][103], items[103];
int n, m, r;
int const INF = 987654321;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> r;    //m 수색범위, r 길이개수


    //dist 초기화
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!= j) dist[i][j] =INF;
        }
    }

    for(int i=1; i<=n; i++){
        cin >> items[i]; 
    }
    
    for(int i=1; i<=r; i++){
        int s, e, w;
        cin >> s >> e >> w;
        dist[s][e] = w;
        dist[e][s] = w;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    //예은이가 위치에 따라서
    //1부터 n까지
    int ret =0;
    for(int i=1; i<=n; i++){//예은이 위치
        int sum =0;
        for(int j=1; j<=n; j++){
            if(dist[i][j] <= m){
                sum += items[j];
            }
        }
        ret = max(ret, sum);
    }

    cout << ret << "\n";


    return 0;
}