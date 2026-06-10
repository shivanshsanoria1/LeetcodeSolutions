class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int maximumLength(vector<int>& nums) {
        // max-length of subsequence with all 0's
        int count_0s = 0;
        // max-length of subsequence with all 1's
        int count_1s = 0;
        // max-length of alternating-subsequence starting at 0 
        int count_01s = 0;
        // max-length of alternating-subsequence starting at 1
        int count_10s = 0;

        for(int num: nums)
        {
            if(num % 2 == 0)
                count_0s++;
            else
                count_1s++;
        }

        int search = 0;
        for(int num: nums)
            if(num % 2 == search)
            {
                count_01s++;
                search = !search;
            }

        search = 1;
        for(int num: nums)
            if(num % 2 == search)
            {
                count_10s++;
                search = !search;
            }

        return max(max(count_0s, count_1s), max(count_01s, count_10s));
    }
};
// imagine replacing each even num by 0 and odd num by 1