class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    // Linear + Linear search
    int hIndex(vector<int>& citations) {
        for(int h=citations.size(); h>=1; h--)
        {
            int count = 0;
            for(int citation: citations)
            {
                if(citation >= h)
                    count++;
                if(count == h)
                    return h;
            }
        }

        return 0;
    }
};
/*
# basically we have the find the max value of a num 'h' such that 
  there are atleast 'h' elements greater than or equal to 'h' in citations[]
# range of 'h' is [0, n]
*/