#include<iostream>
#include<queue>
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
Node* consbt(int arr[], int n){
    queue<Node*>q;
    Node* root=new Node(arr[0]);
    q.push(root);
    int i=1, j=2;
    while(q.size()>0 && i<n){
        Node* temp=q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT_MIN) l=new Node(arr[i]);
        else l=NULL;
        if(j!=n && arr[j]!=INT_MIN) r=new Node(arr[j]);
        else r=NULL;

        temp->leftnode=l;
        temp->rightnode=r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i+=2;
        j+=2;
    }
    return root;
}

void bfstrav(Node* root){
    queue<Node*>q;
    q.push(root);
    while(q.size()>0){
        Node* temp=q.front();
        cout<<temp->val<<" ";
        q.pop();

        if(temp->leftnode!=NULL) q.push(temp->leftnode);
        if(temp->rightnode!=NULL) q.push(temp->rightnode);
    }
}
void leftboundry(Node* root){
    if(root==NULL) return;
    cout<<root->val;
    if(root->leftnode==NULL) leftboundry(root->rightnode);
    else leftboundry(root->leftnode);
     if(root->leftnode==NULL && root->rightnode) leftboundry(root->rightnode);
   
}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root=consbt(arr,n);
    bfstrav(root);
    leftboundry(root);
}