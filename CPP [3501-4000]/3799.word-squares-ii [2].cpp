class Solution {
private:
    void solve(vector<string>& words, vector<vector<string>>& groups, vector<int>& group, int idx){
        if(group.size() == 4){
            vector<string> quad;
            for(int i: group)
                quad.push_back(words[i]);
            groups.push_back(quad);
        }
        
        for(int i=0; i<words.size(); i++){
            // index i already used up in curr group
            if(find(group.begin(), group.end(), i) != group.end())
                continue;

            // curr word can be the:
            // 1: TOP
            bool cond1 = group.size() == 0;
            // 2: LEFT
            bool cond2 = group.size() == 1 && words[group[0]][0] == words[i][0];
            // 3: RIGHT
            bool cond3 = group.size() == 2 && words[group[0]][3] == words[i][0];
            // 4: BOTTOM
            bool cond4 = group.size() == 3 && words[group[1]][3] == words[i][0] && words[group[2]][3] == words[i][3];

            if(cond1 || cond2 || cond3 || cond4){
                group.push_back(i);
                solve(words, groups, group, i+1);
                group.pop_back();
            }
        }
    }

public:
    // T.C.=O((4*n)^4 + n*log(n)), S.C.=O(4)
    // Backtracking
    vector<vector<string>> wordSquares(vector<string>& words) {
        sort(words.begin(), words.end());

        vector<vector<string>> groups;
        // stores indexes and not the word strings
        vector<int> group;

        solve(words, groups, group, 0);

        return groups;
    }
};

/*

a group should be of the form:
(TOP, LEFT, RIGHT, BOTTOM)

A * * B
*     *
*     *
C * * D

TOP: A**B
LEFT: A**C
RIGHT: B**D
BOTTOM: C**D

where * can be any char

*/