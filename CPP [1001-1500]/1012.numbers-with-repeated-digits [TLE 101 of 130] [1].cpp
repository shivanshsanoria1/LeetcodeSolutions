class Solution {
private:
    bool hasRepeatedDigits(int n){
        vector<bool> visited(10, false);
        while(n > 0)
        {
            int dig = n % 10;
            if(visited[dig])
                return true;
            else
                visited[dig] = true;
            n /= 10;
        }
        return false;
    }

public:
    // T.C.=O(10*n), S.C.=O(1)
    int numDupDigitsAtMostN(int n) {
        int count = 0;
        for(int i=11; i<=n; i++)
            if(hasRepeatedDigits(i))
                count++;
        return count;
    }
};