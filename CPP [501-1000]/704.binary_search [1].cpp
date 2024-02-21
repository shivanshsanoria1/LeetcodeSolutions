class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left <= right)
        {
            int mid= left+(right-left)/2;
            if(nums[mid] == target) //found the target
                return mid;
            if(nums[mid] < target) //search in right sub-array
                left= mid+1;
            else //search in left sub-array
                right= mid-1;
        }
        return -1; //target not found
    }
};