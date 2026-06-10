class Solution {
public:
    // T.C.=O(n*t), S.C.=O(1)
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int> ans;

        if(2*time + 1 > n)
            return ans;

        for(int i=time; i < n - time; i++)
        {
            bool isGoodDay = true;

            for(int j=i-1; j >= i - time; j--)
                if(security[j] < security[j+1])
                {
                    isGoodDay = false;
                    break;
                }
            
            if(!isGoodDay)
                continue;

            for(int j=i+1; j <= i + time; j++)
                if(security[j-1] > security[j])
                {
                    isGoodDay = false;
                    break;
                }
            
            if(isGoodDay)
                ans.push_back(i);
        }

        return ans;
    }
};

// similar: [2420. find-all-good-indices]