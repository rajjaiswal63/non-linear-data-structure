#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int val;
    Node* leftnode;
    Node* rightnode;
    Node(int val){
        this->val=val;
        leftnode=NULL;
        rightnode=NULL;
    }

};
void pre(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    pre(root->leftnode);
    pre(root->rightnode);
}
int level(Node* root){
    if(root==NULL) return 0;
    return 1+ max(level(root->leftnode),level(root->rightnode));
}
void bfstrav(Node* root, int levelToPrint){
    int lev=level(root);
    int levToTrav=0;
    queue<Node*>q;
    q.push(root);
    levToTrav++;
    while(q.size()>0){
        Node* temp=q.front();
        cout<<temp->val<<" ";
        q.pop();

        if(temp->leftnode!=NULL) {
            q.push(temp->leftnode);
            levelToPrint++;
        }
        if(temp->rightnode!=NULL) q.push(temp->rightnode);
        

    }
}
void bfs(Node* root, int levelToPrint, int startingLevel){
    if(root==NULL) return;
    if(startingLevel==levelToPrint){
        cout<<root->val<<" ";
        return;
    }
   
    bfs(root->rightnode,levelToPrint,startingLevel+1);       
     bfs(root->leftnode,levelToPrint,startingLevel+1);
}
void bfsTree(Node* root){
    int lev=level(root);
    for (int i = 1; i <= lev; i++)
    {
        bfs(root,i,1);
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

    pre(a);
    cout<<endl;
    // cout<<level(a);
    // cout<<endl;
    // bfs(a,3,1);

    // bfsTree(a);
    bfstrav(a,2);

}