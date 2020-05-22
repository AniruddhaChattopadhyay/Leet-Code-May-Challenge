Count Square Submatrices with All Ones
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1



class Solution {
public:
    void print(vector<int> v){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    int countSquares(vector<vector<int>>& matrix) {
        //O(N) space and O(N*N) time complexity
        vector<int> prev(matrix[0].size(),0);
        int sum=0;
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i] == 1){
                prev[i] = 1;
                sum+=1;
            }
        }   
        print(prev);
        for(int i=1;i<matrix.size();i++){
            int curr = matrix[i][0];
            sum+=curr;
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j] == 1){
                    int arr[] = {prev[j-1],prev[j],curr};
                    prev[j-1] = curr;
                    curr = 1 + (*min_element(arr,arr+3));
                    sum+=curr;   
                }
                else{
                    prev[j-1] = curr;
                    curr = 0;
                    //prev[j-1] = curr;
                }
            }
            prev[matrix[0].size() -1] = curr; 
            print(prev);
        }
        return sum;
        }
};

//O(N*N) space and O(N*N) time complexity
        // vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        // int sum = 0;
        // for(int i=0;i<matrix.size();i++){
        //     if(matrix[i][0] == 1){
        //         dp[i][0] = 1;
        //         sum+=1;
        //     }
        // }
        // for(int i=1;i<matrix[0].size();i++){
        //     if(matrix[0][i] == 1){
        //         dp[0][i] = 1;
        //         sum+=1;
        //     }
        // }
        // for(int i=1;i<matrix.size();i++){
        //     for(int j=1;j<matrix[0].size();j++){
        //         if(matrix[i][j] == 1){
        //             int arr[] = {dp[i-1][j-1],dp[i-1][j],dp[i][j-1]};
        //             dp[i][j] = 1 + (*min_element(arr,arr+3));
        //             sum+=dp[i][j];
        //         }
        //     }
        // }
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         cout<<dp[i][j];
        //     }
        //     cout<<endl;
        // }
        // return sum;
//     }
// };