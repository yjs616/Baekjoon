#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <string.h>
using namespace std;

int n, m, INF = 98765432;
int pre[1003];
vector<pair<int, int>> map[1003];
vector<int> ret;
int dp[1003];

void go(int start) {
    memset(dp, INF, sizeof(dp));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dp[start] = 0;

    while (!pq.empty()) {
        int x = pq.top().second;
        int xcost = pq.top().first;
        pq.pop();

        if(xcost > dp[x]) continue;

        for (auto a : map[x]) {
            int nx = a.first;
            int nxcost = xcost + a.second;

            if (dp[nx] > nxcost) {
                dp[nx] = nxcost;
                pq.push({nxcost, nx});
                pre[nx] = x;
            }
      
        }
        
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        map[s].push_back({e, w});
    }

    int a, b;
    cin >> a >> b; 

    go(a);

    cout << dp[b] << "\n";

    vector<int> v;
    v.push_back(b);
    int tmp = pre[b];  //거슬러올라가기
    while(tmp != a){
        v.push_back(tmp);
        tmp = pre[tmp];
    }
    v.push_back(a);


    cout << v.size() << "\n";
    for(int i = v.size()-1; i>=0; i--){
        cout << v[i] << " ";
    }


    return 0;
}
