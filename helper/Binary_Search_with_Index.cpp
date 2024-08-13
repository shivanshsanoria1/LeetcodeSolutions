#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

// returns the smallest index at which target is found and -1 otherwise
int binarySearch(vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    int idx = -1;
    
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        
        if(nums[mid] == target)
        {
            idx = mid;
            right = mid - 1;
        }
        // search in the left-subarray
        else if(nums[mid] > target)
            right = mid - 1;
        // search in the right-subarray
        else // nums[mid] < target
            left = mid + 1;
    }
    
    return idx;
}

// --------------- END --------------- //

int main() {
    // array sorted in increasing order
    vector<int> nums = {1, 3, 6, 8, 10, 10, 10, 13};
    
    int target = 10;
    int targetIdx = binarySearch(nums, target);
    
    if(targetIdx == -1)
        cout<<"Target value "<<target<<" not found"<<endl;
    else
        cout<<"Target value "<<target<<" found at index "<<targetIdx<<endl;
    
    cout<<"------------------"<<endl;

    return 0;
}

// T.C.=O(log(n)), S.C.=O(1)