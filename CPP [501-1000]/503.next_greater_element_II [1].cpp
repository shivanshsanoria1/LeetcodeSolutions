class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) { //T.C.=O(n^2) , S.C.=O(1)
        int n=nums.size();
        vector<int> nge(n,-1);
        for(int i=0; i<n; i++)
            for(int j=(i+1)%n; j<n; j++)
            {
                if(nums[j] > nums[i])
                {
                    nge[i]=nums[j];
                    break;
                }
                if(j==i) //j reaches to current element
                    break;
                if(j==n-1) //j is at the last element of array
                    j=(j+1)%n -1; //reach to the start of array
            }
        return nge;
    }
};