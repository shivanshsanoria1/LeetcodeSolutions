class Solution {
public:
    int distributeCandies(int n, int limit) {
        int count = 0;
        for(int i=0; i<=limit; i++)
            for(int j=0; j<=min(limit, n-i); j++)
                for(int k=0; k<=min(limit, n-i-j); k++)
                    if(i + j + k == n) 
                        count++;
        return count;
    }
};