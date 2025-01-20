#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long arr[10003];
long long l, r = 0;
long long ret;

bool check(long long m) {
    long long cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += arr[i] / m;
    }
    return cnt >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        r = max(r, arr[i]);
    }

    l = 1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            ret = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ret << "\n";
    return 0;
}
