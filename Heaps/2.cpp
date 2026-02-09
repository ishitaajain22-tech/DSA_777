// PROBLEM LINK : https://www.geeksforgeeks.org/problems/k-largest-elements4206/1
//leetcode: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
