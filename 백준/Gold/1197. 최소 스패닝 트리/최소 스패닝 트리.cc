#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int v, e, parent[10003];

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
    else parent[bRoot] = aRoot;

}

int main(){

    cin >> v >> e;

    //parent 초기화
    for(int i=1; i<=v; i++){
        parent[i]=i;
    }

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    for(int i=0; i <e; i++){
        int s, e, w;
        cin >> s >> e >> w;

        pq.push(Edge{s,e,w});
    }

    int std=1;
    int ret=0;

    while(std <= v-1){
        Edge now = pq.top();
        pq.pop();

        if(find(now.s) != find(now.e)){
            ret += now.w;
            uni(now.s, now.e);
            std++;
        }
    }

    /*
    for(int i=1; i<= v; i++){
        cout << parent[i] << " ";
    }*/
    

    cout << ret << "\n";


    return 0;
}