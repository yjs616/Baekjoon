#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int dist[203][203];
int n, m, k;
int const INF = 987654321;


int main(){

    cin >> n >> m;

    //dist 초기화
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j) dist[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        dist[s][e] = w;
    }

    //총 인원
    cin >> k;
    vector<int> home;
    for(int i=1; i<=k; i++){
        int h;
        cin >> h;
        home.push_back(h);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int ret = 987654321;
    //왕복
    vector<pair<int, int>> _min;
    for(int i=1; i<=n; i++){
        int _max = 0;    //최대 찾기 위해
        for(int j=0; j < home.size(); j++){
            if(dist[i][home[j]]!= INF && dist[home[j]][i] != INF){
                _max = max(_max, dist[i][home[j]] + dist[home[j]][i]);
            }
        } 
        ret = min(ret, _max);
        _min.push_back({i, _max});
    }


    for(auto x : _min){
        if(x.second == ret) cout << x.first << " ";
    }

    return 0;
}