class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length();
        vector<int> ans(n,-1);
        vector<int> ind; //to store index of 0 values
        for(int i=0; i<n; i++) //find the index of 0 values and fill 0's in ans array
            if(s[i]==c)
            {
                ind.push_back(i);
                ans[i]=0;
            }
        int left=-1, right=ind[0], index=0;
        for(int i=0; i<n; i++)
        {
            if(ans[i]==0) //0 value is found
            {
                left=right; //update left zero
                index++;
                if(index < ind.size()) //update right zero if it exists
                    right=ind[index];
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