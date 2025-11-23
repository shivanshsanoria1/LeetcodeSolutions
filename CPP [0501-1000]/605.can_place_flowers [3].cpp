class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) 
            return true;
        int len = flowerbed.size();
        int count = 0;
        int lastUpdatedIndex = INT_MIN;
        for(int i=0; i<len; i++)
        {
            int left = i-1 >= 0 ? flowerbed[i-1] : 0;
            if(i-1 == lastUpdatedIndex)
                left = 1;
            int right = i+1 < len ? flowerbed[i+1] : 0;
            if(flowerbed[i] == 0 && left == 0 && right == 0)
            {
                lastUpdatedIndex = i;
                count++;
                if(count == n)
                    return true;
            }
            
        }
        return false;
    }
};
// without modifying the original array