class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    int numberOfBeams(vector<string>& bank) {
        int totalCount = 0;
        int prevCount = 0;
        for(int i=0; i<bank.size(); i++)
        {
            int currCount = 0;
            for(char ch: bank[i])
                if(ch == '1')
                    currCount++;
            if(currCount == 0)
                continue;
            totalCount += prevCount * currCount;
            prevCount = currCount;
        }
        return totalCount;
    }
};