class MovieRentingSystem {
private:
    #define LIMIT 5

    // shops[i]: movie -> price
    vector<unordered_map<int, int>> shops;
    // unrented-movie -> { {price, shop} }
    unordered_map<int, set<pair<int, int>>> availableMovies;
    // {price, shop, rented-movie}
    set<vector<int>> rentedMovies;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        this->shops.resize(n);

        for(vector<int>& entry: entries)
        {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            this->shops[shop][movie] = price;
            this->availableMovies[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        for(auto [price, shop]: availableMovies[movie])
        {
            ans.push_back(shop);
            if(ans.size() == LIMIT)
                break;
        }

        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = shops[shop][movie];

        availableMovies[movie].erase({price, shop});
        rentedMovies.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = shops[shop][movie];

        availableMovies[movie].insert({price, shop});
        rentedMovies.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for(vector<int> item: rentedMovies)
        {
            int price = item[0];
            int shop = item[1];
            int movie = item[2];

            ans.push_back({shop, movie});
            if(ans.size() == LIMIT)
                break;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */