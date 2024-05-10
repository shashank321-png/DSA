// Check key is present in string or not

#include<bits/stdc++.h>
using namespace std;

bool checkKey(string s,int n,int i,char ch){
    if(i>=n){
        return false;
    }
    if(s[i]==ch){
        return true;
    }
    bool ans=checkKey(s,n,i+1,ch);
    return ans;
}
int main(){
    string s="shashankbajpai";
    int n=s.length();
    char ch='z';
    int i=0;
    bool ans=checkKey(s,n,i,ch);
    cout<<"Answer: "<<ans<<endl;

}