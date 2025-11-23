class Solution {
public:
    int singleNumber(vector<int>& nums) {
    map<int,int>arr;
    int result;
    for(auto i:nums)
    {
        arr[i]++; //storing frequencies of all elements;
    }
    for(auto i:arr)
    {
        if(i.second==1)
        {
            result= i.first;  //if we found frequency is 1 break out from loop;
            break;
        }
    }
    return result;  //return result;
    }
};