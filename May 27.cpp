Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

class Solution {
public:
    bool bipartite(vector<int> *edges,vector<bool> &visited,int sv){
        queue<int> pending;
        unordered_set<int> s[2];
        s[0].insert(sv);
        int currSet = 0;
        pending.push(sv);
        while(!pending.empty()){
            int front = pending.front();
            pending.pop();
            currSet = s[0].count(front)>0?0:1;
            visited[front] = true;
            for(int i=0;i<edges[front].size();i++){
                int elem = edges[front][i];
                if(s[currSet].count(elem)==0 && s[1- currSet].count(elem)==0){
                    s[1-currSet].insert(elem);
                    pending.push(elem);
                }
                else if(s[currSet].count(elem)>0){
                    return false;
                }
            }
        }
        return true;
    }
    bool bipartite(vector<int> *edges,int N){
        vector<bool> visited(N,false);
        bool ans = true;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                ans = ans && bipartite(edges,visited,i);
            }
        }
        return ans;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> *edges = new vector<int>[N];
        int i=0;
        for(vector<int> v:dislikes){
            int ind1 = v[0];
            int ind2 = v[1];
            edges[ind1-1].push_back(ind2-1);
            edges[ind2-1].push_back(ind1-1);
        }
        return bipartite(edges,N);
    }
};