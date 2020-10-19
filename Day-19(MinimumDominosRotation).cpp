/*
Time complexity  : O(n)
Space complexity : O(1)
My approach : Use a hash table to calculate which number can possibly be the answer, if there are two numbers like this then the rotations reqd. are 0, other-wise the 
    rotaion required will be min(count,count1,nA-count,nB-count)
*/
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n =A.size();
        int m =B.size();
        if(n==0 or m==0 ) return -1;
        int hash[7];
        memset(hash,0,sizeof(hash));
        for(int i=0;i<n;i++)
        {
            if(A[i]==B[i]) hash[A[i]]++;
            else
            {
                hash[A[i]]++;
                hash[B[i]]++;
            }
        }
        
        vector<int> answer;
        for(int i=1;i<=6;i++)
        {
            if(hash[i]==n)
                answer.push_back(i);
        }
        
        if(answer.size()==2) return 0;
        if(answer.size()==1)
        {
            int count=0,count1=0;
            for(int i=0;i<n;i++)
            {
                if(answer[0]==A[i])
                    count++;
            }
            
            for(int i=0;i<m;i++)
            {
                 if(answer[0]==B[i])
                    count1++;
            }
                
            return min(count,min(count1,min(n-count,m-count1)));
        }
        return -1;
        
    }
};

