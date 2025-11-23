class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) { //T.C.=O(n^2) , S.C.=O(n)
        int n=nums.size();
        vector<bool> vec(n,false); //initially all elements are unvisited
        int glo_inv=0, loc_inv=0;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] > nums[i+1]) //count local inversions
                loc_inv++;
            vec[nums[i]]=true; //mark the curr element as visited
            int curr_glo_inv=0;
            for(int j=0; j<nums[i]; j++)
                if(vec[j]==false) //count the unvisited elements on the left of curr eleemnt
                    curr_glo_inv++;
            glo_inv+=curr_glo_inv;
        }
        return glo_inv==loc_inv ? true : false;
    }
};