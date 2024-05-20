#include <iostream>
#include <map>
using namespace std;

int n, m, a, cnt;
map<int, int> mp;

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> a;
        mp[a]++;
    }

    for(auto it : mp){
        int comp = m- it.first;

        if(mp.find(comp)!= mp.end() && it.first < comp){
            cnt++;
        }
    }

    cout << cnt << "\n";


    return 0;
}