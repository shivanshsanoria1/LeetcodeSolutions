class Solution {
public:
    // T.C.=O(n), S.C.=O(2*n)
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        int t = time;

        if(2*t + 1 > n)
            return {};

        vector<int> prefix(n, 0);
        vector<int> postfix(n, 0);

        for(int i=1; i<n; i++)
            if(security[i-1] >= security[i])
                prefix[i] = prefix[i-1] + 1;
        
        for(int i=n-2; i>=0; i--)
            if(security[i] <= security[i+1])
                postfix[i] = postfix[i+1] + 1;
        
        vector<int> ans;
        for(int i=t; i < n - t; i++)
            if(prefix[i] - prefix[i - t] == t && postfix[i] - postfix[i + t] == t)
                ans.push_back(i);

        return ans;
    }
};

/*
# prefix[i]: num of consecutive non-increasing elements with index <= i
# postfix[i]: num of consecutive non-decreasing elements with index >= i

# similar: [2420. find-all-good-indices]
*/