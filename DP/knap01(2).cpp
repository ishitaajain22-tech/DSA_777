// PRACTICE LINKS  -> https://leetcode.com/problems/partition-equal-subset-sum/description/  
// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution {
public:
    bool subsetSum(vector<int>&arr,int sum){
        int n = arr.size();
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        //initialize krna haoi
        for(int i=0;i<=n;i++){
            dp[i][0] = true;
        }

        //2 choices
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j < arr[i-1]){ //bigger element ko exclude krenge
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]] ; //j sum hai, sum-arr[i-1] hai
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }else{
            return subsetSum(nums,sum/2);
        }
    }
};
