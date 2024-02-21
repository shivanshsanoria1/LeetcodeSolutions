class Solution {
private:
    static bool cmp(vector<int> &p1, vector<int> &p2){
        //int a = p1[0];
        int b = p1[1];
        //int c = p2[0];
        int d = p2[1];
        return b < d;
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) { // Greedy, T.C.=O(nlogn), S.C.=O(1)
        // sort the pairs in increasing order of end values
        sort(pairs.begin(), pairs.end(), cmp); 
        int len = 1;
        int prevEnd = pairs[0][1];
        for(int i=1; i<pairs.size(); i++)
        {
            int currStart = pairs[i][0];
            int currEnd = pairs[i][1];
            if(prevEnd < currStart)
            {
                len++;
                prevEnd = currEnd;
            }
        }
        return len;
    }
};