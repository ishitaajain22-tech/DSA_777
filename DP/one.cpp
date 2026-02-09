// LEETCODE/GFG -> PRACTICE LINK ( https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1 )

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++){
            dp[i][0]=true; //baaki sab already initialzed by false
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j < arr[i-1]){
                    dp[i][j] = dp[i-1][j]; //bada element will be xcluded always
                }else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]]; //or because bool values ke saath dealing
                }
            }
        }
        return dp[n][sum];
    }
};
