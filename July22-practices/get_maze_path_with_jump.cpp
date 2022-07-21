// #include<iostream>
// #include<vector>
// #include<string>
#include<bits/stdc++.h>
using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
    
    if (sr==dr && sc==dc){
        vector<string> base_ans;
        base_ans.push_back("");
        return base_ans;
    }
    if (sr>=dr || sc>=dc){
        return vector<string>();
    }
    vector<string> ans;
    // Horizontal movement
    for (int jump=1;sc+jump <= dc; ++jump){
        vector<string> paths = get_maze_paths(sr, sc+jump, dr, dc);
        for(string str:paths){
            ans.push_back('h'+ to_string(jump)+str);
        }
    }

    // Vertical movement
    for (int jump=1;sr+jump <= dr; ++jump){
        vector<string> paths = get_maze_paths(sr+jump, sc, dr, dc);
        for(string str:paths){
            ans.push_back('v'+ to_string(jump)+str);
        }
    }

    // Diagonal movement
    for (int jump=1;sc+jump <= dc && sr+jump<=dr; ++jump){
        vector<string> paths = get_maze_paths(sr+jump, sc+jump, dr, dc);
        for(string str:paths){
            ans.push_back('d'+ to_string(jump)+str);
        }
    }
    return ans; 
}
    
void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = get_maze_paths(0,0,n-1,m-1);
    display(ans);

    return 0;
}