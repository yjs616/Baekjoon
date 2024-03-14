#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int n;
int mp, mf, mc, mv;

//결과 변수
int ret = INF;
map<int, vector<vector<int>>> ret_v;    //합, 포함된 재료들

struct A{
    int p, f, c, v, cost;
}a[16];

int main(){

    cin >> n;
    cin >> mp >> mf >> mc >> mv;  //기준 영양소들

    //영양소들 넣기
    for(int i=0; i<n; i++){
        cin >> a[i].p >> a[i].f >> a[i].c >> a[i].v >> a[i].cost;
    }

    //모든 경우의 수 보기
    for(int i=1; i < (1<< n); i++){
        int sp=0, sf=0, sc=0, sv=0, scost=0;
        vector<int> v;
        //재료 포함 여부
        for(int j=0; j<n; j++){
            if(i & (1 << j)){
                //해당 영양소에 대해
                sp += a[j].p;
                sf += a[j].f;
                sc += a[j].c;
                sv += a[j].v;
                scost += a[j].cost;

                v.push_back(j+1);      //선택된 재료 인덱스 넣어줌
            }
        }

        //기준치 넘었는지 체크
        if(sp >= mp && sf >= mf && sc >= mc && sv >= mv){
            //넘었으면 결과 배열과, 결과 합 값 넣기
            if(ret >= scost){
                ret = scost;
                ret_v[ret].push_back(v);

            }

        }
    }

    if(ret == INF){
        cout << -1 << "\n";
    }else{
        sort(ret_v[ret].begin(), ret_v[ret].end());
        cout << ret << "\n";
        for(auto a : ret_v[ret][0]){
            cout << a << " ";
        }
    }


    return 0;
}

