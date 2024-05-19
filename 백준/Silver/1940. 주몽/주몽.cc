#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, m, cnt;
map<int, int> mp;
vector<int> keys;

int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        mp[a]++; 
        keys.push_back(a);
    }
    

    for(int key : keys){
        if(mp.find(key) != mp.end() && mp.find(m-key) != mp.end()){
            if(key != m-key || mp[key] >1){
                cnt++;
                mp.erase(key);
                mp.erase(m-key);
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}