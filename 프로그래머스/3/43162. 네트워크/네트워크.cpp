#include <string>
#include <vector>

#define MAX 200+3
using namespace std;

bool isVisited[MAX];

void DFS(int cur, int n, vector<vector<int>> com){
    isVisited[cur] = true;
    
    for(int i = 0; i < n; i++){
        // 아직 방문하지 않았고, 연결되어 있는 컴퓨터 번호 일 때
        if(!isVisited[i] && com[cur][i] == 1){
            DFS(i, n, com);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){ // 0번부터 n-1까지
        if(!isVisited[i]){ // 아직 방문하지 않았다면 
            // DFS를 통해 연결되어 있는 컴퓨터들을 방문
            DFS(i, n, computers); 
            answer++; // 네트워크의 갯수 추가
        }
    }
    return answer;
}