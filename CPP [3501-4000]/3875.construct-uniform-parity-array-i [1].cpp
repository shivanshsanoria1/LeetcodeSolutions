class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

/*
# Case 1: all nums are either odd or even
    no need to change anything
# Case 2: convert all evens to odd
    even -> odd (need atleast 1 odd in nums[])
# Case 3: convert all odds to even
    odd -> even (need atleast 2 odds in nums[])

# thus, in any case we can just focus on the odd nums
# 0 odd: all nums are even
# 1 odd: convert all evens to odd
# >=2 odds: convert all odds to even

# therefore, in any case it is always possible to make nums[] the same parity 
*/