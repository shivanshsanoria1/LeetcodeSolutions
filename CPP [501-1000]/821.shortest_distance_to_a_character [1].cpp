class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length();
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++) //mark the zeros
            if(s[i]==c)
                ans[i]=0;
        int left=-1, right=0;
        while(right < n) //move right until a zero is found
        {
            if(ans[right]==0)
                break;
            else
                right++;
        }   
        for(int i=0; i<n; i++)
        {
            if(ans[i]==0)
            {
                left=right; //update left
                right++; //increment right
                while(right < n) //move right until a zero is found
                {
                    if(ans[right]==0)
                        break;
                    else
                        right++;
                }
            }
            else if(left<0) //left zero does not exist
                ans[i]=abs(i-right);
            else if(right>=n) //right zero does not exist
                ans[i]=abs(i-left);
            else //both left and right zeros exist
                ans[i]=min(abs(i-left),abs(i-right));
        }
        return ans;
    }
};