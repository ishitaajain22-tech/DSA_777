//PROBLEM LINK: https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b){ //repeatedly asks should n1 come before n2
            if(mp[a] ==  mp[b]){
                return mp[a]>mp[b];
            }
            return mp[a]<mp[b];
        });
        return nums;
    }
};
