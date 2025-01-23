#include <iostream>
using namespace std;

int n, m, arr[10];

void go(int start, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) {
        arr[cnt] = i;
        go(i, cnt + 1);  // 현재 선택한 숫자 i부터 시작 (중복 허용)
    }
}

int main() {
    cin >> n >> m;
    go(1, 0);
    return 0;
}
