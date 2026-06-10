class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) { //T.C.=O(n^2) , S.C.=O(n)
        unordered_set<int> s(arr.begin(),arr.end());
        int n=arr.size(), max_len=0;
        int f2, f1, f; //f: F(n), f1: F(n-1), f2: F(n-2)
        for(int i=0; i<n-2; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                f2=arr[i];
                f1=arr[j];
                f= f2 + f1;
                int curr_len=2;
                while(s.find(f) != s.end()) //(f2+f1) found in set
                {
                    f2=f1;
                    f1=f;
                    f= f2 + f1;
                    curr_len++;
                    max_len= max(max_len,curr_len);
                }
            }
        }
        return max_len >= 3 ? max_len : 0;
    }
};