class Solution {
public:
    // T.C.=O(n), S.C.=O(2*n)
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        int t = time;

        if(2*t + 1 > n)
            return {};
        
        if(t == 0)
        {
            vector<int> ans;
            for(int i=0; i<n; i++)
                ans.push_back(i);

            return ans;
        }

        vector<bool> prefix(n, false);
        vector<bool> postfix(n, false);

        int count = 0;
        for(int i=1; i<n; i++)
        {
            if(security[i-1] >= security[i])
                count++;
            else
                count = 0;
            
            if(count >= t)
                prefix[i] = true;
        }

        count = 0;
        for(int i=n-2; i>=0; i--)
        {
            if(security[i] <= security[i+1])
                count++;
            else
                count = 0;
            
            if(count >= t)
                postfix[i] = true;
        }

        vector<int> ans;
        for(int i=t; i < n - t; i++)
            if(prefix[i] && postfix[i])
                ans.push_back(i);

        return ans;
    }
};

/*
# prefix[i]: 
  whether there are atleast k consecutive 
  non-increasing elements with index <= i
  
# postfix[i]: 
  whether there are atleast k consecutive 
  non-decreasing elements with index >= i

# similar: [2420. find-all-good-indices]
*/