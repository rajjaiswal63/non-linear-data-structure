#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>m;
    m["raj"]=01;
    m["rajnish"]=02;
    m["raja"]=03;
    m["rajklj"]=04;
    cout<<m.size()<<endl;
    for(auto s : m) cout<<s.first<<" "<<s.second<<endl;
    if(m.find("rajaaaa")!=m.end()) cout<<"exits"<<endl;
    else cout<<"not exist"<<endl;
    m.erase("raj");
    for(auto p : m) cout<<p.first<<" "<<p.second<<endl;
    

}