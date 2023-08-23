#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int clothNum;
        cin >> clothNum;
        
        map<string, int> closet;

        for (int j = 0; j < clothNum; j++) {
            string clothName, clothType;
            cin >> clothName >> clothType;
            closet[clothType]++;
        }

        int sum = 1; // 모든 의상을 입지 않는 경우를 고려해서 1로 초기화

        for (auto it : closet) {
            sum *= (it.second + 1); // 각 의상 종류별로 선택 가능한 개수를 계산하여 곱해줌
        }
        
        cout << sum - 1 << "\n"; // 모든 의상을 입지 않는 경우를 고려한 값에서 1을 빼줌
    }

    return 0;
}
