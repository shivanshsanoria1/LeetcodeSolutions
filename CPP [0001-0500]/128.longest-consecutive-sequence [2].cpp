class Solution {
public:
    int longestConsecutive(vector<int>& nums) { //T.C.=O(n) (as each element is visited atmost 2 times)
        unordered_set<int> s(nums.begin(),nums.end()); //put all elements in a set
        int max_len=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(s.find(nums[i]-1) != s.end()) //if left neighbour of curr element is present in set then
                continue;                    //the curr element cannot be the starting of a sub-sequence
            int curr_element=nums[i], curr_len=0;
            while(s.find(curr_element) != s.end()) //while curr element is present in set
            {
                curr_len++;
                curr_element++;
            }
            max_len=max(max_len,curr_len);
        }
        return max_len;
    }
};