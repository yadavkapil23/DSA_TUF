#include<iostream>
using namespace std;
void printsequences(string input , string output,int index){
    if(index == input.size()){
        cout<<output<<endl;
        return;
    }
    
    output.push_back(input[index]);
    printsequences(input,output + input[index],index+1); //considering the sequence

    output.pop_back();
    printsequences(input,output,index+1);
}
int main(){
    string s = "Kapil";
    printsequences(s,"",0);
    return 0;
}