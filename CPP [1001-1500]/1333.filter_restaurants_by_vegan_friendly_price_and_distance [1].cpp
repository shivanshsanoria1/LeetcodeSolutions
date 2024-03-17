class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        // {rating, id}
        vector<pair<int, int>> filteredRestaurants;

        for(vector<int>& restaurant: restaurants)
        {
            int id = restaurant[0];
            int rating = restaurant[1];
            int isVeganFriendly = restaurant[2];
            int price = restaurant[3];
            int distance = restaurant[4];

            // skip the restaurant
            if((!isVeganFriendly && veganFriendly) || price > maxPrice || distance > maxDistance)
                continue;

            filteredRestaurants.push_back({rating, id});
        }

        // sorts in increasing order of rating and in 
        // increasing order of id (if rating is the same) 
        sort(filteredRestaurants.begin(), filteredRestaurants.end());

        vector<int> ans;
        for(int i=filteredRestaurants.size()-1; i>=0; i--)
            ans.push_back(filteredRestaurants[i].second);
        return ans;
    }
};