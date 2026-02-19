#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){}
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> >pq(nums.begin(),nums.end());
        int sum=0;
        for(int i=0; i<nums.size(); i++) sum+=nums[i];
        while(k--){
            int smallestEle=pq.top();
            if(smallestEle==0) break;
            pq.pop();
            sum-=smallestEle;
            smallestEle=-1*smallestEle;
            pq.push(smallestEle);
            sum+=smallestEle;
        }
        return sum;
    }
};