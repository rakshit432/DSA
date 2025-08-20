#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    // To store the rank of each node
    vector<int> rank;
    
    /* To store the size of components 
    that each node belongs to */
    vector<int> size;
    
    // To store the ultimate parent of each node
    vector<int> parent;
    
public:
    
    // Constructor
    DisjointSet(int n) {
        
        // Resize the arrays
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1, 1);
        // Initialise each node with its own value
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    /* Helper function to find ultimate
    parent along with path compression */
    int findUPar(int node) {
        // Base case
        if (node == parent[node])
            return node;
            
        // Backtracking step for path compression
        return parent[node] = findUPar(parent[node]);
    }
    
    /* Function to detemine if two nodes 
    are in the same component or not */
    bool find(int u, int v) {
        // Return true if both have same ultimate parent 
        return (findUPar(u) == findUPar(v));
    }
    
    /* Function to perform union of 
    two nodes based on ranks */
    void unionByRank(int u, int v) {
        
        // Get the ultimate parents of both nodes
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        // Return if nodes already belong to the same component
        if (ulp_u == ulp_v) return;
        
        /* Otherwise, join the node to the other 
        node having higher ranks among the two */
        if (rank[ulp_u] < rank[ulp_v]) {
            // Update the parent
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            // Update the parent
            parent[ulp_v] = ulp_u;
        }
        
        /* If both have same rank, join any node to the 
        other and increment the rank of the parent node */
        else {
            // Update the parent
            parent[ulp_v] = ulp_u;
            
            // Update the rank
            rank[ulp_u]++;
        }
    }
    
    /* Function to perform union of 
    two nodes based on ranks */
    void unionBySize(int u, int v) {
        
        // Get the ultimate parents of both nodes
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        // Return if nodes already belong to the same component
        if (ulp_u == ulp_v) return;
        
        /* Otherwise, join the node belonging to the smaller 
        component to the node belonging to bigger component */
        if (size[ulp_u] < size[ulp_v]) {
            // Update the parent
            parent[ulp_u] = ulp_v;
            
            // Update the size 
            size[ulp_v] += size[ulp_u];
        }
        else {
            // Update the parent
            parent[ulp_v] = ulp_u;
            
            // Update the size
            size[ulp_u] += size[ulp_v];
        }
    }
};



class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
      
      int maxrow = 0 , maxcol = 0 ;
      int n = stones.size();
      for(auto it : stones)
      {
        maxrow = max(maxrow,it[0]);
        maxcol = max(maxcol,it[1]);
      }

      DisjointSet ds(maxrow+maxcol+1);

      unordered_map<int,int>stoneNodes ;

      for(auto &it:stones)
      {
        int noderow = it[0];
        int nodecol = it[1] + maxrow + 1 ;

        ds.unionBySize(noderow,nodecol);
        stoneNodes[noderow] = 1 ;
        stoneNodes[nodecol] = 1 ;
      }

      int k = 0 ;

      for(auto &it:stoneNodes)
      {
        if(ds.findUPar(it.first) == it.first)
        k++ ;
      }

      return n-k ;
    }
};