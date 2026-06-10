class Solution {
public:
    // T.C.=O(m), S.C.=O(1)
    // where m is the number of elements in the range pointed to by the *begin and *end iterators. 
    int maxProductDifference(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + 1, nums.end());
        int minPro = nums[0]*nums[1];
        nth_element(nums.begin(), nums.end() - 2, nums.end());
        int n=nums.size();
        int maxPro = nums[n-1]*nums[n-2];
        return maxPro - minPro;
    }
};
/*
# nth_element() rearranges the list in such a way such that the element at the nth position 
  is the one which should be at that position if we sort the list.
# It does not sort the list, just that all the elements, which precede the nth element 
  are not greater than it, and all the elements which succeed it are not less than it.
# The elements to the left and right of nth element maybe in any order
*/