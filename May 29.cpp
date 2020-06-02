There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

class Solution {
public:
    bool dfsCycle(vector<vector<int>> &edge,vector<int> &visited,int sv,int num){
        if(visited[sv] == 2){
            return false;
        }
        bool ans = true;
        visited[sv] = 2;
        //cout<<sv<<" ";
        for(int i=0;i<edge[sv].size();i++){
            if(visited[edge[sv][i]] != 1){
                ans = ans && dfsCycle(edge,visited,edge[sv][i],num);
                if(!ans)
                    return ans;
            }
        }
        visited[sv] = 1;
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> process(numCourses,0);
        vector<vector<int>> edge(numCourses);
        int k=0;
        // for(int i=0;i<numCourses;i++)
        //     edge[i] = NULL;
        for(vector<int> v:prerequisites){
            int x = v[0];
            int y = v[1];
            edge[x].push_back(y);
        }
        for(int i=0;i<numCourses;i++){
            if(process[i]==0){
                //cout<<"hey"<<endl;
                if(!dfsCycle(edge,process,i,numCourses)){
                    return false;
                }
            }
        }
        return true;
    }
};