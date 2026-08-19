class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, unordered_set<int>> reserved;//row->seats
        for(auto reservedSeat : reservedSeats){
            reserved[reservedSeat[0]].insert(reservedSeat[1]);
        }
        
        int unreservedRows = n - reserved.size();
        int ans = unreservedRows * 2;

        for(auto [row, seats] : reserved){
            bool corner = false;
            if(!seats.count(2) && !seats.count(3) && !seats.count(4) && !seats.count(5)){
                corner = true;
                ans++;
            }
            if(!seats.count(6) && !seats.count(7) && !seats.count(8) && !seats.count(9)){
                corner = true;
                ans++;
            }

            if(!corner && !seats.count(4) && !seats.count(5) && !seats.count(6) && !seats.count(7)){
                ans++;
            }
        }
        

        return ans;
    }
};