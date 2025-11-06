class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        if(xp == yp) return;

        if(rank[xp] < rank[yp]) {
            parent[xp] = yp;
        } else if(rank[yp] < rank[xp]) {
            parent[yp] = xp;
        } else {
            parent[yp] = xp;
            rank[xp]++;
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        DSU d(c);

        for(auto it: connections){
            int u= it[0];
            int v = it[1];

            d.unite(u, v);
        }

        for(int i = 1;i <=c; i++){
            d.find(i);
        }

        vector<set<int>> online(c +1);
        for(int i = 1;i <= c; i++){
            int p = d.find(i);
            online[p].insert(i);
        }
        
        vector<int> ans;
        for(auto it: queries){
            int u = it[0];
            int v = it[1];
            int p = d.find(v);
            
            if(u == 2){
                online[p].erase(v);
            }
            else{
                if(online[p].count(v)){
                    ans.push_back(v);
                }
                else if(online[p].empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(*online[p].begin());
                }
            }
        }

        return ans;
    }
};