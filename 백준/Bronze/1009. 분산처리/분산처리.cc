#include <bits/stdc++.h>
using namespace std;

int a, b, t, cn;

int main(){
   cin >> t;
   for(int i=0; i<t; i++){
      cn =1;
      cin >> a >> b;
      for(int j=0; j<b; j++){
         cn = (cn*a) % 10; 
      }
      if(cn ==0){
         cout << 10 << "\n";
      }else{
         cout << cn << "\n";
      }      
         
   }   
   return 0;
}