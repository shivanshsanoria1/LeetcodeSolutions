class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) { // T.C.=O(n), S.C.=O(1)
        int n=arr.size();
        int left = 0, right = 1;
        int flag = 0; // unset flag
        int count = 0; // inequality count in subarray
        int maxCount = 0;
        while(right < n)
        {
            if(arr[right-1] < arr[right]) // -ve flag case
            {
                if(flag == 0 || flag == 1) // prev flag must be unset or +ive
                {
                    flag = -1; // set the flag to -ive
                    count++;
                }
                else
                {
                    left = right-1; // update left
                    maxCount = max(maxCount, count);
                    count = 1; // reset count to 1 (inequality between left and right is counted)
                }
            }
            else if(arr[right-1] > arr[right]) // +ive flag case
            {   
                if(flag == 0 || flag == -1) // prev flag must be unset or -ive
                {
                    flag = 1; // set the flag to +ive
                    count++;
                }
                else
                {
                    left = right-1; // update left
                    maxCount = max(maxCount, count);
                    count = 1; // reset count to 1 (inequality between left and right is counted)
                }
            }
            else // arr[right-1] == arr[right]
            {
                left = right; // update left
                maxCount = max(maxCount, count);
                count = 0; // reset count to 0 (equality between left and right is not counted)
            }
            right++;
        }
        return 1 + max(maxCount, count);
    }
};
/*
# if arr[right-1] < arr[right] set flag = -1
# if arr[right-1] > arr[right] set flag = 1
*/