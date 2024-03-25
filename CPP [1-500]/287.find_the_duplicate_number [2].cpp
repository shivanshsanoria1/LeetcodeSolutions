class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int findDuplicate(vector<int>& nums) { 
        unordered_set<int> s;
        for(int num: nums)
        {
            if(s.find(num) != s.end()) // found in set
                return num;
            s.insert(num);
        }
        return -1;
    }
};