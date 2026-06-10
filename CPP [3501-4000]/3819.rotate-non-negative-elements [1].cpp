class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<int> rotateElements(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> ans(n, 0);
        // to store all the non -ive nums
        vector<int> temp1;

        // add the -ive nums in ans[] at their original position
        // add the non -ive to temp1[]
        for(int i=0; i<n; i++){
            if(nums[i] < 0)
                ans[i] = nums[i];
            else
                temp1.push_back(nums[i]);
        }

        const int t = temp1.size();
        // all nums are -ive
        if(t == 0)
            return ans;

        // reduce k mod t, since, k rotations are needed in temp1[]
        k %= t;
        // make a copy to store the rotated nums from temp1[]
        vector<int> temp2 = temp1;
        // perform k left rotations; (+t) is done to prevent -ive modulo
        for(int i=0; i<t; i++)
            temp2[(i - k + t) % t] = temp1[i];
        
        // fill the leftover empty spaces in ans[] 
        // with the rotated non -ive nums
        for(int i=0, j=0; j<t; i++)
            if(ans[i] == 0)
                ans[i] = temp2[j++];

        return ans;
    }
};