#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, max_cnt_words, fill_cnt;
//int alphabet[30];
int alphabet;
vector<int> words;
//숫자 대 숫자로 숫자끼리 비교

//알파벳 26개

int can_read_words(int cur){
    int cnt=0;
    for(int word : words){
        int tmp = word & cur;
        if(word && tmp == word) cnt++;
    }

    return cnt;
}


void learn_words(int idx, int added){  //idx : 탐색 시작할 알파벳 번호

    if(added == 0){
        int cur_cnt= can_read_words(alphabet);    //현재 학습된 단어 인자로 넘겨
        max_cnt_words = max(max_cnt_words, cur_cnt);
        return;
    }

    for(int i= idx; i<26; i++){
        if((alphabet & (1 << i)) ==0){  //연산자 우선순위 (괄호 주의)
            alphabet |= (1 << i);
            learn_words(i+1, added-1);
            alphabet ^= (1 << i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    words.resize(n);

    //단어 입력
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(char ch : str){
            words[i] |= (1 << ch-'a');    //단어를 숫자로 저장
        }
        
    }

    if(k < 5) cout << 0 << "\n";
    else{
        //a, n, t, i, c는 읽음으로 표시해야됨 (숫자로 표시)
        //alphabet['a'-'a'] = 1; alphabet['n'-'a']=1; alphabet['t'-'a']=1; alphabet['i'-'a']=1; alphabet['c'-'a']=1;
        alphabet |= (1 << 'a'-'a');
        alphabet |= (1 << 'n'-'a');
        alphabet |= (1 << 't'-'a');
        alphabet |= (1 << 'i'-'a');
        alphabet |= (1 << 'c'-'a');

        fill_cnt = k-5;

        learn_words(0, fill_cnt);


        cout << max_cnt_words << "\n";
    }


}