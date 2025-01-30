#include <iostream>
#include <queue>
using namespace std;

int n;

//자연수 : 자연수 넣기
//0 : 가장 큰 값 출력하고 제거

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    priority_queue<int, vector<int>, less<int>> pq;

    for(int i=0; i<n; i++){
        int num;
        cin  >> num;
        
        if(num == 0){
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }
            else cout << 0 << "\n";
        }else{
            //숫자라면
            pq.push(num);
        }


    }

    return 0;
}