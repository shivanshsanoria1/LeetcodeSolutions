class Solution {
private:
    // returns true if bloomDay[] can be partitioned into 
    // 'm' groups of size 'k' with each group element <= 'd'
    bool check(vector<int>& bloomDay, int m, int k, int d){
        int n=bloomDay.size();
        int left = 0, right = 0;

        while(right < n && m > 0)
        {
            // streak broken by an invalid element
            if(bloomDay[right] > d)
                left = right + 1;
            // a group of size 'k' found
            else if(right - left + 1 == k)
            {
                left = right + 1;
                m--;
            }

            right++;
        }

        return m == 0;
    }

public:
    // T.C.=O(n*(max - min)), S.C.=O(1)
    // max, min: max and min val in bloomDay[]
    // Linear-search + 2-pointer
    int minDays(vector<int>& bloomDay, int m, int k) {
        // not possible to partition bloomDay[] 
        // into 'm' groups of size 'k'
        if((long long int)m*k > bloomDay.size())
            return -1;
        
        int firstDay = *min_element(bloomDay.begin(), bloomDay.end());
        int lastDay = *max_element(bloomDay.begin(), bloomDay.end());

        for(int i = firstDay; i <= lastDay; i++)
            if(check(bloomDay, m, k, i))
                return i;
        
        return -1;
    }
};