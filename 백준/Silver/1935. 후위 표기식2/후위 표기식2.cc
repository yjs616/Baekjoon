#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;          // 피연산자 개수
    string postfix; // 후위 표기식

    vector<int> operand(26); // 입력한 피연산자
    stack<double> st;

    cin >> N >> postfix;

    for (int i = 0; i < N; i++)
    {
        cin >> operand[i];
    }

    // 후위표기식의 길이 만큼 반복
    for (int i = 0; i < postfix.length(); i++)
    {
        // 피연산자인 경우
        if (postfix[i] >= 'A' && postfix[i] <= 'Z')
        {
            st.push(operand[postfix[i] - 'A']);
        }
        else // 연산자인 경우
        {
            if (!st.empty())
            {
                double temp = st.top();
                st.pop();
                switch (postfix[i])
                {
                case '+':
                    temp = st.top() + temp;
                    break;
                case '-':
                    temp = st.top() - temp;
                    break;
                case '*':
                    temp = st.top() * temp;
                    break;
                case '/':
                    temp = st.top() / temp;
                    break;
                }
                st.pop();
                st.push(temp); // 계산한 결과 push
            }
        }
    }
    // 소수점 둘째 자리까지 출력
    cout << fixed;
    cout.precision(2);
    cout << st.top() << '\n';
}
