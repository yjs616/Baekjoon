#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

//우선순위 큐로 접근

const int INF = 98765432;
int v, e, a;
vector<pair<int, int>> map[20003];
int ret[20003];

void go(int start){
    //ret 초기화
    memset(ret, INF, sizeof(ret));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    ret[start]=0;

    while(pq.size()){
        int cur = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        for(auto next : map[cur]){
            int nx = next.first;
            int nx_cost = cur_cost + next.second;

            if(ret[nx] > nx_cost){
                ret[nx] = nx_cost;
                pq.push({nx_cost, nx});
            }
        }
    }
}


int main(){
    cin >>  v >> e;
    cin >> a;

    for(int i=0; i<e; i++){
        int s, e, w;
        cin >> s >> e >> w;
        map[s].push_back({e, w});
    }

    go(a);

    for(int i=1; i<=v; i++){
        if(ret[i] < INF) cout << ret[i] <<"\n";
        else cout << "INF" << "\n";
    }

    return 0;
}