// PROBLEM LINK-: https://leetcode.com/problems/sort-an-array/   https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>res;
        for(int i:nums){
            pq.push(i);
        }
            for(int i=0;i<nums.size();i++){
                int u = pq.top();
                res.push_back(u);
                pq.pop();
            }
        return res;
    }
};
