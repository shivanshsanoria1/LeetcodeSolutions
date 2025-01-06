class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(n1)
    // n1: length of s, n2: size of shifts[]
    // Line-sweep algo.
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n1 = s.length(), n2 = shifts.size();
        vector<int> mp(n1, 0);
        for(vector<int>& shift: shifts)
        {
            int left = shift[0], right = shift[1], dir = shift[2];

            // interval starts at 'left' and ends at 'right + 1'
            
            if(dir == 1) // forward dir.
            {
                // incrementing-interval started
                mp[left]++;
                // incrementing-interval ended
                if(right + 1 < n1)
                    mp[right + 1]--;
            }
            else // dir == 0; reverse dir.
            {
                // decrementing-interval started
                mp[left]--;
                // decrementing-interval ended
                if(right + 1 < n1)
                    mp[right + 1]++;
            }
        }

        int prefixSum = 0;
        for(int i=0; i<n1; i++)
        {
            prefixSum += mp[i];

            int val = (s[i] - 'a' + prefixSum);
            // convert val to +ive before taking %
            if(val < 0) 
                val += 26 * ((-val) / 26 + 1);
            val %= 26;

            s[i] = 'a' + val;
        }

        return s;
    }
};