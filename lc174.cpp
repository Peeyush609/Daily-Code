class Solution {
public:
    static bool comp(const vector<string>& v1, const vector<string>& v2) {
        int t1 = stoi(v1[1]);
        int t2 = stoi(v2[1]);

        if (t1 == t2) {
            return v1[0] == "OFFLINE";  // OFFLINE events should come first
        }
        return t1 < t2;  // Sort by timestamp
    }

    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> mentions(n, 0); // Store number of mentions for each user
        unordered_set<int> onlineusers; // Store online users
        unordered_map<int, int> offlineusers; // Store offline users (user -> timestamp)

        // Initially, all users are online
        for (int i = 0; i < n; i++) {
            onlineusers.insert(i);
        }

        // Sort events based on timestamp
        sort(events.begin(), events.end(), comp);

        for(auto &event : events){
            string s1 = event[0]; // Type of event
            string s2 = event[1]; // Timestamp
            string s3 = event[2]; // Mentions string or offline user ID

            int time = stoi(s2); // Convert timestamp to integer

            // Check if any offline users should come back online
            vector<int> toRestore;
            for(auto &[user, offlineTime] : offlineusers){
                if(offlineTime + 60 <= time){
                    toRestore.push_back(user);
                }
            }
            // Restore users who were offline
            for(int user : toRestore){
                onlineusers.insert(user);
                offlineusers.erase(user);
            }

            if(s1 == "MESSAGE"){
                // If all users are mentioned
                if(s3 == "ALL"){
                    for(int i = 0; i < n; i++){
                        mentions[i]++;
                    }
                }
                // If only online users are mentioned
                else if(s3 == "HERE"){
                    for(int x : onlineusers){
                        mentions[x]++;
                    }
                }
                // Particular users are mentioned
                else{
                    stringstream ss(s3);
                    string token;
                    while(ss >> token){
                        if(token.substr(0, 2) == "id"){
                            int user = stoi(token.substr(2)); // Extract user ID
                            mentions[user]++;
                        }
                    }
                }
            }
            else{ // OFFLINE event
                int user = stoi(s3);
                offlineusers[user] = time; // Store offline time
                onlineusers.erase(user);
            }
        }

        return mentions;
    }
};