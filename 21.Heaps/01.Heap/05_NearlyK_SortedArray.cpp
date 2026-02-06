#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int arr[]={10,9,8,7,4,70,60,50};
    vector<int>ans;
    int n=sizeof(arr)/4;
    int k=4;
    priority_queue<int, vector<int>, greater<int>>pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if(pq.size()>k) {
            ans.push_back(pq.top());
            pq.pop();
        }
    }
   while (pq.size()!=0)
   {
    ans.push_back(pq.top());
    pq.pop();
    
   }
   for (int i = 0; i < ans.size(); i++)
   {
    cout<<ans[i]<<" ";
   }
   
    
}