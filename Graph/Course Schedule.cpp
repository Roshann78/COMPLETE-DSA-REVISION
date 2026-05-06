class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>in(n);
        for(auto i:pre){
            adj[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!in[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto i:adj[node]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        if(topo.size()!=n){
            return 0;
        }
        return 1;
    }
};