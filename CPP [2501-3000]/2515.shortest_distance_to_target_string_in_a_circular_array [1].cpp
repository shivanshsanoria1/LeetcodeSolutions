class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int count = 0;
        int ans = INT_MAX;
        // forward direction
        for(int i=startIndex; count < n; i = (i+1) % n, count++)
            if(words[i] == target)
            {
                ans = min(ans, count);
                break;
            }
            
        count = 0;
        // backward direction
        for(int i=startIndex; count < n; i = (i-1+n) % n, count++)
            if(words[i] == target)
            {
                ans = min(ans, count);
                break;
            }

        return ans == INT_MAX ? -1 : ans;
    }
};