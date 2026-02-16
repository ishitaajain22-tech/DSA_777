class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        if (abs(target)>sum || (sum + target) % 2 != 0){ 
            return 0;
        }     
         /* 
        eq1-> s1+s2 = sum;
        eq2-> s1-s2 = difference;
        2s1 = sum+diff; => s1 = (sum+diff)/2;
        */
        int s1 = (sum+target)/2;
        int ans= subsetCnt(nums,s1);
        return ans;
    }

    int subsetCnt(vector<int>&nums,int s1){
        int n = nums.size();
        int dp[n+1][s1+1];
        dp[0][0]=1; //initialize
        for(int i=1;i<s1+1;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<s1+1;j++){
                if(nums[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][s1];
    }
};
