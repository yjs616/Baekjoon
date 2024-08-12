#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int A, B, C;
set<vector<int>> visited;
vector<int> result;

void dfs(int a, int b, int c) {
    // 이미 방문한 상태라면 return
    if (visited.count({a, b, c})) return;
    
    // 현재 상태를 방문했다고 표시
    visited.insert({a, b, c});
    
    // A가 비어있을 때 C의 양을 결과에 추가
    if (a == 0) result.push_back(c);
    
    // 물을 옮기는 6가지 경우를 모두 고려
    // A -> B
    dfs(max(0, a - (B - b)), min(B, b + a), c);
    // A -> C
    dfs(max(0, a - (C - c)), b, min(C, c + a));
    // B -> A
    dfs(min(A, a + b), max(0, b - (A - a)), c);
    // B -> C
    dfs(a, max(0, b - (C - c)), min(C, c + b));
    // C -> A
    dfs(min(A, a + c), b, max(0, c - (A - a)));
    // C -> B
    dfs(a, min(B, b + c), max(0, c - (B - b)));
}

int main() {
    cin >> A >> B >> C;
    
    dfs(0, 0, C);
    
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    
    for (int x : result) {
        cout << x << " ";
    }
    
    return 0;
}