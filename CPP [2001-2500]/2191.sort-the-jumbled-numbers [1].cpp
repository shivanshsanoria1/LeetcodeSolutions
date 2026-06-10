class Solution {
private:
    int getMappedNum(vector<int>& mapping, int num){
        if(num == 0)
            return mapping[0];

        int mappedNum = 0;
        int mul = 1;
        while(num > 0)
        {
            mappedNum += mul * mapping[num % 10];
            mul *= 10;
            num /= 10;
        }

        return mappedNum;
    }

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // {mapped-num, idx}
        vector<pair<int, int>> vec;
        for(int i=0; i<nums.size(); i++)
            vec.push_back({getMappedNum(mapping, nums[i]), i});
            
        sort(vec.begin(), vec.end());

        vector<int> ans;
        for(auto [mappedNum, i]: vec)
            ans.push_back(nums[i]);

        return ans;
    }
};