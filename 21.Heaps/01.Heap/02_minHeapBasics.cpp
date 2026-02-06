#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int> >q;
    q.push(10);
    q.push(12);
    q.push(8);
    q.push(15);
    q.push(-1);
    q.push(2);

    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
}
