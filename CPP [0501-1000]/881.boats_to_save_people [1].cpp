class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    // Greedy
    int numRescueBoats(vector<int>& people, int limit) { 
        sort(people.begin(), people.end());

        int left = 0, right = people.size() - 1;
        int count = 0;

        while(left < right)
        {
            // both left and right person can fit in boat
            if(people[right] + people[left] <= limit)
                left++;
            // else, only the right person can fit in boat
            right--;

            count++;
        }
        
        return left == right ? 1 + count : count;
    }
};