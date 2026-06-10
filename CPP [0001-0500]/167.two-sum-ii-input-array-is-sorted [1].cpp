class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) { //T.C.=O(n) , S.C.=O(1)
        vector<int> ans;
        int n=numbers.size();
        int left=0, right=n-1;
        while(left < right)
        {
            if(numbers[left]+numbers[right] == target)
            {
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }
            else if(numbers[left]+numbers[right] < target)
                left++;
            else
                right--;
        }
        return ans;
    }
};