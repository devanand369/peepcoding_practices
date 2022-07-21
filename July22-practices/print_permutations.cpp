#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    if (str==""){
        cout<<asf<<endl;
        return;
    }
    for (int i=0; i<str.length(); i++){
        string ros = str.substr(0, i) + str.substr(i+1);
        cout<<"Remaining of string : " <<ros<<endl;
        char ch = str[i];
        cout<<"String added to asf : "<< ch<<endl;
        printPermutations(ros, asf + ch);
    }
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}