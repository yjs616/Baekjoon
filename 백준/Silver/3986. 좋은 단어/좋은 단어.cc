#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        stack<char> st;
        bool goodWord = true;

        for (char c : word) {
            if (!st.empty() && st.top() == c) {
                st.pop(); // 같은 문자가 연속되면 pop
            } else {
                st.push(c);
            }
        }

        if (st.empty()) {
            cnt++; // 스택이 비어있다면 좋은 단어
        }
    }

    cout << cnt << "\n";

    return 0;
}
