class Solution {
public:
    int countTriples(int n) { // T.C.=O(n^2), S.C.=O(1)
        int count = 0;
        for(int i=5; i<=n; i++)
        {
            int left = 1, right = i-1;
            while(left < right)
            {
                if(left*left + right*right == i*i)
                {
                    count += 2;
                    left++;
                    right--;
                }
                else if(left*left + right*right > i*i)
                    right--;
                else
                    left++;
            }
        }
        return count;
    }
};