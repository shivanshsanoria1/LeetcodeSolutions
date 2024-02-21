class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) { // T.C.=O(n), S.C.=O(1)
        vector<int> freq(7, 0);
        int n=tops.size();
        for(int num: tops)
            freq[num]++;
        for(int num: bottoms)
            freq[num]++;
        int num = 0;
        for(int i=1; i<=6; i++)
            if(freq[i] >= n)
                num = i;
        if(num == 0)
            return -1;
        int swaps1 = 0, swaps2 = 0;
        for(int i=0; i<n; i++)
        {
            if(tops[i] != num && bottoms[i] != num)
                return -1;
            if(tops[i] == num && bottoms[i] != num)
                swaps1++;
            if(tops[i] != num && bottoms[i] == num)
                swaps2++;
        }
        return min(swaps1, swaps2);
    }
};