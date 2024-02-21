/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *                1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) { // T.C.=O(logn)
        int left = 1, right = n;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            int curr = guess(mid);
            if(curr == 0) // curr num is equal to ans
                return mid;
            else if(curr == 1) // curr num is smaller than ans
                left = mid + 1;
            else // curr num is larger than ans
                right = mid - 1;
        }
        return -1;
    }
};