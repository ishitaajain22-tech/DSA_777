//problem link: https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char chr:s){
            mp[chr]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto &p:mp){
            pq.push({p.second,p.first});
        }
        string res="";
        while(!pq.empty()){
            auto [freq,chr] = pq.top();
            pq.pop();
            res.append(freq,chr);
        }
        return res;
    }
};
