class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    bool threeConsecutiveOdds(vector<int>& arr) {
        // count of consecutive odd nums
        int countOdd = 0;

        for(int num: arr)
        {
            if(num % 2 == 1)
            {
                countOdd++;
                if(countOdd == 3)
                    return true;
            }
            else
                countOdd = 0;
        }

        return false;
    }
};