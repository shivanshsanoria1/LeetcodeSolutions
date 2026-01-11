class Solution {
public:
    // T.C.=O(n^4 + n*log(n)), S.C.=O(4)
    vector<vector<string>> wordSquares(vector<string>& words) {
        sort(words.begin(), words.end());

        vector<vector<string>> groups;
        int n = words.size();

        for(int a=0; a<n; a++){
            vector<string> group;
            group.push_back(words[a]);

            for(int b=0; b<n; b++){
                if(a == b)
                    continue;

                if(group[0][0] != words[b][0])
                    continue;
                group.push_back(words[b]);

                for(int c=0; c<n; c++){
                    if(a == c || b == c)
                        continue;

                    if(group[0][3] != words[c][0])
                        continue;
                    group.push_back(words[c]);

                    for(int d=0; d<n; d++){
                        if(a == d || b == d || c == d)
                            continue;

                        if(!(group[1][3] == words[d][0] && group[2][3] == words[d][3]))
                            continue;
                        group.push_back(words[d]);

                        groups.push_back(group);

                        group.pop_back();
                    }
                    group.pop_back();
                }
                group.pop_back();
            }
            group.pop_back();
        }

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