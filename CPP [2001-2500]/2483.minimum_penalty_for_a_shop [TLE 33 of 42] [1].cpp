class Solution {
public:
    int bestClosingTime(string customers) { // T.C.=O(n^2), S.C.=O(1)
        int n=customers.length();
        int n_open = 0; // num of hours where shop was open and no customers visited
        int minPenalty = n;
        int ans = -1;
        // assume the shop closes at the ith hour (is also closed at ith hour)
        for(int i=0; i<=n; i++) 
        {
            if(i-1 >= 0 && customers[i-1] == 'N')
                n_open++;

            int y_closed = 0; // num of hours where shop was closed and some customers visited
            for(int j=i; j<n; j++)
                if(customers[j] == 'Y')
                    y_closed++;

            if(n_open + y_closed < minPenalty)
            {
                minPenalty = n_open + y_closed;
                ans = i;
            }
        }
        return ans;
    }
};