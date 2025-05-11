class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    bool threeConsecutiveOdds(vector<int>& arr) {
        // count of consecutive odd nums
        int countOdd = 0;
        for(int num: arr)
        {
            // reset count
            if(num % 2 == 0)
                countOdd = 0;
            // increment count
            else if(++countOdd == 3)
                return true;
        }

        return false;
    }
};