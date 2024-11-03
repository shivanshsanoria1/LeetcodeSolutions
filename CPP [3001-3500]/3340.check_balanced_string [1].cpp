class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    bool isBalanced(string num) {
        int sum0 = 0, sum1 = 0;
        for(int i=0; i<num.length(); i++)
        {
            if(i % 2 == 0)
                sum0 += num[i] - '0';
            else
                sum1 += num[i] - '0';
        }

        return sum0 == sum1;
    }
};