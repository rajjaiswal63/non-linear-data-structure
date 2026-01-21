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
void pre2(Node* root, int sl, int cl){
    if(root==NULL) return;
    if (sl==cl) cout<<root->val<<" ";
    pre2(root->rightnode,sl+1,cl);
    pre2(root->leftnode,sl+1,cl);
}
int level(Node* root){
    if(root==NULL) return 0;
    return 1+ max(level(root->leftnode),level(root->rightnode));
}
void bft(Node* root){
    int n=level(root);
    for(int i=1; i<=n; i++){
        pre2(root,1,i);
        cout<<endl;
    }
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

    bft(a);
}