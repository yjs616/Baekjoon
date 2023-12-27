#include <iostream>
#include <algorithm>
using namespace std;

// 두 단어가 서로 애너그램 관계에 있도록 하기 위해 제거해야 하는 최소 문자 수 출력
string a, b;

int main() {
    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            a.erase(i, 1);
            b.erase(j, 1);
        }
        else {
            if (a[i] < b[j]) i++;
            else j++;
        }
    }

    // 남은 문자 수를 더해서 출력
    cout << a.size() + b.size() << "\n";

    return 0;
}