class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    // Binary + Linear search
    int hIndex(vector<int>& citations) {
        int left = 1, right = citations.size();
        int h = 0;

        while(left <= right)
        {
            int mid = left + (right - left)/2;
            int count = 0;
            
            for(int citation: citations)
            {
                if(citation >= mid)
                    count++;
                if(count == mid)
                {
                    h = mid;
                    break;
                }
            }

            if(count == mid)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return h;
    }
};
/*
# basically we have the find the max value of a num 'h' such that 
  there are atleast 'h' elements greater than or equal to 'h' in citations[]
# range of 'h' is [0, n]
*/