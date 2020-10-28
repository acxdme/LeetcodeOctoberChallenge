/*
Time complexity : O(N)
Space complexity : O(N) , for ouput vector of string.
My approach : initialize start as nums[0] and end as INT_MIN , traverse the nums vector and get valid start and end points ranges or solo points as they exist.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n =nums.size();
        vector<string> answer;
        if(n==0) return answer;
        if(n==1) 
        { 
            string temp = to_string(nums[0]);
            answer.push_back(temp);
            return answer;
            
        }
        int start = nums[0];
        int end= INT_MIN;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                end = nums[i];
            }
            else
            {
               if(end > start)
               {string t1 = to_string(start) + "->" + to_string(end);
                answer.push_back(t1);}
               if(start >= end or end == INT_MIN )
                   answer.push_back(to_string(start));
                start = nums[i];   
            }
        }
        if(end < start)  answer.push_back(to_string(start));
        else {
            string t2 = to_string(start) + "->" + to_string(end);
            answer.push_back(t2);
        }
        
       return answer; 
    }
};
