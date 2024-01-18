#include <iostream>
#include <string.h>
using namespace std;

int h, w, visited[103][103],nx;
char arr[103][103];


int main(){

    cin >> h >> w;

    memset(visited, -1, sizeof(visited));   //visited -1로 초기화

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> arr[i][j];

            if(arr[i][j]=='c') visited[i][j]=0;

        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){ //행
            if(arr[i][j]=='c'){
                while(true){
                    nx = j+1;
                    if(nx > w || arr[i][nx]=='c') break;
                    visited[i][nx] = visited[i][j]+1;
                    j++;
                }
            }
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}