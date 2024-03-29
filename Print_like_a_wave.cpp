/*https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_6&leftPanelTab=0

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here
    vector<int> ans;
    for(int col = 0; col<mCols; col++){

        if(col&1){
            //odd index wale ke liye bottom to top
            for(int row = nRows-1; row>=0; row--){
                ans.push_back(arr[row][col]);
            }
        }
        else{
            // 0 or even wale ke liye top to bottom
            for(int row = 0; row<nRows; row++){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}