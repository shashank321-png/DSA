// Subsequence of string
#include<bits/stdc++.h>
using namespace std;

void printSubsequence(string str,string output,int i){
    if(i>=str.length()){
        cout<<output<<endl;
        return;
    }
    // exclude
    printSubsequence(str,output,i+1);

    //include
    output.push_back(str[i]);
    printSubsequence(str,output,i+1);
}
int main(){
    string str="abc";
    string output="";
    int i=0;
    printSubsequence(str,output,i);
}