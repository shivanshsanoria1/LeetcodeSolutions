#include <bits/stdc++.h>
using namespace std;

int kadanesAlgo(vector<int>& nums){
    int currMaxSubarrySum = nums[0];
    int maxSubarrySum = nums[0];
    
    for(int i=1; i<nums.size(); i++)
    {
        currMaxSubarrySum = max(currMaxSubarrySum + nums[i], nums[i]);
        maxSubarrySum = max(maxSubarrySum, currMaxSubarrySum);
    }
    
    return maxSubarrySum;
}

int main() {
    vector<int> nums = { 1, 2, 3, -2, 5 };
    int maxSubarrySum = kadanesAlgo(nums);
    
    cout<<"Max subarray sum = "<<maxSubarrySum<<endl;
    
    cout<<endl<<"-----------------"<<endl;
    
    return 0;
}

// T.C.=O(n), S.C.=O(1)