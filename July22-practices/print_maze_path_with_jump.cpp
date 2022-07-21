#include<iostream>
using namespace std;


void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        if (sc==dc && sr==dr){
            cout << psf <<endl;
        }
        cout<<endl;
        // Horizontal movement
        for(int jump=1; sc+jump<=dc; jump++){
            printMazePaths(sr, sc+jump, dr, dc, psf+"h"+to_string(jump));
        }
        // Vertical movement
        for(int jump=1; sr+jump<=dr; jump++){
            printMazePaths(sr+jump, sc, dr, dc, psf+"v"+to_string(jump));
        }
        // Diagonal movement
        for(int jump=1; sc+jump<=dc && sr+jump<=dr; jump++){
            printMazePaths(sr+jump, sc+jump, dr, dc, psf+"d"+to_string(jump));
        }    

}

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }