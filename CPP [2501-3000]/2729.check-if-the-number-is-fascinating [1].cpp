class Solution {
public:
    bool isFascinating(int n) {
        vector<bool> seen(10, false);
        int n2 = 2*n, n3 = 3*n;
        while(n > 0)
        {
            int rem = n % 10;
            if(seen[rem] || rem == 0)
                return false;
            seen[rem] = true;
            n /= 10;
        }
        while(n2 > 0)
        {
            int rem = n2 % 10;
            if(seen[rem] || rem == 0)
                return false;
            seen[rem] = true;
            n2 /= 10;
        }
        while(n3 > 0)
        {
            int rem = n3 % 10;
            if(seen[rem] || rem == 0)
                return false;
            seen[rem] = true;
            n3 /= 10;
        }
        for(int i=1; i<=9; i++)
            if(!seen[i])
                return false;
        return true;
    }
};