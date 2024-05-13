#include <iostream>
using namespace std;

int times[3], sum;

int main(){

    for(int i=0; i<3; i++){
        cin >> times[i];
    }

    pair<int, int> p[3];
    for(int i=0; i<3; i++){
        cin >> p[i].first >> p[i].second;
    }

    //시간 돌리면서 주차요금 합 구하기
    for(int i=1; i<=100; i++){
        int cnt=0;

        if(p[0].first < i && p[0].second >=i) cnt++;
        if(p[1].first < i && p[1].second>=i) cnt++;
        if(p[2].first < i && p[2].second>=i) cnt++;

        sum += cnt*times[cnt-1];

    }


    cout << sum <<"\n";

    return 0;
}