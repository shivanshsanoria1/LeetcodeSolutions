class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int num = 1; num <= n-1; num++)
            for(int den = num + 1; den <= n; den++)
                if(gcd(num, den) == 1)
                    ans.push_back(to_string(num) + "/" + to_string(den));
        return ans;
    }
};
/*
# range of numerator: [1, n-1]
# range of denominator: [numerator + 1, n]
# to avoid duplicate fractions, the numerator and denominator 
  must not have any common divisor (other than 1), ie,
  gcd(numerator, denominator) == 1
Eg- fraction 1/3 must be included but 2/6, 3/9, 4/12 ... must be excluded
    for 2/6 gcd(2, 6) = 2
    for 3/9 gcd(3, 9) = 3
    for 4/12 gcd(4, 12) = 4
*/