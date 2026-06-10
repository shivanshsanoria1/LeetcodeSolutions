class Solution {
private:
    // returns true if 'm' balls can be positioned 
    // at a min-gap of 'gap' from each other
    bool check(vector<int>& position, int m, int gap){
        int left = 0, right = 0;
        m--; // 1st ball can always be positioned at the 1st position

        while(m > 0 && right < position.size())
        {
            if(position[right] - position[left] >= gap)
            {
                left = right;
                m--;
            }
            right++;
        }

        return m == 0;
    }

public:
    // T.C.=O(n*logn + n*log(max - min)), S.C.=O(1)
    // max, min: max-val and min-val in position[]
    // Sorting + Binary-search + 2-pointer
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int n=position.size();
        int left = 1, right = position[n-1] - position[0];
        int gap = 0;

        while(left <= right)
        {
            int mid = left + (right - left)/2;
            
            if(check(position, m, mid))
            {
                gap = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        
        return gap;
    }
};
/*
# range of values that gap can be is [1, max - min]
# max, min: max-val and min-val in position[]
# min possible gap is 1 and it happens when 
  2 balls are adjacent to each other
# max possible gap is (max - min) and 
  it happens when there are only 2 balls
*/