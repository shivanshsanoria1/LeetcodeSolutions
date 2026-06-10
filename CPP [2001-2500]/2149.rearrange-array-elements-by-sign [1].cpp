class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(int num: nums)
        {
            if(num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        for(int i=0; i<pos.size(); i++)
        {
            nums[2*i] = pos[i];
            nums[2*i + 1] = neg[i];
        }
        return nums;
    }
};