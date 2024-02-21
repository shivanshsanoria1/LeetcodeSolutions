class Solution {
public:
    int distinctAverages(vector<int>& nums) { // T.C.=O(n*logn), S.C.O(n)
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;
        unordered_set<int> s;
        while(left < right)
        {
            s.insert(nums[left] + nums[right]);
            left++;
            right--;
        }
        return s.size();
    }
};