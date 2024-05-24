#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

//메시지 n개로 이루어진 수열, 모두 C보다 작음
//자주 등장하는 빈도순대로 정렬
//자주 등장하는 것이 더 앞에 나와야 하고,
//횟수가 같다면 먼저 나온 것이 앞에   (VV)

int N, C;
map<int, int> mp;     //1순위 : counting
map<int, int> mp_first;  //2순위 : index
vector<pair<int, int>> v;

bool cmp(pair<int, int>a, pair<int, int> b){
    if(a.first == b.first){
        return mp_first[a.second] < mp_first[b.second];
    }
    return a.first > b.first;
}

int main(){
    cin >> N >> C;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        mp[a]++;   //counting

        if(mp_first[a]==0) mp_first[a] = i+1;  //index 저장
    }

    for(auto it : mp){
        v.push_back({it.second, it.first});   //it.second : 1순위(빈도수), it.first : 2순위(인덱스)
    }

    sort(v.begin(), v.end(), cmp);

    for(auto i : v){
        for(int j=0; j<i.first; j++){
            cout << i.second << " ";
        }
    }


    return 0;
}