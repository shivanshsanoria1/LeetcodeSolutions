class Solution {
public:
    int bulbSwitch(int n) {
        // count the perfect squares from 1 to n
        int i=1;
        while(i*i<=n)
            i++;
        return i-1;
    }
};