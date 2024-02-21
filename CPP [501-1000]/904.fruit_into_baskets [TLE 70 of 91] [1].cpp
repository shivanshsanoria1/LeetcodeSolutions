class Solution {
public:
    int totalFruit(vector<int>& fruits) { // T.C.=O(n^2), S.C.=O(1)
        int n=fruits.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int a = -1, b = -1;
            int currLen = 0; // length of curr subarray
            for(int j=i; j<n; j++)
            {
                if(a == -1 || fruits[j] == a) // 1st distinct num
                {
                    currLen++;
                    a = fruits[j];
                }
                else if(b == -1 || fruits[j] == b) // 2nd distinct num
                {
                    currLen++;
                    b = fruits[j];
                }
                else // 3rd distinct num
                    break;
            }
            ans = max(ans, currLen);
        }
        return ans;
    }
};
// just find the longest subarray with atmost 2 distinct numbers