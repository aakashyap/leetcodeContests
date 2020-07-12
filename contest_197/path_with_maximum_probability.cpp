/*

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
 

Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.

*/


class Solution {
    vector<vector<pair<int,double>>> adj;
    vector<bool> isVisited;
    vector<double> prob;
    double util(int start,int stop) {
        queue<int> q;
        q.push(start);
        prob[start] = 1;
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            for(int i=0;i<adj[temp].size();++i) {
                if (prob[adj[temp][i].first] < prob[temp]*adj[temp][i].second) {
                    prob[adj[temp][i].first] = prob[temp]*adj[temp][i].second;
                    q.push(adj[temp][i].first);   
                }
            }
        }
        return prob[stop];
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int size = edges.size();
        adj.resize(n);
        isVisited.resize(n,false);
        prob.resize(n,0.0);
        for(int i = 0;i<size;++i) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        return util(start,end);
    }
};

// SOLUTION 1
/* DFS WONT WORK HERE
class Solution {
    vector<vector<pair<int,double>>> adj;
    vector<bool> isVisited;
    vector<vector<double>> dp;
    double util(int start,int stop,double prob) {
        cout<<start<<","<<stop<<endl;
        if (start == stop) return prob;
        cout<<dp[start][stop]<<endl;
        if (dp[start][stop] != -1.0) return dp[start][stop];
        isVisited[start] = true;
        double max_ = -1.0;
        //cout<<"here2"<<endl;
        for(int i=0;i<adj[start].size();++i) {
            if (!isVisited[adj[start][i].first]) {
                //cout<<adj[start][i].first<<endl;
                cout<<prob*adj[start][i].second<<endl;
                max_ = max(max_,util(adj[start][i].first,stop,prob*adj[start][i].second));
            }
        }
        //cout<<"here3"<<endl;
        isVisited[start] = false;
        dp[start][stop] = max_ < 0 ? 0:max_;
        return dp[start][stop];
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        cout<<"**************"<<endl;
        int size = edges.size();
        adj.resize(n);
        isVisited.resize(n,false);
        dp.resize(n,vector<double>(n,-1.0));
        for(int i = 0;i<size;++i) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        util(start,end,1);
        return dp[start][end];
    }
};
*/