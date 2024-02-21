class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { // T.C.=O(n) , S.C.=O(n)
        vector<int> result;
        unordered_map<int,int> hash_table;
        for(int i=0; i<nums.size(); i++)
        {
            int x= target- nums.at(i);
            if(hash_table.find(x) != hash_table.end())  // if x is present in hash table
            {
                result.push_back(i);  
                result.push_back(hash_table.find(x)->second);
                break;
            }
            else
                hash_table[nums.at(i)]=i;
        }
        return result;
    }
};