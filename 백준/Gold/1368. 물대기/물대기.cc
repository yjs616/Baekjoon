#include <iostream>
#include <queue>
using namespace std;

int n, parent[303];

struct Edge{
    int s, e, w;
    bool operator > (const Edge& temp) const{
        return w > temp.w;
    }
};

int find(int n){
    if(parent[n]== n) return n;
    else return parent[n] = find(parent[n]);
}

void uni(int a, int b){
    int aRoot = find(a);
    int bRoot = find(b);

    if(aRoot == bRoot) return;
    else parent[aRoot] = bRoot;
}

//가상 노드 0 만들기
int main(){

    cin >> n;

    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    //가상 노드와 연결
    for(int i=1; i<=n; i++){
        int w;
        cin >> w;
        pq.push(Edge{0, i, w});
    }

    //노드끼리 연결
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int w;
            cin >> w;
            if(i==j) continue;
            pq.push(Edge{i, j, w});
        }
    }
    
    int cnt=1;
    int ret=0;
    while(cnt <= n){
        Edge now = pq.top(); 
        pq.pop();

        if(find(now.s) != find(now.e)){
            //연결
            //cout << "현재 now.s : " << now.s << "현재 now.e : " << now.e << "현재 now.w : " << now.w << "\n"; 
            uni(now.s, now.e);
            ret+= now.w;
            cnt++;
        }
    }

    /*
    for(int i=0; i<=n; i++){
        cout << parent[i] << " ";
    }*/

    cout << ret << "\n";

    return 0;
}