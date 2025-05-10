class Solution {
private:
    // returns the num of adjacent pairs with the same color
    int countAdjPairs(vector<int>& colors){
        int count = 0;
        for(int i=1; i<colors.size(); i++)
            if(colors[i-1] != 0 && colors[i-1] == colors[i])
                count++;
        
        return count;
    }

public:
    // T.C.=O(q*n), S.C.=O(n)
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        // initially all elements are uncolored
        vector<int> colors(n, 0);
        vector<int> ans;

        for(vector<int>& query: queries)
        {
            int idx = query[0];
            int newColor = query[1];
            colors[idx] = newColor;

            ans.push_back(countAdjPairs(colors));
        }

        return ans;
    }
};