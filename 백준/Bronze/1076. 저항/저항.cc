#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s1, s2, s3;
int v, mul;
ll total;

void value(string s){
	if(s == "black"){
		v=0; mul=1;
	}else if(s== "brown"){
		v=1; mul=10;
	}else if( s=="red"){
		v=2; mul=100;
	}else if( s== "orange"){
		v=3; mul= 1000;
	}else if( s== "yellow"){
		v=4; mul= 10000;
	}else if(s== "green"){
		v=5; mul= 100000;
	}else if(s== "blue"){
		v=6; mul= 1000000;
	}else if(s== "violet"){
		v=7; mul= 10000000;
	}else if(s== "grey"){
		v=8; mul= 100000000;
	}else if(s=="white"){
		v=9; mul= 1000000000;
	}
}

int main(){
	cin >> s1 >> s2 >> s3;
	value(s1);
	total = v;
	value(s2);
	total= total*10 + v;
	value(s3);
	total *= mul;
		
	cout << total;
		
	return 0;
} 