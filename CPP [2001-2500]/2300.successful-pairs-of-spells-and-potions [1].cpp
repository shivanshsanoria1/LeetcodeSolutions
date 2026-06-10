class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m=potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(int spell: spells)
        {
            // idx: index of the smallest potion which can form a valid pair with the curr spell
            int idx = -1;
            int left = 0, right = m-1;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(potions[mid] * (long long int)spell >= success)
                {
                    idx = mid;
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            // idx == -1 means no matching potion found for the curr spell
            ans.push_back(idx == -1 ? 0 : m - idx);
        }
        return ans;
    }
};
// T.C.=O(m*logm + n*logm), S.C.=O(1), n: size of spells[], m: size of potions[]