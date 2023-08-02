#include <bits/stdc++.h>
using namespace std;

string convertToBinary(int num) {
    string binaryStr = "";

    while (num > 0) {
        int remainder = num % 2;
        binaryStr = to_string(remainder) + binaryStr;
        num /= 2;
    }

    return binaryStr;
}

int main() {
    string octalStr;
    cin >> octalStr;

    // 입력이 0인 경우 예외 처리
    if (octalStr == "0") {
        cout << 0;
    } else {
        string binaryStr = "";

        // 각 자리의 8진수 숫자를 2진수로 변환하여 이어붙임
        for (char digit : octalStr) {
            int num = digit - '0'; // char를 int로 변환
            string binaryDigit = convertToBinary(num);
            // 각 자리의 2진수를 3자리로 맞춰줌
            while (binaryDigit.size() < 3) {
                binaryDigit = "0" + binaryDigit;
            }
            binaryStr += binaryDigit;
        }

        // 첫 번째 자리가 0인 경우 0을 제외하고 출력
        int startIdx = 0;
        while (binaryStr[startIdx] == '0') {
            startIdx++;
        }
        cout << binaryStr.substr(startIdx);
    }

    return 0;
}
