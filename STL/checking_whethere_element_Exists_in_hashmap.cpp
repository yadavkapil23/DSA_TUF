#include<algorithm>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//CHECK IF ENOUGH FREQUENCY IS THERE.
bool canBeFormed(string large, string pattern)
{
    unordered_map<char, int> freq;

    for(char c : large)
        freq[c]++;

    for(char c : pattern)
    {
        if(freq[c] == 0)
            return false;

        freq[c]--;
    }

    return true;
}




//CHECK ONLY UNIQUE CHARS
bool uniqueCharactersExist(string large, string pattern)
{
    unordered_map<char, int> freq;

    for(char c : large)
        freq[c]++;

    unordered_set<char> visited;

    for(char c : pattern)
    {
        if(visited.count(c))
            continue;

        visited.insert(c);

        if(freq.find(c) == freq.end())
            return false;
    }

    return true;
}


int main(){
    vector<int> v = {12,42,7,65,94};
    int n = v.size();
    unordered_map<int,int> m;
    for(int i=0 ; i<n ; i++){
        m[v[i]]++;
    }


    //THESE ARE USED TO CHECK EVERY CHARACTER EXISTS ON MAP.

    for(char c : v){
        if(m.count(c)){
            //continue. , its true , the element is there.
        }
    }

    bool exists = true;
    for (char c : v) {
       if (m.find(c) == m.end()) {
        exists = false;
        break;
    }

    return true;
}
}