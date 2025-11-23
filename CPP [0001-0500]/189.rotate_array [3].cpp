class Solution {
public:
    void rotate(vector<int>& nums, int k) { //S.C.=O(1)
        int n=nums.size();
        k=k%n; //to reduce k in the range(0,n-1)
        reverse(nums.begin(),nums.end()); //reverse all the elements
        reverse(nums.begin(),nums.begin()+k); //reverse the first k elements, ie, from index 0 to (k-1)
        reverse(nums.begin()+k,nums.end()); //reverse the remaining (n-k) elements, ie, from index k to (n-1)
    }
};