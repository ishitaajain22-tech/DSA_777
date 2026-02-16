//problem link: https://leetcode.com/problems/k-closest-points-to-origin/description/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>>v1;
    priority_queue<pair<int,pair<int,int>>>pq;
    for(int i=0;i<points.size();i++){
        pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});

        while(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        auto p = pq.top().second; //uska second is {1,3}->kaunse 2 points ke beech mei
        v1.push_back({p.first,p.second});
        pq.pop();
    }
    return v1;
    }
};
