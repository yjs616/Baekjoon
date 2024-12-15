#include <iostream>
using namespace std;

int n;
char m[6563][6563];

//cout으로 바로 별을 찍는게 아니라 맵을 만들어서 넣어야될 것 같다.

void draw(int y, int x, int n){
    for(int i=y; i< y+n; i++){
        for(int j=x; j< x+n; j++){
            if(i==y+1 && j==x+1){
                m[i][j]=' ';
                continue;
            }
            m[i][j]='*';
        }
    }
}

//나누는 역할
void solve(int y, int x, int z){
    
    if(z==3){  //길이가 3일 때 멈춤
        draw(y, x, z);
        return;
    }

    int n = z/3;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==1 && j==1){
                continue;
            }
            solve(y + n*i, x+ n*j, n);
        }
    }

    //return;
}

int main(){
    cin >> n;

    //0로 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            m[i][j]='0';
        }
    }

    solve(0, 0, n);

    //배열로 저장하고 한번에 다 출력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(m[i][j]=='0'){
                m[i][j]=' ';    //0인건 빈 배열로 재정의
            }
            cout << m[i][j];
        }
        cout << "\n";
    }

    return 0;


}