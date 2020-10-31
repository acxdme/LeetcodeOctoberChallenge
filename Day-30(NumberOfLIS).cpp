/*
Time complexity :  O(n^2)
Space complexity : O(N)
My approach :  just a slight modification of LIS.
*/

class Solution {
public:
    int find (vector<int>& nums)
    {
        int n = nums.size();
         vector<int> dp(n);
         vector<int> count(n,1);
         dp[0]= 1;
         for(int i=1;i<n;i++)
             dp[i] = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                   if(1+dp[j] > dp[i])
                   {
                       dp[i] = max( dp[i], 1+ dp[j]);
                       count[i] = count[j];
                   }
                   else if( 1+ dp[j] == dp[i])
                   {
                       count[i] +=count[j];
                   }
                } 
            }
        }
        
        int answer=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i] == *max_element(dp.begin(),dp.end()) )
            {
                 answer += count[i]; 
            }
        }
        
      return answer;
    }

    
    int findNumberOfLIS(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        return find(nums);
    }
};
