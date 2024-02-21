class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) { // Greedy, T.C.=O(n*logn), S.C.=O(1)
        sort(people.begin(), people.end()); 
        int count = 0;
        int left = 0, right = people.size() - 1;
        while(left < right)
        {
            count++;
            // both left and right person can fit in boat
            if(people[right] + people[left] <= limit)
                left++;
            // only the right person can fit in boat
            right--;
        }
        return left == right ? count + 1 : count;
    }
};