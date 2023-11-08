#include <bits/stdc++.h>
using namespace std;

int n, m, y, x, ny, nx, visited[103][103];
char adj[103][103];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

//최단경로 문제-> bfs 이용 

int main(){
	
	cin >> n >> m;
	
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> adj[i][j];
		}
	}
	
	queue<pair<int, int>> q;
	visited[1][1] = 1;
	q.push({1,1});
	
	while(q.size()){
		tie(y, x) = q.front(); q.pop();
		
		for(int i=0; i<4; i++){
			ny = y + dy[i];
			nx = x + dx[i];
			
			if(ny <= 0 || nx <=0 || ny>n || nx>m || adj[ny][nx]=='0')continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] +1;
			q.push({ny, nx});
		}
	}
	
	cout << visited[n][m] << "\n";
	
	
	return 0;
} 