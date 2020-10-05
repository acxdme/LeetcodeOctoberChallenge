/*
Time complexity: O(logN)
Space complexity: O(1)
My approch : Complement create kar diya hai. 
*/

class Solution {
public:
    int bitwiseComplement(int N) {
        int k=0;
        int i=0;
        if(N==0) return 1;
        while(N>0)
        {
            int m= N%2;
            N=N/2;
            k += (1<<i)*(m^1); 
            i++;
        }
        
        return k;
        
        
    }
};
