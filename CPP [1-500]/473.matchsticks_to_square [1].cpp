class Solution {
public:
    bool solve(vector<int>& arr, int sideLen, vector<int>& sides, int i){
        if(i == arr.size())
            return true;
        for(int j=0; j<4; j++)
        {
            if(sides[j] + arr[i] > sideLen)
                continue;
            sides[j] += arr[i];
            if(solve(arr, sideLen, sides, i+1))
                return true;
            sides[j] -= arr[i];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) { // T.C.=O(4^n)
        int n=matchsticks.size();
        if(n < 4) // atleast 4 sticks are needed to form a square
            return false;
        int sum = 0;
        for(int stick: matchsticks)
            sum += stick;
        if(sum % 4 != 0) // all 4 sides must be of equal length 
            return false;
        int sideLen = sum/4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sides(4, 0);
        return solve(matchsticks, sideLen, sides, 0);
    }
};