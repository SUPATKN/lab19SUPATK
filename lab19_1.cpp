#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string file,vector<string> &name,vector<int> &score,vector<char> &grade){
    ifstream text(file.c_str());
    string line;
    char format[] = {"%[^:]: %d %d %d"};
    char Name[100];
    int a,b,c;
    while(getline(text,line)){
        sscanf(line.c_str(),format,Name,&a,&b,&c);
        name.push_back(Name);
        score.push_back(a+b+c);
        grade.push_back(score2grade(a+b+c));
    }
}

void getCommand(string com,string k){   
    cout << "Please input your command: ";
    string fuck;
    getline(cin,fuck);
    int start = 0;
    int end = fuck.find_first_of(" ");
    com = fuck.substr(start,end);
    start = end+1;
    k = fuck.substr(start);

}

void searchName(vector<string> &name,vector<int> &score,vector<char> &grade,string k){
    int p = name.size();
    for(int i = 0;i<p;i++){
        if(k==toUpperStr(name[i])){
            cout << name[i] << "'s" << "score  = " << score[i] << endl;
            cout << name[i] << "'s" << "grade  = " << grade[i] << endl;
        }else cout << "Cannot found.";
    }
}

void searchGrade(vector<string> &name,vector<int> &score,vector<char> &grade,string k){
    int p = name.size();
    for(int i = 0;i<p;i++){
        string y = ""+grade[i];
        if(k == y){
            cout << name[i] << " " << "(" << score[i] << ")"<< endl;
        }else cout << "Cannot found.";
    }
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
