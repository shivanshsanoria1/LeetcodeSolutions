class Solution {
private:
    typedef pair<string, char> PSC;

public:
    // T.C.=O(n*m + 26*m + 26*m*log(26*m)), S.C.=O(26*m)
    // n: size of votes, m: length of every string in votes[]
    string rankTeams(vector<string>& votes) {
        int m=votes[0].length();
        vector<vector<int>> grid(26, vector<int>(m, 0));

        for(string& vote: votes)
            for(int i=0; i<m; i++)
                grid[vote[i] - 'A'][i]++;

        vector<PSC> hashes;
        for(int i=0; i<26; i++)
        {
            string hash = "";
            for(int j=0; j<m; j++)
            {
                string leadingZeros = "";
                if(grid[i][j] < 10)
                    leadingZeros += "000";
                else if(grid[i][j] < 100)
                    leadingZeros += "00";
                else if(grid[i][j] < 1000)
                    leadingZeros += "0";

                hash += leadingZeros + to_string(grid[i][j]) + "#";
            }

            hashes.push_back({hash, i + 'A'});
        }

        // sort in decreasing order of hash-value and 
        // in increasing order of char if hash-values are same
        sort(hashes.begin(), hashes.end(), [](PSC& a, PSC& b){
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        });

        string ans = "";
        for(auto it: hashes)
            ans += it.second;

        // only take the first m chars, the leftover chars 
        // are not present in any string in votes[]
        return ans.substr(0, m);
    }
};
/*
# grid[i][j]: number of jth votes received by person (i + 'A')
# max num of jth votes recevied by any person is n
# as n <= 1000, each jth vote value must be 4 digits while generating the hash
*/