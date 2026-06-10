class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) 
            return true;
        int len = flowerbed.size();
        if(len == 1)
            return flowerbed[0] == 0 ? true : false;
        int count = 0;
        // check for 0th index
        if(flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            flowerbed[0] = 1;
            count++;
            if(count == n)
                return true;
        }
        for(int i=1; i<len-1; i++)
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                count++;
                if(count == n)
                    return true;
            }
        // check for last index
        if(flowerbed[len-1] == 0 && flowerbed[len-2] == 0)
        {
            flowerbed[len-1] = 1;
            count++;
            if(count == n)
                return true;
        }
        return false;
    }
};