class Solution {
public:
    int bestClosingTime(string customers) { // T.C.=O(n), S.C.=O(1)
        int n=customers.length();
        int y_total = 0, n_total = 0;
        for(char ch: customers)
        {
            if(ch == 'Y')
                y_total++;
            else
                n_total++;
        }

        int y_open = 0, n_open = 0;
        int y_closed = y_total, n_closed = n_total;
        int minPenalty = n;
        int hour = -1; // hour at which shop should be closed to minimize penalty
        for(int i=0; i<=n; i++)
        {
            if(n_open + y_closed < minPenalty)
            {
                minPenalty = n_open + y_closed;
                hour = i;
            }
            if(i == n)
                break;
            if(customers[i] == 'Y')
            {
                y_closed--;
                y_open++;
            }
            else
            {
                n_closed--;
                n_open++;
            }
        }
        return hour;
    }
};