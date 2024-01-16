#include <iostream>
using namespace std;

string s="";


int main(){

    while(true){
        cin >> s;

        if(s=="end"){
            break;
        }
        
        int arr[23],cnt=0;
        bool isAEIOU = false, isTree=false, samePre=false;
        char pre=' ';

        for(int i=0; i<s.size(); i++){
            if(pre != 'e' && pre != 'o' && pre == s[i]){
                samePre = true;
                break;
            }
            
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                arr[i]=1;
                isAEIOU = true;    //모음 반드시 1개 포함 (기준1)
            }
            else{
                arr[i] = 0;
            }

            //연속되는 모음/자음 갯수 세기 (기준2)  여기가 이상함
            if(i==0){
                cnt++;
            }else{
                if(arr[i-1] == arr[i]) cnt++;
                else{
                    cnt=0;
                    cnt++;
                }
                //cout << "현재 cnt는  : " << cnt << "\n";
            }

            //cnt 3 되면 2번 기준 불충족
            if(cnt ==3){
                isTree=true;
                break;
            }
            pre = s[i];

        }

        //cout << "isAEIOU :" << isAEIOU << "\n";
        //cout << "isTree : " << isTree << "\n";
        //cout << "samePre : " << samePre << "\n";

        if(!isAEIOU || isTree || samePre){ //승인 불가
            cout << "<" << s << ">" << " is not acceptable.\n";
        }else{
            cout << "<" << s << ">" << " is acceptable.\n";
        }

    }
    
    return 0;
}