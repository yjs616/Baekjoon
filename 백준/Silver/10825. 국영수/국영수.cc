#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//국어 점수 낮은 순

struct Student{
    string name;
    int kor;
    int mat;
    int eng;
};

vector<Student> student_info;

int n;

bool sort_operator(Student &a, Student &b){

    
    if(a.kor != b.kor){
        return a.kor > b.kor;
    }else if(a.eng != b.eng){
        return a.eng < b.eng;
    }else if(a.mat != b.mat){
        return a.mat > b.mat;
    }else{
        return a.name < b.name;
    }

    /*
    if(a.kor == b.kor){
        return a.eng < b.eng;        
    }else if(a.kor == b.kor && a.eng == b.eng){
        return a.mat > b.mat;
    }else if(a.kor == b.kor && a.eng == b.eng && a.mat == b.mat){
        return a.name < b.name;
    }

    return a.kor > b.kor;
    */
}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        string name; int kor, mat, eng;
        cin >> name >> kor >> mat >> eng;
        student_info.push_back({name, kor, eng, mat});
    }

    sort(student_info.begin(), student_info.end(), sort_operator);

    for(auto it : student_info){
        cout << it.name << "\n";
    }

    return 0;
}