class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) { // T.C.O(n^2), S.C.=O(1)
        int n=words.size();
        int count = 0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                if(words[i].length() != words[j].length())
                    continue;
                int len = words[i].length();
                bool flag = true;
                for(int k=0; k<len; k++)
                    if(words[i][k] != words[j][len-k-1])
                    {
                        flag = false;
                        break;
                    }
                if(flag)
                    count++;
            }
        return count;
    }
};