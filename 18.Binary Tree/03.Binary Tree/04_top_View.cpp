#include<iostream>
#include<queue>
#include<climits>
#include <algorithm>
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
void pre2(Node* root, int sl, int cl){
    if(root==NULL) return;
    if (sl==cl) cout<<root->val<<" ";
    pre2(root->leftnode,sl+1,cl);
    pre2(root->rightnode,sl+1,cl);
}
//bft just by root--
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

// top view
//no. of horizontal level------
void horizontalLevel(Node* root, int &minlev, int &maxlev, int level){
    if(root==NULL) return;
    minlev=min(minlev,level);
    maxlev=max(maxlev,level);
    horizontalLevel(root->leftnode,minlev,maxlev,level-1);
    horizontalLevel(root->rightnode,minlev,maxlev,level+1);
}
// top view
void topview(vector<int>&top, Node* root, int levelidx){
    if(root==NULL) return;
    if(top[levelidx]==INT_MIN) top[levelidx]=root->val;
    topview(top,root->leftnode,levelidx-1);
    topview(top,root->rightnode,levelidx+1);
}
// void topleft(Node* root , vector<int>&v){
//     if(root==NULL) return;
//     v.push_back(root->val);
//     topleft(root->leftnode,v);
// }
// void topright(Node* root, vector<int>&v){
//     if(root==NULL) return;
//     v.push_back(root->val);
//     topright(root->rightnode,v);
// }
// void topview(Node* root, vector<int>&ans){
//     vector<int>vforleft;
//     topleft(root,vforleft);
//      vector<int>vforright;
//     topright(root->rightnode,vforright);
//     reverse(vforleft.begin(),vforleft.end());
    
//     for(int i=0; i<vforleft.size(); i++){
//         ans.push_back(vforleft[i]);
//     }
//     for(int i=0; i<vforright.size(); i++){
//         ans.push_back(vforright[i]);
//     }

// }
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,9,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,INT_MIN,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root=consbt(arr,n);
    // bft(root);

    // // top view
    // vector<int>ans;
    // topview(root,ans);
    //   for(int x:ans) cout<<x<<" ";
    int minlev=0,maxlev=0;
    int horizontalLev=0;
    horizontalLevel(root,minlev,maxlev,0);
    cout<<minlev<<" "<<maxlev<<endl;
    horizontalLev= maxlev - minlev +1;
    cout<<"no. of horizontal levels : "<<horizontalLev<<endl;

    vector<int>top(horizontalLev,INT_MIN);
    topview(top,root,-minlev);
    for(int x:top) cout<<x<<" ";
}