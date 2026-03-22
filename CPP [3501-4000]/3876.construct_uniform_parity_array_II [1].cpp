class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    bool uniformArray(vector<int>& nums1) {
        int minOdd = int(1e9);
        for(const int num: nums1)
            if(num % 2 == 1)
                minOdd = min(minOdd, num);

        // try to convert all even -> odd
        bool allOddPossible = true;
        for(const int num: nums1)
            if(num % 2 == 0 && num - minOdd < 1){
                allOddPossible = false;
                break;
            }
        
        if(allOddPossible)
            return true;
        
        // try to convert all odd -> even
        bool allEvenPossible = true;
        for(const int num: nums1)
            if(num % 2 == 1 && num - minOdd < 1){
                allEvenPossible = false;
                break;
            }
        
        return allEvenPossible; 
    }
};

/*
# Case 1: all nums are either odd or even
    no need to change anything
# Case 2: convert all evens to odd
    even -> odd (need 1 odd < curr even)
# Case 3: convert all odds to even
    odd -> even (need 1 odd < curr odd)
*/