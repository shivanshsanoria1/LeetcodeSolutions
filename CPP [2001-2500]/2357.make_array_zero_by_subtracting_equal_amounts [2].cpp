class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        for(int num: nums)
        {
            if(num == 0)
                continue;
            s.insert(num);
        }
        return s.size();
    }
};
// just find the num of non-zero unique numbers