class Solution {
public:
    // T.C.=O(n + m), S.C.=O(n)
    int findChampion(int n, vector<vector<int>>& edges) {
        // assume all teams are champions initially
        vector<bool> isChamp(n, true);

        for(int i=0; i<edges.size(); i++)
            isChamp[edges[i][1]] = false;

        int champ = -1;

        for(int i=0; i<n; i++)
            if(isChamp[i])
            {
                // champion already exists, ie,  multiple champions found
                if(champ != -1)
                    return -1;
                champ = i;
            }
        
        return champ;
    }
};
/*
# A -> B : team A is stronger than team B
# The champion node must have 0 incoming edges
*/