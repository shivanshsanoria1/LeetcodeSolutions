class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) { // T.C.=O(n^2), S.C.=O(1)
        int n=arr.size();
        int maxCount = 0;
        for(int i=0; i<n-1; i++)
        {
            int flag = 0; // unset flag
            int count = 0; // inequality count in subarray
            for(int j=i+1; j<n; j++)
            {
                if(arr[j-1] < arr[j]) // -ve flag case
                {   
                    if(flag == 0 || flag == 1) // prev flag must be unset or +ive
                        flag = -1; // set the flag to -ive
                    else
                        break;
                }
                else if(arr[j-1] > arr[j]) // +ive flag case
                {   
                    if(flag == 0 || flag == -1) // prev flag must be unset or -ive
                        flag = 1; // set the flag to +ive
                    else
                        break;
                }
                else // arr[j-1] == arr[j]
                    break;
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return 1 + maxCount; // for E inequalities there are 1 + E elements
     }
};
/*
# if arr[j-1] < arr[j] set flag = -1
# if arr[j-1] > arr[j] set flag = 1
*/