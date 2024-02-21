class Solution {
public:
    int kthGrammar(int n, int k) { // Binary Search, T.C.=O(n), S.C.=O(1)
        int curr = 0;
        int left = 1, right = 1 << (n-1);
        while(n--)
        {
            int mid = left + (right - left)/2;
            if(mid >= k) // move to the left half
                right = mid;
            else // move to the right half
            {
                left = mid + 1;
                curr = !curr; // 0 becomes 1 and 1 becomes 0
            }
        }
        return curr;
    }
};