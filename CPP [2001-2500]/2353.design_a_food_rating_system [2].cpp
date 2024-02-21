class FoodRatings {
private:
    unordered_map<string, pair<int, string>> mp1; // food -> {rating, cuisine}
    unordered_map<string, set<pair<int, string>>> mp2; // cuisine -> { {-1*rating, food} }

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++)
        {
            mp1[foods[i]] = {ratings[i], cuisines[i]};
            mp2[cuisines[i]].insert({-1*ratings[i], foods[i]});
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
        mp2[cuisine].erase({-1*oldRating, food});
        // add the food to the new rating set
        mp2[cuisine].insert({-1*newRating, food});
    }
    
    string highestRated(string cuisine) {
        return mp2[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

/*
# -1 is multiplied in rating in mp2 so that the highest rating will
  become the smallest (most -ive) and will be at the start of the set. 
  Thus, if the rating is same, the lexicographically smaller food will be 
  closer to the start of the set than a lexicographically larger one
# if -1 is not multiplied in rating in mp2, the highest rating will be 
  at the end of the set. But if there are multiple foods with same rating
  lexicographically larger food will be closer to the end of the set
  than a lexicographically smaller one, which we don't want
*/