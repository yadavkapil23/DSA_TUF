#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void solve(int i,int j,vector<vector<int>> &maze,int n,string path,vector<vector<int>> &visited,vector<string> &paths){
    if(i==n-1 && j==n-1){
        paths.push_back(path);
        return;
    }
    
    visited[i][j] = 1;
    
    //moving down.
    if( i+1 < n && maze[i+1][j] == 1 && visited[i+1][j] == 0){
        solve(i+1,j,maze,n,path + "D",visited,paths);
    }
    
    //moving up.
    if( i-1 >= 0 && maze[i-1][j] == 1 && visited[i-1][j] == 0){
        solve(i-1,j,maze,n,path+"U",visited,paths);
    }
    
    //moving left.
    if( j-1 >=0 && maze[i][j-1] == 1 && visited[i][j-1] == 0){
        solve(i,j-1,maze,n,path + "L",visited,paths);
    }
    
    //moving right.
    if( j+1 < n && maze[i][j+1] == 1 && visited[i][j+1] == 0){
        solve(i,j+1,maze,n,path+"R",visited,paths);
    }
    
    visited[i][j] = 0;
    
}
vector<string> findPath(vector<vector<int>> &maze,int n){
    vector<string> paths;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    
    if(maze[0][0] == 0){
        return paths;
    }
    
    solve(0,0,maze,n,"",visited,paths);
    return paths;
}
int main(){
    int n;
    cout << "Enter size of maze (N): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter the maze (0 = blocked, 1 = open):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    vector<string> result = findPath(maze, n);
    
    if(result.empty()){
        cout<<"No Paths fOUND.";
    }
    else{
        for(auto i : result){
            cout<<i<<endl;
        }
    }
    return 0;
}
