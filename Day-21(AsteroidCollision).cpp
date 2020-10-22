/*
Time complexity : O(N)
Space complexity : O(N) , for the stack
My approach : negative asteroid brings disturbance , stablize rest of the elements present in the stack.
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n =asteroids.size();
        stack<int> s;
        for(int i=0;i<asteroids.size();i++)
        {
            if(s.empty())
            {
                s.push(asteroids[i]);
            }
            else
            {
                if(asteroids[i]>0)
                    s.push(asteroids[i]);
                else
                {
                    bool flag=false;
                    
                    while(!s.empty() and s.top()>0 )
                    {
                        if(abs(asteroids[i])< s.top())
                        {    
                            flag=true;
                            break;
                        }
                        else if(abs(asteroids[i]) > s.top())
                            s.pop();
                        else
                        {
                            flag=true;
                            s.pop();
                             break;
                        }   
                    }
                  
                  if(flag == false)
                      s.push(asteroids[i]);
                }
            }
        }
        vector<int> answer;
        while(!s.empty())
        {
            answer.push_back(s.top());
            s.pop();
        }
        
        reverse(answer.begin(),answer.end());
        return answer;
        
    }
};
