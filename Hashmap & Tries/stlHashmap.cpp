// STL in Hashmap
#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<string,int> m;
    pair<string,int> p=make_pair("Scorpio",9);
    m.insert(p);
    pair<string,int> p2("Innova",8);
    m.insert(p2);
    m["Fortuner"]=10;

    //Acess
    cout<<m.at("Scorpio")<<endl;
    cout<<m["Fortuner"]<<endl;

    //Search
    cout<<m.count("alto")<<endl;
    if(m.find("Scorpio")!=m.end()){
        cout<<"Scorpio Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    cout<<m.size()<<endl;
    cout<<m["hammer"]<<endl;// Hammer not exist that's why it create new entry of hammer in map
    cout<<m.size()<<endl;

    for(auto i:m){
        cout<<i.first<<"->"<<i.second<<endl;
    }
}