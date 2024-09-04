class Solution {
public:
    // T.C.=O(r), S.C.=O(r)
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> mp;
        
        for(vector<int>& reservedSeat: reservedSeats)
        {
            int r = reservedSeat[0];
            int c = reservedSeat[1];

            if(mp.find(r) == mp.end())
            {
                vector<bool> isReserved(11, false);
                mp[r] = isReserved;
            }

            mp[r][c] = true;
        }

        // assuming each row has block2345 and block6789 free
        int freeBlocks = 2*n;

        for(auto& [r, isReserved]: mp)
        {
            // assuming these blocks are free in the row 'r'
            bool block2345 = true;
            bool block4567 = true;
            bool block6789 = true;

            for(int i=2; i<=9; i++)
            {
                if(!isReserved[i])
                    continue;

                if(i >= 2 && i <= 5)
                    block2345 = false;
                if(i >= 4 && i <= 7)
                    block4567 = false;
                if(i >= 6 && i <= 9)
                    block6789 = false;
            }

            if(!block2345)
                freeBlocks--;
            if(!block6789)
                freeBlocks--;

            if(!block2345 && !block6789 && block4567)
                freeBlocks++;
        }

        return freeBlocks;
    }
};