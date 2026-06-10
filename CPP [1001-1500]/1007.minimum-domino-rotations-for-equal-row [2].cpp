class Solution {
private:
    // returns the min num of swaps needed to convert 
    // each element in tops[] or bottoms[] to 'finalNum'
    int calculateSwaps(vector<int>& tops, vector<int>& bottoms, int finalNum){
        int swaps1 = 0, swaps2 = 0;
        for(int i=0; i<tops.size(); i++)
        {
            if(tops[i] != finalNum && bottoms[i] != finalNum)
                return INT_MAX;
            if(tops[i] == finalNum && bottoms[i] != finalNum)
                swaps1++;
            if(tops[i] != finalNum && bottoms[i] == finalNum)
                swaps2++;
        }
        
        return min(swaps1, swaps2);
    }

public:
    // T.C.=O(n), S.C.=O(1)
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = min(calculateSwaps(tops, bottoms, tops[0]), calculateSwaps(tops, bottoms, bottoms[0]));

        return ans == INT_MAX ? -1 : ans;
    }
};

/*
either every element in tops[] becomes equal to tops[0] or bottoms[0]
or every element in bottoms[] becomes equal to tops[0] or bottoms[0]
*/