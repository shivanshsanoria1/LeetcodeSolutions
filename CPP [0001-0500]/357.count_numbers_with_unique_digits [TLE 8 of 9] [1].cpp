class Solution {
private:
    bool hasUniqueDigits(int num) {
        vector<bool> visited(10, false);

        while(num > 0)
        {
            int dig = num % 10;
            if(visited[dig])
                return false;
            visited[dig] = true;
            num /= 10;
        }

        return true;
    }

public:
    // T.C.=O(10^n), S.C.=O(1)
    int countNumbersWithUniqueDigits(int n) {
        int lastNum = pow(10, n);
        int count = 0;
        for(int i=0; i<lastNum; i++)
            if(hasUniqueDigits(i))
                count++;
        return count;
    }
};