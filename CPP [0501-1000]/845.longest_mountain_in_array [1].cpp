class Solution {
public:
    int longestMountain(vector<int>& arr) { // T.C.=O(n^2), S.C.=O(1)
        int n=arr.size();
        int ans = 0;
        for(int i=1; i<n-1; i++)
        {
            int left = i-1, right = i+1;
            int leftLen = 0, rightLen = 0;
            while(left >= 0)
            {
                if(arr[left] >= arr[left+1])
                    break;
                leftLen++;
                left--;
            }
            while(right < n)
            {
                if(arr[right-1] <= arr[right])
                    break;
                rightLen++;
                right++;
            }
            // no elements found on the left or right side
            if(leftLen == 0 || rightLen == 0)
                continue;
            ans = max(ans, 1 + leftLen + rightLen);
        }
        return ans;
    }
};