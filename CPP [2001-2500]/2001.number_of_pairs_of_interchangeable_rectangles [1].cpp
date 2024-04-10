class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        // w/h -> freq
        unordered_map<double, int> mp;

        for(vector<int>& rectangle: rectangles)
        {
            int w = rectangle[0], h = rectangle[1];
            mp[(double)w/h]++;
        }

        long long int count = 0;

        for(auto [ratio, freq]: mp)
            if(freq > 1)
                count += (long long int)freq*(freq-1)/2;
        
        return count;
    }
};
/*
for n rectangles with same w/h ratio,
the num of possible pairs is: 
= nC2
= n! / (2!*(n-2)!)
= (n*(n-1)*(n-2)!) / (2*(n-2)!)
= (n*(n-1))/2
*/