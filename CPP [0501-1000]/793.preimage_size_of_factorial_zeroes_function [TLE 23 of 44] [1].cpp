class Solution {
private:
    int getFactorialZeros(int num) {
        int count = 0;
        int pow5 = 5;

        while(num / pow5 > 0)
        {
            count += num / pow5;
            pow5 *= 5;
        }

        return count;
    }

public:
    int preimageSizeFZF(int k) {
        int count = 0;
        
        for(int num = 0; num <= INT_MAX; num++)
        {
            int zerosCount = getFactorialZeros(num);

            if(zerosCount > k)
                break;
            else if(zerosCount == k)
                count++;
        }

        return count;
    }
};