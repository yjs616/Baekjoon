#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n,c;
map<int, int> mp;      //1순위 : counting
map<int, int> mp_first;   //2순위 : index
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return mp_first[a.second] < mp_first[b.second];
    }
    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> n >> c;

    int num;
    int std = 0;
    for(int i=0; i<n; i++){
        cin >> num;
        mp[num]++;     //counting

        if(mp_first[num]==0) mp_first[num] = i+1;   //index
    }

    for(auto it : mp){
        v.push_back({it.second, it.first});   //it.second : 1순위, it.firts : 2순위
    }

    sort(v.begin(), v.end(), cmp);

    for(auto i : v){
        for(int j=0; j< i.first; j++){
            cout << i.second << " ";
        }
    }
    return 0;
}