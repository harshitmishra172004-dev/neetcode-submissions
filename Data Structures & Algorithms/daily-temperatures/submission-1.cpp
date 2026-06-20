class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();

        vector<int> res(n);

        for(int i =0;i<n;i++){
            int count =1;
            int j=i+1;
            while(j<n){
                if(temp[j]>temp[i]){
                    break;
                }
                j++;
                count++;
            }
            count = (j==n) ? 0:count;
            res[i] = count;
        }
        return res;
    }
};
