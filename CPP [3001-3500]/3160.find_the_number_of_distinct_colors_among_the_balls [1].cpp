class Solution {
public:
    // T.C.=O(q), S.C.=O(min(q, limit) + q)
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // num -> color
        unordered_map<int, int> mp1;
        // color -> freq
        unordered_map<int, int> mp2;
        
        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int num = query[0];
            int color = query[1];
            
            // num is already colored
            if(mp1.find(num) != mp1.end())
            {
                int oldColor = mp1[num];

                mp2[oldColor]--;
                if(mp2[oldColor] == 0)
                    mp2.erase(oldColor);
            }
            
            mp1[num] = color;
            mp2[color]++;
            
            ans.push_back(mp2.size());
        }
        
        return ans;
    }
};