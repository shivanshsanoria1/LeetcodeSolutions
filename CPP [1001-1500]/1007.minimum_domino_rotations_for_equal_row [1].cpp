class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) { 
        vector<int> freq(7, 0);
        for(int num: tops)
            freq[num]++;
        for(int num: bottoms)
            freq[num]++;
        
        int n = tops.size();
        int finalNum = 0;
        for(int i=1; i<=6; i++)
            if(freq[i] >= n)
                finalNum = i;

        // no num with freq >= 50% found
        if(finalNum == 0)
            return -1;

        int swaps1 = 0, swaps2 = 0;
        for(int i=0; i<n; i++)
        {
            if(tops[i] != finalNum && bottoms[i] != finalNum)
                return -1;
            if(tops[i] == finalNum && bottoms[i] != finalNum)
                swaps1++;
            if(tops[i] != finalNum && bottoms[i] == finalNum)
                swaps2++;
        }
        
        return min(swaps1, swaps2);
    }
};