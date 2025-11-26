class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> nums2;
        for(int num: nums)
            nums2.push_back(num*num);

        sort(nums2.begin(), nums2.end());

        int n = nums2.size();
        long long int sum = 0;

        for(int left = 0, right = n-1; left < right; left++, right--){
            sum -= nums2[left];
            sum += nums2[right];
        }

        // center element for odd length nums[] 
        // with +ive sign to maximize sum
        if(n % 2 == 1)
            sum += nums2[n/2];

        return sum;
    }
};