class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Greedy
    int maxOperations(string s) {
        int ones = 0;
        int ops = 0; // operations
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '1')
                ones++;
            else if(i-1 >= 0 && s[i-1] == '1')
                ops += ones;
        }

        return ops;
    }
};
// for each subarray of 0's the num of operations 
// will increment by the num of 1's found till now 