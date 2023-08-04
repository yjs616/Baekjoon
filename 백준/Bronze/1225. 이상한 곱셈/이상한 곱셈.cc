#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string num1, num2;
ll sum=0;
int main(){
	
	cin >> num1 >> num2;
	
	for(int i=0; i<num1.size(); i++){
		for(int j=0; j<num2.size(); j++){
			int mul1 = num1[i]-'0';
			int mul2 = num2[j]-'0';
			
			sum = sum + (mul1 * mul2);
		}
	}
	
	cout << sum;
	
	return 0;
}