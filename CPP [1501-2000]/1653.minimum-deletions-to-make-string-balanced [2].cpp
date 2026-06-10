class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minimumDeletions(string s) {
        int count_b = 0;
        int deletions = 0;

        for(char ch: s)
        {
            if(ch == 'b')
                count_b++;
            else if(count_b > 0)
            {
                count_b--;
                deletions++;
            }
        }

        return deletions;
    }
};