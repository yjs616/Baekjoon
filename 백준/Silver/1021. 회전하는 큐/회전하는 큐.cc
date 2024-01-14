#include <iostream>
#include <deque>
using namespace std;

int n, m;
deque<int> dq;
int ret;

int main(){
    cin >> n >> m;
    
    //1부터 n까지 큐에 넣기
    for(int i=1; i<=n; i++){
        dq.push_back(i);
    }

    int num;
    int index;
    
    while (m>0){
        cin >> num;

        int scnt=0;
        int ecnt=0;

        //num에 해당하는 인덱스 찾기 + 왼쪽으로 이동했을 때의 cnt도 함께
        for(int i=0; i<dq.size(); i++){
            if(num == dq[i]){
                index = i;
                break;
            }else{
                scnt++;
            }
        }

        //오른쪽으로 이동해서 찾았을 때 cnt
        for(int i=dq.size()-1; i>0; i--){
            if(num==dq[i]) break;
            else ecnt++;
        }

        //왼쪽 이동이 빠른지 오른쪽 이동이 빠른지
        if(scnt <= ecnt){ //왼쪽으로 이동하기
            while(dq.front() != num){
                dq.push_back(dq.front());
                dq.pop_front();
                ret++;
            }
            dq.pop_front();   //뽑아내기
            
        }else{ //오른쪽으로 이동하기
            while(dq.front()!= num){
                dq.push_front(dq.back());
                dq.pop_back();
                ret++;
            }
            dq.pop_front();
        }
        m--;
    }
    
    cout << ret;

    return 0;
}