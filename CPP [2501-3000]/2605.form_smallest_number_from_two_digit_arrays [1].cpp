class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> digs(10, 0);
        int min1 = 10, min2 = 10;
        for(int num: nums1)
        {
            digs[num]++;
            min1 = min(min1, num);
        }
        for(int num: nums2)
        {
            digs[num]++;
            min2 = min(min2, num);
        }
        for(int i=1; i<=9; i++)
            if(digs[i] == 2)
                return i;
        return min1 < min2 ? 10 * min1 + min2 : 10 * min2 + min1;
    }
};