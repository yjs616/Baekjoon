#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    unordered_map<string, int> nameToNum; // 포켓몬 이름을 번호로 매칭
    vector<string> numToName(n + 1); // 포켓몬 번호를 이름으로 매칭
    
    for (int i = 1; i <= n; i++) {
        string poketmon;
        cin >> poketmon;
        nameToNum[poketmon] = i;
        numToName[i] = poketmon;
    }
    
    for (int i = 0; i < m; i++) {
        string prob;
        cin >> prob;
        
        if (isdigit(prob[0])) { // 숫자가 주어진 경우
            int num = stoi(prob);
            cout << numToName[num] << "\n";
        } else { // 이름이 주어진 경우
            cout << nameToNum[prob] << "\n";
        }
    }
    
    return 0;
}
