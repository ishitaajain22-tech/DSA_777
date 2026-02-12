//PROBLEM LINK: https://www.geeksforgeeks.org/problems/k-closest-elements3619/1 https://leetcode.com/problems/find-k-closest-elements/description/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++){
            int dist = abs(arr[i] - x);
            pq.push({dist,arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(),res.end()); //this is also important
        return res;
    }
};
