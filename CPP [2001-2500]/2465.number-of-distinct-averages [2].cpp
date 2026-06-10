class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        vector<int> freq(101, 0); // num -> freq
        for(int num: nums)
            freq[num]++;
        unordered_set<int> s;
        int left = 0, right = 100;
        while(left <= right)
        {
            if(freq[left] == 0)
            {
                left++;
                continue;
            }
            if(freq[right] == 0)
            {
                right--;
                continue;
            }
            s.insert(left + right);
            freq[left]--;
            freq[right]--;
        }
        return s.size();
    }
};