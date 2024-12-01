#include <iostream>
using namespace std;

int n;
char arr[70][70];

int check(int y, int x, int n){
    for(int i=y; i< y+n; i++){
        for(int j=x; j< x+n; j++){
            if(arr[i][j] != arr[y][x]){
                return 0;
            }
        }
    }
    return 1;
}

void solve(int y, int x, int z){
    if(check(y, x, z)){    //다 0 or 1인지 확인
        cout << arr[y][x];   //1 or 0 출력
        return;
    }

    //같은 숫자가 아니라면
    int n = z/2;       //8->4->2
    cout << "(";
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            solve(y + i*n, x+ j*n, n);
        }
    }
    cout << ")";
}

int main(){

    cin >> n;

    //입력 받기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    solve(0, 0, n);

    return 0;
}