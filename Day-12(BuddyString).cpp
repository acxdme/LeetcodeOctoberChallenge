/*
Time complexity : O(N)
Space complexity : O(N) 
My approach : maintain hashset, check lenth sizes of a and b , check if valid swap points exist or not.

*/
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
          return false;
        map<int,int> hash;
        if(A == B)
        {
          for(int i=0;i<A.size();i++)
          {
            hash[A[i]-'a']++;
          }
        if(hash.size() < A.size())
            return true;
         else
             return false;
        }
        vector<int> diff;
        for(int i=0;i<A.size();i++)
        {
            if(A[i] != B[i])
                diff.push_back(i);
            
        }
        if(diff.size()==2 and A[diff[0]]==B[diff[1]] and A[diff[1]]==B[diff[0]])
            return true;
       
        
        
        return false;
        
    }
};
