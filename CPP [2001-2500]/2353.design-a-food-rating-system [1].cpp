class FoodRatings {
private:
    unordered_map<string, pair<int, string>> mp1; // food -> {rating, cuisine}
    unordered_map<string, map<int, set<string>>> mp2; // cuisine -> {rating -> {food}}

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++)
        {
            mp1[foods[i]] = {ratings[i], cuisines[i]};
            mp2[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        // old rating of the food
        int oldRating = mp1[food].first;
        // update the old rating with the new rating
        mp1[food].first = newRating;
        // cuisine of the food
        string cuisine = mp1[food].second;
        // remove the food from the old rating set
        mp2[cuisine][oldRating].erase(food);
        // remove the old rating set if it becomes empty
        if(mp2[cuisine][oldRating].empty())
            mp2[cuisine].erase(oldRating);
        // add the food to the new rating set
        mp2[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *(mp2[cuisine].rbegin()->second).begin();
        /*
        # mp2[cuisine] : map of ratings and their corresponding foods
        # mp2[cuisine].rbegin() : iterator to the highest key of map
        # mp2[cuisine].rbegin()->second : set of highest rated foods
        # (mp2[cuisine].rbegin()->second).begin() : iterator to the 
          first element of the set of foods, ie, lexicographically smallest food
        # *(mp2[cuisine].rbegin()->second).begin() : lexicographically smallest food
          with the highest rating of the 'cuisine'
        */
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */