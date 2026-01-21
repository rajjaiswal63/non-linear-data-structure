#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* leftnode;
    Node* rightnode;
    Node(int val){
        this->val=val;
        this->leftnode=NULL;
        this->rightnode=NULL;
    }
};
// mene kiya ye ye bhi sahi hai bhai
void pre(Node* root, int n){
    if(root==NULL) return;
    if (n==1) cout<<root->val<<" ";
    pre(root->leftnode,n-1);
    pre(root->rightnode,n-1);
}
// or ye sir me bataya hai method
void pre2(Node* root, int sl, int cl){
    if(root==NULL) return;
    if (sl==cl) cout<<root->val<<" ";
    pre2(root->leftnode,sl+1,cl);
    pre2(root->rightnode,sl+1,cl);
}
int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);

    a->leftnode=b;
    a->rightnode=c;
    b->leftnode=d;
    b->rightnode=e;
    c->leftnode=f;
    c->rightnode=g;
    pre(a,3);
    cout<<endl;
    pre2(a,1,3);
    
}