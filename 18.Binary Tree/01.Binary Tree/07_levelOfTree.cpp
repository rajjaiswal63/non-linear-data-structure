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
void display(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    display(root->leftnode);
    display(root->rightnode);
}
int level(Node* root){
    if(root==NULL) return 0;
    int llevel=level(root->leftnode);
    int rlevel=level(root->rightnode);
    return 1+max(llevel,rlevel);
}
int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    Node* h=new Node(8);

    a->leftnode=b;
    a->rightnode=c;
    b->leftnode=d;
    b->rightnode=e;
    c->leftnode=f;
    c->rightnode=g;
    e->rightnode=h;
    display(a);
    cout<<endl;
    cout<<"level= "<<level(a);
}