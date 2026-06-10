class Solution {
public:
    // T.C.=O(n + 100), S.C.=O(100)
    // Counting-sort
    int heightChecker(vector<int>& heights) {
        vector<int> freq(101, 0);
        for(int height: heights)
            freq[height]++;
        
        int i = 0, j = 1;
        int count = 0;
        while(i < heights.size())
        {
            if(freq[j] == 0)
            {
                j++;
                continue;
            }
            
            if(heights[i] != j)
                count++;
            freq[j]--;
            i++;
        }

        return count;
    }
};