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
    int guessNumber(int n) { // T.C.=O(n)
        for(int i=1; i<=n; i++)
            if(guess(i) == 0)
                return i;
        return -1;
    }
};