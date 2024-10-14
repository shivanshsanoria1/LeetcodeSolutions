class Solution {
public:
    // T.C.=O(n*m), S.C.=O(1)
    // m: max-val in nums[]
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int num: nums)
        {
            bool found = false;

            for(int x=1; x <= num; x++)
                if((x | (x+1)) == num)
                {
                    ans.push_back(x);
                    found = true;
                    break;
                }
            
            if(!found)
                ans.push_back(-1);
        }

        return ans;
    }
};