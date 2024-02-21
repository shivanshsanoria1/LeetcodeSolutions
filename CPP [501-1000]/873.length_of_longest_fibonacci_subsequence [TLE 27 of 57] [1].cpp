class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) { //T.C.=O(n^3) , S.C.=O(1)
        int n=arr.size(), max_len=0;
        int f2, f1, f; //f: F(n), f1: F(n-1), f2: F(n-2)
        for(int i=0; i<n-2; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                f2=i;
                f1=j;
                int curr_len=2;
                for(int k=j+1; k<n; k++)
                {
                    f=k;
                    if(arr[f] == arr[f2] + arr[f1])
                    {
                        curr_len++;
                        f2=f1;
                        f1=f;
                    }
                    else if(arr[f] > arr[f2] + arr[f1])
                        break;
                }
                if(curr_len > 2) //min curr length must be 3
                    max_len= max(max_len,curr_len);
            }
        }
        return max_len;
    }
};