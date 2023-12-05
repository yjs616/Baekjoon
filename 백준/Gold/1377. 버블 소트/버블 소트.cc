#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//몇 번만에 정렬 되는지?!
int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<pair<int, int>> v(N + 1);
    int n;

    for (int i = 1; i <= N; i++) {
        cin >> n;
        v[i] = { n, i };
    }

    sort(v.begin(), v.end());

    int answer = 0;
    for (int i = 1; i <= N; i++) { //인덱스 차이
        answer = max(answer, v[i].second - i);
    }

    cout << answer + 1;

    return 0;
}
