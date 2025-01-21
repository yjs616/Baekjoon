#include <iostream>
using namespace std;

int n, m;
int arr[10];  // 1부터 N까지의 숫자를 저장할 배열
bool visited[10];  // 방문 여부를 확인할 배열

void solve(int start, int cnt) {
    if (cnt == m) {
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
        return;
    }

    // start부터 n까지 숫자 선택 (오름차순 조합)
    for (int i = start; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;  // 선택
            solve(i + 1, cnt + 1);  // 다음 숫자 선택 (중복 방지)
            visited[i] = false;  // 선택 해제 (백트래킹)
        }
    }
}

int main() {
    cin >> n >> m;

    // 1부터 N까지의 자연수 채우기
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    // 백트래킹 시작
    solve(1, 0);

    return 0;
}
