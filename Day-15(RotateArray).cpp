/*
Time complexity : O(N)
Space complexity : O(1)
My approach :  step -1) Reverse whole vector.  step-2) reverse size% k part of the vector from begin  step-3) reverse the remaining part of the vector.
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {  // 1,2,3,4,5,6,7  [4 5 6 7  1  2 3]
        
        int n= nums.size();
        int  t  = k % n;
        // for(int i=0;i<t;i++)
        // {
        //     int temp = nums[n-1];
        //     for(int i=n-1;i>0;i--)
        //         nums[i] =nums[i-1];
        //     nums[0] = temp;
        // }
        
        reverse(nums.begin(),nums.end());      
        reverse(nums.begin(),nums.begin()+t);
        reverse(nums.begin()+t,nums.end());
        
    }
};
