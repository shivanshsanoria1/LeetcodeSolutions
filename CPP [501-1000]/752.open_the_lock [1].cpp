class Solution {
private:
    // returns a vector of 8 strings that could be generated from string 's' 
    vector<string> generateNextCombinations(string& s){
        vector<string> strs;

        for(int i=0; i<4; i++)
        {
            string str1 = s; 
            // increment
            str1[i] = (s[i] - '0' + 1) % 10 + '0'; 
            strs.push_back(str1);

            string str2 = s;
            // decrement
            str2[i] = (s[i] - '0' - 1 + 10) % 10 + '0';
            strs.push_back(str2);
        }

        return strs;
    }

public:
    // T.C.=O(10^4), S.C.=O(10^4)
    // BFS
    int openLock(vector<string>& deadends, string target) { 
        unordered_set<string> deadSet(deadends.begin(), deadends.end());

        // "0000" is itself a deadend
        if(deadSet.find("0000") != deadSet.end()) 
            return -1;

        unordered_set<string> visited;
        queue<string> q;
        int steps = 0;

        visited.insert("0000");
        q.push("0000");

        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                string curr = q.front();
                q.pop();

                // reached the target
                if(curr == target) 
                    return steps;

                // 8 possible strings that could be generated from curr string
                vector<string> strs = generateNextCombinations(curr);

                for(string str: strs)
                {
                    // skip the deadend strings 
                    if(deadSet.find(str) != deadSet.end())
                        continue;
                    // skip the already visited strings
                    if(visited.find(str) != visited.end())
                        continue;

                    visited.insert(str);
                    q.push(str);
                }
            }
            
            steps++;
        }

        // cannot reach the target string
        return -1; 
    }
};