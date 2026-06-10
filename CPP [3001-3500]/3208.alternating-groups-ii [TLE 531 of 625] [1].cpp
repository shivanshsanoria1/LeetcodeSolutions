class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int count = 0;

        for(int i=0; i<n; i++)
        {
            int itrs = 1;
            for(int j=i; itrs < k; j = (j+1) % n, itrs++)
                if(colors[j] == colors[(j+1) % n])
                    break;

            if(itrs == k)
                count++;
        }

        return count;
    }
};