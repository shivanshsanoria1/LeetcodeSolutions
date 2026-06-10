class Solution {
public:
    int countOdds(int low, int high) {
        int diff = high - low;
        if(low % 2 == 0 && high % 2 == 0) // both limits are even
            return diff/2;
        if(low % 2 == 1 && high % 2 == 1) // both limits are odd
            return diff/2 + 1;
        // one limit is even and other is odd
        return (diff + 1) / 2; 
    }
};