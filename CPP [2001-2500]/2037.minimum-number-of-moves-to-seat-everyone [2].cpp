class Solution {
public:
    // T.C.=O(n + 100), S.C.=O(100)
    // Counting-sort
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> availableSeats(101, 0);

        for(int seat: seats)
            availableSeats[seat]++;
        
        for(int student: students)
            availableSeats[student]--;
        
        int prefixSum = 0;
        int ans = 0;
        for(int availableSeat: availableSeats)
        {
            prefixSum += availableSeat;
            ans += abs(prefixSum);
        }

        return ans;
    }
};