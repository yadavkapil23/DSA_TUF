    int f(int index,vector<int> &stones){
        if(index = 0){
            return 0;
        }

        int left = f(index-1) + abs(f[index] - f[index-1]);
        int right = INT_MAX;
        if(index>1){
            int right = f(index-2) + abs(f[index] - f[index-2]);
        }

        return min(left,right);
    }