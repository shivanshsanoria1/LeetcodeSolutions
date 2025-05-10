class Solution {
private:
    int updatePairCount(vector<int>& colors, int n, int i, int count, int updater){
        if(i-1 >= 0 && colors[i-1] != 0 && colors[i-1] == colors[i])
            count += updater;
        if(i+1 < n && colors[i+1] != 0 && colors[i] == colors[i+1])
            count += updater;
        
        return count;
    }

public:
    // T.C.=O(n + q), S.C.=O(n)
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> colors(n, 0);
        int count = 0;
        vector<int> ans;

        for(vector<int>& query: queries)
        {
            int i = query[0];
            int newColor = query[1];
            
            // possibly decrement the pair count due to the removal of prev color
            count = updatePairCount(colors, n, i, count, -1);
            colors[i] = newColor;
            // possibly increment the pair count due to the addition the new color
            count = updatePairCount(colors, n, i, count, +1);

            ans.push_back(count);
        }

        return ans;
    }
};

// anytime the color of element at index i is changed 
// only the pairs (i-1, i) and (i, i+1) are affected