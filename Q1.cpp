int n = grid.size();
if(grid[0][0]==1){return -1;}
vector<vector<int>>mat(n,vector<int>(n,100000));

grid[0][0] = 0;

priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

pq.push({1,{0,0}});
mat[0][0] = 1;

while(pq.size()>0){
int dis = pq.top().first;
int i = pq.top().second.first,j = pq.top().second.second;
pq.pop();

if(i + 1<n && grid[i + 1][j]==0 && mat[i + 1][j]>dis + 1){
mat[i + 1][j] = dis + 1;
pq.push({dis + 1,{i + 1,j}});
}

if(i - 1>=0 && grid[i - 1][j]==0 && mat[i - 1][j]>dis + 1){
mat[i - 1][j] = dis + 1;
pq.push({dis + 1,{i - 1,j}});
}

if(j + 1<n && grid[i][j + 1]==0 && mat[i][j + 1]>dis + 1){
mat[i][j + 1] = dis + 1;
pq.push({dis + 1,{i,j + 1}});
}

if(j - 1>=0 && grid[i][j - 1]==0 && mat[i][j - 1]>dis + 1){
mat[i][j - 1] = dis + 1;
pq.push({dis + 1,{i,j - 1}});
}


}


}

if(mat[n - 1][n - 1]==100000){return -1;}
return mat[n - 1][n - 1];