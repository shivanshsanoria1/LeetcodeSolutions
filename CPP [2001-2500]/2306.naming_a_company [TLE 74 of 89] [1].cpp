class Solution {
public:
    long long distinctNames(vector<string>& ideas) { // T.C.=O(n^2), S.C.=O(n)
        unordered_set<string> s(ideas.begin(), ideas.end());
        int n=ideas.size();
        long long int count = 0;
        for(int i=0; i<n-1; i++)
        {
            string s1 = ideas[i];
            for(int j=i+1; j<n; j++)
            {
                string s2 = ideas[j];
                if(s1[0] == s2[0]) // skip the words with matching 0th char
                    continue;
                // swap the 0th char of s1 and s2
                char temp = s1[0];
                s1[0] = s2[0];
                s2[0] = temp;
                // both s1' and s2' are not found in set
                if(s.find(s1) == s.end() && s.find(s2) == s.end())
                    count += 2;
                // restore the 0th char of s1
                s1[0] = s2[0];
            }
        }
        return count;
    }
};