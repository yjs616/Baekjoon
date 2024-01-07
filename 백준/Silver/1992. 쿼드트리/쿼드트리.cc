#include <iostream>
#include <string.h>
using namespace std;

char map[67][67];
int n;

string go(int size, int y, int x) {
	if (size == 1) return string(1, map[y][x]);
	char std = map[y][x];   //기준
	string ret = "";        //결과 출력

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (std != map[i][j]) {
				ret += '(';
				ret += go(size / 2, y, x);    //왼쪽 위
				ret += go(size / 2, y, x + size/2);  //오른쪽 위
				ret += go(size / 2, y + size/2, x);   //왼쪽 아래
				ret += go(size / 2, y + size/2, x + size/2); //오른쪽 아래
				ret += ')';
				return ret;
			}
		}
	}
	return string(1, map[y][x]);       //map[y][x]가 char형이라서 반환형이 string이니까 string으로 만들어줘 return 
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cout << go(n, 0, 0);
	
	

	return 0;
}