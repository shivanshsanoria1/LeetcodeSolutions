class Solution {
public:
    int removeDuplicates(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(n)
        map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;
        int k=0;
        for(auto it: mp)
        {
            if(it.second >= 2)
            {
                nums[k] = it.first;
                k++;
            }
            nums[k] = it.first;
            k++;
        }
        return k;
    }
};