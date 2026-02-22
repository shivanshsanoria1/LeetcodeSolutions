class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int scoreDifference(vector<int>& nums) {
        int a = 0, b = 0;
        int active = 1; // initially A is active
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 1)
                active *= -1;
            if(i % 6 == 5)
                active *= -1;

            if(active == 1)
                a += nums[i];
            else // active == -1
                b += nums[i];
        }

        return a - b;
    }
};

// active = 1 (player A active)
//         -1 (player B active)