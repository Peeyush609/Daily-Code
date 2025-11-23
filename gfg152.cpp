

class disjointset{
public:
    vector<int> rank, parent, size;
    disjointset(int n){
        rank.resize(n + 1, 0);//for handling 1 base indexing n + 1 is used
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int ultimateparent(int node){
        if(node == parent[node])    return node;

        return parent[node] = ultimateparent(parent[node]);
    }

    //tc : O(4 aplha) where alpha is approx 1 so constant time
    //tc: O(1)
    void unionbyrank(int u, int v){
        int upu = ultimateparent(u);
        int upv = ultimateparent(v);

        if(upu == upv)  return;
        if(rank[upu] > rank[upv]){
            parent[upv] = upu;
        }
        else if(rank[upv] > rank[upu]){
            parent[upu] = upv;
        }
        else{
            //both ranks are equal attach anyone to anyone
            //to whom attached increase the rank
            parent[upv] = upu;
            rank[upu]++;
        }
    }

    //union by size much more intuitive and better
    //however tc is same for both union by rank and size

    //tc : O(4 aplha) where alpha is approx 1 so constant time
    //tc: O(1)
    void unionbysize(int u, int v){
        int upu = ultimateparent(u);
        int upv = ultimateparent(v);

        if(upu == upv)  return;

        if(size[upu] > size[upv]){
            parent[upv] = upu;
            size[upu] += size[upv];
        }
        else{
            parent[upu] = upv;
            size[upv] += size[upu];
        }
    }
};

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int ns) {

        //this is nothing u just need to find the no. of components and here comp are bit diff and just subtract them for the and u will get your answer

        //see striver graphs 53 video for better understanding
        if(ns == 1)  return 0;

        int n = 0;
        int m = 0;

        for(auto it: stones){
            n = max(n, it[0]);
            m = max(m, it[1]);
        }

        disjointset ds(n + m + 1);
        //we treat each row as node like row 0 as node 0 and row 1 as node 1 and so on
        //we treat each col as node too like col 0 as node row + 1 + 0 and col 1 as node row + 1 + 1 and so on


        //remember all nodes are not used
        unordered_set<int> nodes;
        for(auto it : stones){
            int i = it[0];
            int j = it[1];

            int u = i;
            int v = n + 1 + j;

            ds.unionbysize(v, u);
            nodes.insert(u);
            nodes.insert(v);
        }

        //now all comps are created 
        //now find the no. of components
        int comps = 0;
        for(int a : nodes){
            if(ds.parent[a] == a)   comps++;
        }

        return ns - comps;
    }
};