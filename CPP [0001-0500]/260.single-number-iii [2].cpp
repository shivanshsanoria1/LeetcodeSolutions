class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // unordered-set
    vector<int> singleNumber(vector<int>& nums) { 
        unordered_set<int> s;
        for(int num: nums)
        {
            // num found in set
            if(s.find(num) != s.end()) 
                s.erase(num);
            // num not found in set
            else
                s.insert(num);
        }

        vector<int> ans;
        for(int num: s)
            ans.push_back(num);
        return ans;
    }
};