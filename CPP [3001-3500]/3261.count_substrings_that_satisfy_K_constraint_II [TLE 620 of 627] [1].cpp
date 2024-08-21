class Solution {
private:
    typedef long long int lli;

    // returns the num of substrings of s in index range [left, right]
    // that have either <= k 0's or 1's 
    lli countSubstrings(string& s, int k, int left, int right){
        lli count = 0;

        for(int i=left; i<=right; i++)
        {
            lli count0 = 0, count1 = 0;

            for(int j=i; j<=right; j++)
            {
                if(s[j] == '0')
                    count0++;
                else // s[j] == '1'
                    count1++;

                if(count0 <= k || count1 <= k)
                    count++;
                else
                    break;
            }
        }

        return count;
    }

public:
    // T.C.=O(q*n^2), S.C.=O(1)
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        vector<lli> ans;
        for(vector<int>& query: queries)
        {
            int left = query[0];
            int right = query[1];
            
            ans.push_back(countSubstrings(s, k, left, right));
        }

        return ans;
    }
};