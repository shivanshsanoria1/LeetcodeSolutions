#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

// returns true if target is found in nums[] and false otherwise
bool binarySearch(vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        
        if(nums[mid] == target)
            return true;
        // search in the left-subarray
        else if(nums[mid] > target)
            right = mid - 1;
        // search in the right-subarray
        else // nums[mid] < target
            left = mid + 1;
    }
    
    return false;
}

// --------------- END --------------- //

int main() {
    // array sorted in increasing order
    vector<int> nums = {1, 3, 6, 8, 10, 10, 10, 13};
    
    int target = 10;
    bool targetFound = binarySearch(nums, target);
    
    if(targetFound)
        cout<<"Target value "<<target<<" found"<<endl;
    else
        cout<<"Target value "<<target<<" not found"<<endl;
    
    cout<<"------------------"<<endl;

    return 0;
}

// T.C.=O(log(n)), S.C.=O(1)