class Solution {
private:
    bool isSpecial(int n){
        vector<bool> visited(10, false);
        while(n > 0)
        {
            int dig = n % 10;
            if(visited[dig])
                return false;
            else
                visited[dig] = true;
            n /= 10;
        }
        return true;
    }

public:
    // T.C.=O(10*n), S.C.=O(1)
    int countSpecialNumbers(int n) {
        int count = 0;
        for(int i=1; i<=n; i++)
            if(isSpecial(i))
                count++;
        return count;
    }
};