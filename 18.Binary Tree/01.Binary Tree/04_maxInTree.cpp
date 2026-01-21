#include<iostream>
#include<climits>
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
int maxOfNode(Node* root){
    if(root==NULL) return INT_MIN;
    int lmax=maxOfNode(root->leftnode);
    int rmax=maxOfNode(root->rightnode);
    return max(root->val, max(lmax, rmax));
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
    display(a);
    cout<<endl;
    // size(a);
    // cout<<sum;
    cout<<"max number in tree "<<maxOfNode(a);
    cout<<endl;
}