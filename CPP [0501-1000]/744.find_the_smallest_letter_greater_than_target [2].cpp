class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) { // T.C.=O(logn), S.C.=O(1)
        int left = 0, right = letters.size()-1;
        char ans = ' ';
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(letters[mid] > target) // move to the left subarray
            {
                ans = letters[mid];
                right = mid - 1;
            }
            else // move the right subarray
                left = mid + 1;
        }
        return ans == ' ' ? letters[0] : ans;
    }
};