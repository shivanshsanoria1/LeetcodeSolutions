#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

#define INF INT_MAX

// returns majority-element and its votes (frequency)
pair<int, int> findMajorityElement(vector<int>& nums){
    int majority = INF; 
    int votes = 0;

    for(int num: nums)
    {
        // set curr element as majority element
        if(votes == 0)
            majority = num;

        if(num == majority) 
            votes++;
        else
            votes--;
    }
    
    // count the votes of majority element
    votes = 0;
    for(int num: nums)
        if(num == majority) 
            votes++;

    return votes > nums.size()/2 ? make_pair(majority, votes) : make_pair(INF, -1);
}

// --------------- END --------------- //

int main() {
    vector<int> nums = { 2,1,3,1,1,1,7,1,2,1 };
    //vector<int> nums = { 1,3,5,4,4,4 };
    
    auto [majority, votes] = findMajorityElement(nums);
    
    if(majority == INF)
        cout<<"No majority element found.";
    else
        cout<<"Majority element is "<<majority<<" with "<<votes<<" votes."<<endl;

    return 0;
}

// majority element is an element with more than n/2 frequency