/*
Time complexity : O(N)
Space complexity : O(N)
My approach : store the frequencies of all the 10 lettered substr from the given string in a map.
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> answer;
        if(s.size() < 10)
            return answer;
        unordered_map<string,int> mp;
        for(int i=0;i<s.size()-9;i++)
        {
            string temp;
            temp = s.substr(i,10);
            mp[temp]++;
        }
        
        for(auto it : mp)
        {
            cout<<it.first<<" ";
            if(it.second > 1)
                answer.push_back(it.first);
        }
        
        return answer;
        
        
        
    }
};
