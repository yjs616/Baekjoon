#include <bits/stdc++.h>
using namespace std;
int n, a, b, sn, snb, cnt=0, newNum=0, fixNum=0;

int main(){
	
	cin >> n;
	fixNum =n;
	do{
		a = n/10;
		b = n%10;
		
		sn = a+b;   //1
		snb = sn%10;
		newNum = b*10 + snb; //2
		
		cnt++;
		n= newNum;
	
	}while(fixNum != newNum);
	
	cout << cnt;
	
	return 0;
}