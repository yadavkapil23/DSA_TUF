#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void my_function(vector<int> &v, int target){
    sort(v.begin(), v.end());
    bool found = false;
    
    for(int i = 0; i < v.size() - 3; i++){  //used to fix the i -> first element.
        // Skip duplicates for i
        if(i > 0 && v[i] == v[i-1]) continue;
        
        for(int j = i + 1; j < v.size() - 2; j++){ //used to fix the j , second element.
            // Skip duplicates for j
            if(j > i + 1 && v[j] == v[j-1]) continue;
            
            int left = j + 1;
            int right = v.size() - 1;
            
            while(left < right){
                int sum = v[i] + v[j] + v[left] + v[right];
                
                if(target == sum){
                    cout << "Numbers are: " << v[i] << " and " << v[j] 
                         << " and " << v[left] << " and " << v[right] << endl;
                    found = true;
                    left++;
                    right--;
                    
                    // Skip duplicates for left and right
                    while(left < right && v[left] == v[left-1]){
                        left++;
                    }
                    while(left < right && v[right] == v[right+1]){
                        right--;
                    }
                }
                else if(sum < target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
    }
    
    if(!found){
        cout << "Not found" << endl;
    }
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        cout << "Enter the " << i+1 << " element: ";
        cin >> v[i];
    }
    
    int target = 50;
    my_function(v, target);
    return 0;
}