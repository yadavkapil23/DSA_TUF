#include<iostream>
#include<vector>
#include<set>
using namespace std;
bool sudoku(vector<vector<char>>& v){
    // Check rows
    for(int row = 0; row < 9; row++){
        set<char> st;
        for(int col = 0; col < 9; col++){
            if(v[row][col] == '.'){
                continue;
            }
            if(st.find(v[row][col]) != st.end()){
                return false;
            }


// When you call st.find(value), it returns an iterator:

// If the value is found → returns iterator pointing to that element
// If the value is NOT found → returns iterator pointing to st.end()

            st.insert(v[row][col]);
        }
    }


        for(int col = 0; col < 9; col++){
        set<char> st;
        for(int row = 0; row < 9; row++){
            if(v[row][col] == '.'){
                continue;
            }
            if(st.find(v[row][col]) != st.end()){
                return false;
            }
            st.insert(v[row][col]);
        }
    }

        for(int box = 0; box < 9; box++){
        set<char> st;
        for(int i = 0; i < 9; i++){
            int row = (box / 3) * 3 + i / 3;
            int col = (box % 3) * 3 + i % 3;
            
            if(v[row][col] == '.'){
                continue;
            }
            if(st.find(v[row][col]) != st.end()){
                return false;
            }
            st.insert(v[row][col]);
        }
    }
    
    return true;
}
int main(){

}