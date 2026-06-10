class Solution {
public:
    int countTriples(int n) { // T.C.=O(n^3), S.C.=O(1)
        int count = 0;
        for(int i=5; i<=n; i++)
            for(int j=1; j<=i-1; j++)
                for(int k=j+1; k<=i; k++)
                    if(j*j + k*k == i*i)
                        count += 2;
        return count;
    }
};