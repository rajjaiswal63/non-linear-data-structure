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
void pre(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    pre(root->leftnode);
    pre(root->rightnode);
}
void in(Node* root){
    if(root==NULL) return;
    in(root->leftnode);
    cout<<root->val<<" ";
    in(root->rightnode);
}
void post(Node* root){
    if(root==NULL) return;
    post(root->leftnode);
    post(root->rightnode);
    cout<<root->val<<" ";
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
    pre(a);
    cout<<endl;
    in(a);
    cout<<endl;
    post(a);
}