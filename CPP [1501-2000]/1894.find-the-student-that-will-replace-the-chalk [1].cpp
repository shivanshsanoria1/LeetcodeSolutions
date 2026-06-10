class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        for(int ck: chalk)
            sum += ck;
        k %= sum;

        for(int i=0; i<chalk.size(); i++)
        {
            k -= chalk[i];
            if(k < 0)
                return i;
        }

        return -1;
    }
};