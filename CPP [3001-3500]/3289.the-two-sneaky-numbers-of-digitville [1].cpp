class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> ans;

        for(int num: nums)
        {
            if(s.find(num) != s.end())
            {
                ans.push_back(num);
                if(ans.size() == 2)
                    break;
            }
            else
                s.insert(num);
        }
        
        return ans;
    }
};