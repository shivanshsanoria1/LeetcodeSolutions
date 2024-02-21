class Solution {
public:
    // returns a vector of 8 strings that could be generated from string 's' 
    vector<string> generateNextCombinations(string &s){
        vector<string> strs;
        for(int i=0; i<4; i++)
        {
            string str1 = s; 
            str1[i] = (s[i]-'0'+1) % 10 + '0'; // increment
            strs.push_back(str1);
            string str2 = s;
            str2[i] = (s[i]-'0'+9) % 10 + '0'; // decrement
            strs.push_back(str2);
        }
        return strs;
    }

    int openLock(vector<string>& deadends, string target) { // BFS, T.C.=O(10^4), S.C.=O(10^4)
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if(visited.find("0000") != visited.end()) // "0000" is itself a deadend
            return -1;
        int ans=0;
        queue<string> q;
        visited.insert("0000");
        q.push("0000");
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string curr = q.front();
                q.pop();
                if(curr == target) // reached the target
                    return ans;
                // 8 possible strings that could be generated from curr string
                vector<string> strs = generateNextCombinations(curr);
                for(string str: strs)
                    // not a deadend string and is an unvisited string
                    if(visited.find(str) == visited.end())
                    {
                        visited.insert(str);
                        q.push(str);
                    }
            }
            ans++;
        }
        return -1; // cannot reach the target
    }
};
// deadend strings can be treated as visited strings so we won't push them in queue