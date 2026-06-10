class Solution {
public:
    void rotate(vector<int>& nums, int k) { //S.C.=O(n)
        int n=nums.size();
        vector<int> vec(n);
        int j=k;
        for(int i=0; i<n; i++)
        {
            j=j%n; //make the counter return to 0th index after reaching (n-1)th index
            vec[j]=nums[i];
            j++;
        }
        for(int i=0; i<n; i++)
            nums[i]=vec[i];
    }
};