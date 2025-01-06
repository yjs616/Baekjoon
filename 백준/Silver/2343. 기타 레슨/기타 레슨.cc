#include <iostream>
using namespace std;

//강의 순서 유지하면서 블루레이 크기 최소화
//mid는 블루레이 크기다.
//블루레이 크기는 최소 가장 긴 강의 길이만큼은 되야 모든 강의를 담을 수 있다.
//블루레이 크기의 최대는 한 블루레이에 모든 강의를 담는 것이니, 합이다.

int n, m;  //n은 강의 수, m은 블루레이 갯수
int rec[100003];
int high, low;
int ret = 987654321;

bool isPos(int raysize){
    int cnt = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        if(sum + rec[i] > raysize){
            sum = 0;
            cnt++;
        }
        sum += rec[i];
    }
    if(sum != 0) cnt++;

    return cnt <= m;
}

int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> rec[i];
        high += rec[i];
        low = max(low, rec[i]);
    }

    while(low <= high){
        int mid = (low + high) /2;

        if(isPos(mid)){
            ret = min(ret, mid);   //블루레이 최소 찾기

            //블루레이 크기 더 줄여보자
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }


    cout << ret;


    return 0;
}