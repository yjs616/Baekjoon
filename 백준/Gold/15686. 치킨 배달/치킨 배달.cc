#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m, map[53][53], result = 987654321;    //m은 폐업시킬 치킨집의 갯수
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<vector<int>> chickenList;

void combi(int start, vector<int> v){
    if(v.size()==m){
        chickenList.push_back(v);     //전체 담을꺼
        return;
    }
    for(int i =start+1; i <chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;

}

int main(){

    cin >> n >> m;

    //맵 정보 넣기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];

            if(map[i][j]==1) home.push_back({i, j});
            if(map[i][j]==2) chicken.push_back({i, j});
        }
    }

    vector<int> v;   //3개 담을꺼
    combi(-1, v);

    for(vector<int> cList :  chickenList){
        int ret=0;
        for(pair<int, int> hm : home){
            
            int tmp = 987654321;
            for(int c : cList){
                int distance = abs(hm.first - chicken[c].first) + abs(hm.second - chicken[c].second);
                tmp = min(tmp, distance);
            }
            ret += tmp;
        }
        //전체
        result = min(result, ret);
    }

    cout << result << "\n";

    return 0;
}