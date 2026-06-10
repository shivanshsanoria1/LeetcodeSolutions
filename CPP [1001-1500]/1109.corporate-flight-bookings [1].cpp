class Solution {
public:
    // T.C.=O(b*n), S.C.=O(1)
    // b: size of bookings[]
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);

        for(vector<int>& booking: bookings)
        {
            int start = booking[0];
            int end = booking[1];
            int seats = booking[2];

            for(int i=start; i<=end; i++)
                ans[i-1] += seats;
        }

        return ans;
    }
};