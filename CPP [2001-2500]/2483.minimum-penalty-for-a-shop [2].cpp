class Solution {
public:
    int bestClosingTime(string customers) { // T.C.=O(n), S.C.=O(1)
        int n=customers.length();
        int y_total = 0;
        for(char ch: customers)
            if(ch == 'Y')
                y_total++;

        int n_open = 0; // num of hours where shop was open and no customers visited
        int y_closed = y_total; // num of hours where shop was closed and some customers visited
        int minPenalty = n; // at max all the hours count towards the penalty
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
                y_closed--;
            else
                n_open++;
        }
        return hour;
    }
};