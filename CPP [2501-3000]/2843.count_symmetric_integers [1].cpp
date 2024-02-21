class Solution {
public:
    bool isNumSymmetric(int num){
        string s = to_string(num);
        int n = s.length(); 
        if(n % 2 == 1)
            return false;
        int leftSum = 0, rightSum = 0;
        for(int i=0; i<n/2; i++)
            leftSum +=  s[i] - '0';
        for(int i=n/2; i<n; i++)
            rightSum += s[i] - '0';
        return leftSum == rightSum ? true : false;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low; i<=high; i++)
            if(isNumSymmetric(i))
                count++;
        return count;
    }
};