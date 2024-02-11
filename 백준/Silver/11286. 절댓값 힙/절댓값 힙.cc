#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int n, a;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a)== abs(b)){
            return a > b;
        }
        return abs(a) > abs(b);
    }

};

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    priority_queue<int, vector<int>, cmp> pq;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a;

        if(a ==0){
            if(!pq.size()) cout << "0" << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
            
        }else{
            pq.push(a);
        }
    }

    return 0;
}