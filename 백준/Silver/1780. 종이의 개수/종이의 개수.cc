#include <iostream>
#include <math.h>
using namespace std;

//종이 모두 같은 수 : 그대로 사용
//다른 수 : 종이 9등분
//출력 : -1로만, 0으로만, 1로만 채워진 종이 개수

int pos;
int n, arr[2190][2190];
int cnt[3]; //-1, 0, 1

int check(int y, int x, int n){
    for(int i=y; i< y+n; i++){
        for(int j=x; j< x+n; j++){
            if(arr[i][j] != arr[y][x]) return 0;
        }
    }
    return 1;
}

void solve(int y, int x, int z){
    if(check(y, x, z)){ //정사각형 안에 숫자 다 같은지 체크
        cnt[arr[y][x] + 1] +=1;
        return;
    }

    //정사각형 안에 숫자 다르다면 다시 분할 후 탐색
    int n = z/3;       //27->9->3->1
    for(int i=0; i<3; i++){      
        for(int j=0; j<3; j++){
            solve(y + (i*n), x + (j*n), n);   //총 9가지 경우의 수 나옴(나는 9개의 solve를 다 만들려고 했었다..)
        }
    }
}

int main(){
    cin >> n;

    //입력 받기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    //탐색(일반화 시켜서 생각하자)
    //1.종이가 다 같은 숫자인지 확인해
    //2.다르면 9등분해
    //3.그러면 탐색할 시작 인덱스를 잡아
    //시작 인덱스를 기준으로 다시 탐색해
    //다 같은 숫자면 그 숫자 저장하고 종료해

    solve(0, 0, n);

    //-1, 0, 1 각 갯수 출력
    for(int i=0; i<3; i++){
        cout << cnt[i] << "\n";
    }
    return 0;
}

//시작 점과 끝 점을 잡는 것이 관건인 것 같다!!!!