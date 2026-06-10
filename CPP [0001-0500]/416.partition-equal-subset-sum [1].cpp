class Solution {
public:
    bool subsetSum(vector<int>& nums, int sum) //BFS + visited array
    {
        int n=nums.size(), i=0;
        queue<int> q;
        q.push(sum);
        while(!q.empty())
        {
            int size= q.size();
            vector<bool> visited(sum+1,false); //visited array for each level
            while(size--)
            {
                int curr= q.front();
                q.pop();
                if(visited[curr]==true) //skip the already visited sums in that level
                    continue;
                visited[curr]=true; //mark the curr sum as visited in this level
                if(curr-nums[i] == 0) //ans found
                    return true;
                if(curr-nums[i] > 0) //including nums[i] in sum
                    q.push(curr-nums[i]);
                q.push(curr); //not including nums[i] in sum
            }
            i++;
            if(i >= n)
                break;
        }
        return false;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++)
            sum += nums[i];
        if(sum % 2 != 0) //total sum cannot be odd
            return false;
        return subsetSum(nums,sum/2);
    }
};