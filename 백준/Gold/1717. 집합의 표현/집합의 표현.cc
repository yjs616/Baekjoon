#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n, m, parent[1000003];

int find(int a){
    if(parent[a]==a) return a;           //부모 찾으면 리턴
    else{
        return parent[a] = find(parent[a]);     //거슬러올라가면서 부모 찾기
    }
}

void uni(int a, int b){
    int aRoot = find(a);
    int bRoot = find(b);

    if(aRoot == bRoot) return;
    else{
        parent[aRoot] = bRoot;     //한쪽에서 합치기
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    //parent 초기화
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        //합치기
        if(a==0){
            uni(b, c);
        }else if(a==1){
            if(find(b)== find(c)) cout << "yes" << "\n";
            else cout << "no" << "\n";
        }
    }

    return 0;
}