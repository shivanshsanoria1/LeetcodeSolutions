#include <bits/stdc++.h>
using namespace std;

void generateSubarrays(vector<int>& nums, vector<vector<int>>& subarrays){
    int n = nums.size();
    
    for(int i=0; i<n; i++)
    {
        vector<int> subarray;
        for(int j=i; j<n; j++)
        {
            subarray.push_back(nums[j]);
            subarrays.push_back(subarray);
        }
    }
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    
    vector<vector<int>> subarrays;
    
    generateSubarrays(nums, subarrays);
    
    for(vector<int>& subarray: subarrays)
    {
        for(int num: subarray)
            cout<<num<<" ";
        cout<<endl;
    }
    
    cout<<endl<<string(20, '-')<<endl;
    
    return 0;
}