#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n;
    cin>>n;
    
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    
    int q;
    cin>>q;
    
    while(q--){
        int target;
        cin>>target;
        
        // iterator to the first num >= target
        auto itr = lower_bound(nums.begin(), nums.end(), target);
        
        string isFound = *itr == target ? "Yes" : "No";
        // +1 is done to convert 0-based to 1-based index
        int idx = itr - nums.begin() + 1;
        
        cout<<isFound<<" "<<idx<<endl;
    }
     
    return 0;
}
