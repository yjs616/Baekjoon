#include <iostream>
#include <queue>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        pq.push(num);
    }

    int ret = 0;  //비교 횟수(최소화되어야 하는 대상임)

    while(pq.size() >= 2){ //2개 이상은 있어야됨
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int sum = first + second;
        ret += sum;
        //cout << "ret : " << ret << "\n";
        pq.push(sum);
    }

    cout << ret;

    return 0;
}