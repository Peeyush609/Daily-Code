//2353. Design a Food Rating System

class FoodRatings {
public:
    unordered_map<string, pair<string, int>> foodInfo; 
    // food -> {cuisine, rating}

    unordered_map<string, set<pair<int, string>>> cuisineMap; 
    // cuisine -> {(-rating, food)}

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        
        // remove old entry
        cuisineMap[cuisine].erase({-oldRating, food});
        
        // insert new entry
        cuisineMap[cuisine].insert({-newRating, food});
        
        // update food info
        foodInfo[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        // top element in set = best food
        return cuisineMap[cuisine].begin()->second;
    }
};
