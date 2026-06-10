class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) 
            return true;
        int count = 0;
        int len = flowerbed.size();
        for(int i=0; i<len; i++)
        {
            int left = i-1 >= 0 ? flowerbed[i-1] : 0;
            int right = i+1 < len ? flowerbed[i+1] : 0;
            if(flowerbed[i] == 0 && left == 0 && right == 0)
            {
                flowerbed[i] = 1;
                count++;
                if(count == n)
                    return true;
            }
            
        }
        return false;
    }
};