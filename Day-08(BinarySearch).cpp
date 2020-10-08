/*
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return -1;
        int low=0,high=n-1;
         int mid;
        while(low<=high)
        {
            mid= low +(high-low)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid] > target)
                high=mid-1;
            else
                low=mid+1;
        }
        
        return -1;
        
    }
};
