#include <iostream>
#include <vector>
using namespace std;

int n, s, sum=987654321, ret=0;
vector<int> v;
int arr[21];

/*void print(){
    for(int i : v){
        cout << i << " ";
    }
    cout << "\n";
}*/

void select(int idx){
    if(sum == s){
        ret++;
        //print();
        //return; //0이 더해질 수도 있으니까 리턴하면 안됨
    }
    if(idx == n-1) return;

    for(int i= idx+1; i<n; i++){
        sum += arr[i];
        //v.push_back(arr[i]);
        select(i);

        //끝나면
        sum-=arr[i];
        //v.pop_back();
    }
}

int main(){

    cin >> n >> s;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        sum = arr[i];
        //v.push_back(arr[i]);
        select(i);
        //v.pop_back();
        
    }

    cout << ret << "\n";

    return 0;
}