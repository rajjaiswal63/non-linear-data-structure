#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int>s; // initialition of set

    s.insert(1); // insert in set
    s.insert(2);
    s.insert(3);
    s.insert(4);

    s.insert(1);  // not insert in set because duplicate
    s.insert(2);
    s.insert(3);
    s.insert(4);

    cout<<s.size()<<endl; // size of the set

    for(int ele : s){// for traversing all elements in set
        cout<<ele<<" ";
    }
    cout<<endl;

    s.erase(2); // for easing 2 from the set

     cout<<s.size()<<endl; 
    for(int ele : s){
        cout<<ele<<" ";
    }
    cout<<endl;

    int target = 3;
    if(s.find(target)!=s.end()) cout<<"exits"<<endl;

}