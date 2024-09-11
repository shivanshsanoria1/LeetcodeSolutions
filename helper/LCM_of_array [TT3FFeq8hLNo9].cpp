#include <bits/stdc++.h>
using namespace std;

#define MOD int(1e9 + 7)

// T.C.=O(n*log(m))
// n: size of nums[], m: max-val in nums[]
int findLCM(vector<int>& nums){
    long long int lcm_val = nums[0];
    // using inbuilt gcd() 
    for(int i=1; i<nums.size(); i++)
        lcm_val = ((lcm_val * nums[i]) / gcd(lcm_val, (long long int)nums[i])) % MOD;

    return lcm_val;
}

int main() {
    vector<int> nums = {1, 2, 8, 3};
    
    cout<<"LCM of nums[] = "<<findLCM(nums);

    cout<<endl<<"------------------------"<<endl;
    return 0;
}

// formula used: a * b = gcd(a, b) * lcm(a, b)