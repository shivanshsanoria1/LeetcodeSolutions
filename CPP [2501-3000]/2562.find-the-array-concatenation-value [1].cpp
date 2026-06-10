class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long int ans = 0;
        int left = 0, right = nums.size()-1;
        while(left <= right)
        {
            if(left == right)
                ans += nums[left];
            else
                ans += stoi(to_string(nums[left]) + to_string(nums[right]));
            left++;
            right--;
        }
        return ans;
    }
};