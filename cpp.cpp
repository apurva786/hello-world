//https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    void dfs(int ind, vector<vector<int>> graph,vector<bool> visit,vector<vector<int>> &ans)
    {
        if(ind==graph.size()-1)
        {
            ans.push_back(vector<int> (1,ind));
        }
        visit[ind]=true;
        for(int i=0;i<graph[ind].size();i++)
        {
            if(!visit[graph[ind][i]])
            {
                dfs(visit[graph[ind][i]],graph,visit,ans);
                for(int j=0;j<ans.size();j++)
                {
                    ans[j].push_back(ind);
                }
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {

        vector<vector<int>> ans;
        vector<bool> visit(graph.size(),false);
        
        dfs(0,graph,visit,ans);
        for(int i=0;i<ans.size();i++)
            reverse(ans[i].begin(),ans[i].end());
        
        return ans;
    }
};
