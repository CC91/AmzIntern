// Paint House

class Solution {
public: 
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size(), r =0 , g = 0, b = 0;
        for (int i=0; i<n; i++) {
        	int tr = r, tg = g, tb = b;
        	r = costs[i][0]+min(tg, tb);
        	g = costs[i][0]+min(tr, tb);
        	b = costs[i][0]+min(tr, tg);
        }
        return min(r, min(g, b));
    } 
};

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        for (int i=0; i<costs.size(); i++) {
        	costs[i][0] = costs[i][0]+min(costs[i-1][2], costs[i-1][2]);
        	costs[i][1] = costs[i][1]+min(costs[i-1][0], costs[i-1][2]);
        	costs[i][2] = costs[i][2]+min(costs[i-1][0], costs[i-1][1]);
        }
        return min(costs[costs.size-1][0], min(costs[costs.size-1][1], costs[costs.size-1][2]));
    } 
};