class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        unordered_set<int> s;
        for(int num: nums)
        {
            if(s.find(num) != s.end()) // num found in set
                s.erase(num);
            else
                s.insert(num);
        }
        vector<int> ans;
        for(int num: s)
            ans.push_back(num);
        return ans;
    }
};