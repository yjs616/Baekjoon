#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, parent[1003];

struct Edge{
    int s, e, w;
    bool operator > (const Edge& temp) const{
        return w > temp.w;
    }
};

int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

void uni(int a, int b){
    int aRoot = find(a);
    int bRoot = find(b);

    if(aRoot == bRoot) return;
    parent[aRoot] = bRoot;
}



int main(){

    cin >> n;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    //parent 초기화
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int w;
            cin >> w;

            if(i>=j) continue;
            pq.push(Edge{i, j, w});

        }
    }

    int cnt =1;
    long long ret =0;
    while(cnt <= n-1){
        Edge now = pq.top();
        pq.pop();

        //cout << "현재 now.s : " << now.s << "현재 now.e : " << now.e << "현재 now.w : " << now.w << "\n";

        if(find(now.s) != find(now.e)){
            uni(now.s, now.e);
            ret += now.w;
            cnt++;
        }
    }

    cout << ret << "\n";


    return 0;
}