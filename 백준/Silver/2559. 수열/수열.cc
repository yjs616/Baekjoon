#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> tem(n);
    for (int i = 0; i < n; i++) {
        cin >> tem[i];
    }

    int maxSum = 0;
    int curSum = 0;
    
    for (int i = 0; i < k; i++) {
        curSum += tem[i];
    }
    maxSum = curSum;

    for (int i = k; i < n; i++) {
        curSum = curSum + tem[i] - tem[i - k];
        maxSum = max(maxSum, curSum);
    }

    cout << maxSum;

    return 0;
}