/* 
Time complexity : O(N)
Space complexity : O(n) ,could also be done is constant space.
Best Hint : Since House[1] and House[n] are adjacent, they cannot be robbed together.
Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money.
Now the problem has degenerated to the House Robber, which is already been solved.
*/

class Solution {
public:
    
    int money(vector<int> arr )
    {
        int n = arr.size(); 
        int dp[n];
        memset (dp,0,sizeof(dp));
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1],arr[i]+dp[i-2]);
        }
        
        return dp[n-1];
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        return max(money(vector<int>(nums.begin(),nums.end()-1)),money(vector<int>(nums.begin()+1,nums.end())));
         
    }
};
