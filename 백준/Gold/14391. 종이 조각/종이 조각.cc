#include <iostream>
#include <algorithm>
using namespace std;

//종이를 자르는데, 가로 혹은 세로가 1이여야 함
//각 조각 숫자 합 최대가 되도록

int n, m, ret=0;
int arr[6][6];

int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &arr[i][j]);   //int 1자리만 입력받기?
        }
    }


    //0:가로 
    //1:세로
    //전체 경우의 수 : 2의 (n*m)승
    for(int s = 0; s < (1 << (n*m)); s++){    //0,1로 된 전체 경우
        int sum = 0;
        //가로로 0들만 모두 더함
        for(int i=0; i<n; i++){
            int cur = 0;
            for(int j=0; j<m; j++){
                int k = i*m + j;
                if((s & (1 << k)) == 0){     //k번째 자리가 0인지
                    cur = cur*10 + arr[i][j];

                }else{ //k번째 자리가 1이면
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }


        //세로로 1들만 모두 더함
        for(int j=0; j<m; j++){
            int cur =0;
            for(int i=0; i<n; i++){
                int k = i*m + j;
                if((s & (1<<k)) != 0){    //==1이랑 !=0이랑 무슨 차이지
                    cur = cur*10 + arr[i][j];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }



        //합 최대 비교
        ret = max(ret, sum);

    }

    cout << ret;


    return 0;
}

//괄호로 우선순위를 잘 표시해야함