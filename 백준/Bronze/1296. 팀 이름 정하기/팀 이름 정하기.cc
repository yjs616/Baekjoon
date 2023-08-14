#include <bits/stdc++.h>
using namespace std;
int num;
string green, teamName;
vector<string> test,team;
vector<int> prob;


struct CompareTeams{
	bool operator()(const pair<int, string>& a, const pair<int, string>& b){
		if(a.first != b.first){
			return a.first < b.first;   // prob 오름차순 정렬
		}
		return a.second > b.second;     // team 내림차순 정렬
	}
};

int main(){
	cin >> green >> num;
			
	test.push_back(green);
	
	for(int i=0; i<num; i++){
		int ret =1;
		int cnt[4]={0,0,0,0};
		
		cin >> teamName;
		team.push_back(teamName);
		test.push_back(teamName); 
		
		for(int i=0; i<test.size(); i++){
		    for(int j=0; j<test[i].size(); j++){
			    if(test[i][j]=='L'){
				    cnt[0]++;
			    }else if(test[i][j]=='O'){
				    cnt[1]++;
			    }else if(test[i][j]=='V'){
				    cnt[2]++;
			    }else if(test[i][j]=='E'){
				    cnt[3]++;
			    }
		    }
	    }
	    
	    for(int i=0; i<4; i++){
		    for(int j=i+1; j<4; j++){
			    ret *= cnt[i]+cnt[j];
		    }
	    }
		
		prob.push_back(ret%100); 
		test.pop_back();    //팀 후보명 계산한거 빼기 
	}
	
    // pair<우승 확률, 팀 이름>을 저장하는 우선순위 큐
    priority_queue<pair<int, string>, vector<pair<int, string>>, CompareTeams> pq;
    
    for(int i=0; i<num; i++){
    	pq.push({prob[i], team[i]});
	}	
	cout << pq.top().second << "\n";
				
	return 0;
}