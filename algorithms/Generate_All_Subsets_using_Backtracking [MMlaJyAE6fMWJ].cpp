#include <bits/stdc++.h>
using namespace std;

// Backtracking
void generateSubsets(vector<int>& nums, int i, vector<vector<int>>& subsets, vector<int>& subset){
    if(i == nums.size())
    {
        subsets.push_back(subset);
        return;
    }
    
    // exclude
    generateSubsets(nums, i+1, subsets, subset);
    
    // include
    subset.push_back(nums[i]);
    generateSubsets(nums, i+1, subsets, subset);
    subset.pop_back();
}

int main(){
    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> subsets;
    vector<int> subset;
    
    generateSubsets(nums, 0, subsets, subset);
    
    for(vector<int>& subset: subsets)
    {
        if(subset.empty())
            cout<<"NULL ";
        for(int num: subset)
            cout<<num<<" ";
        cout<<endl;
    }
    
    cout<<endl<<string(20, '-')<<endl;
    
    return 0;
}