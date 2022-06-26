#include<bits/stdc++.h>
using namespace std;

int board[11][11];
bool issafe(int n,int row, int col){
//     to make sure its safe column wise
    for(int i = row ; i >= 0 ; i--){
        if(board[i][col] == 1){
            return false;
        }
    }
// to make sure its safe from left dignoal
    for(int i = row-1,j = col-1;i >= 0 && j >= 0;i--,j-- ){
        if(board[i][j]==1){
            return false;
        }
    }
// to make sure its safe from right dignoal
    for(int i = row-1 ,j = col+1;i >= 0 && j <= n;i--, j++ ){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
    
}
void nqueenhelper(int n,int row){
    if(n == row){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
    return;
    }
     for(int i=0;i<n;i++){
         if(issafe(n,row,i)){
             board[row][i]=1;
             nqueenhelper(n,row+1);
              board[row][i]=0;
         }
     }
    return ;
    }

void nqueen(int n){
    memset(board,0,11*11*sizeof(int));
    nqueenhelper(n,0);
}
int main(){
    int n;
    cin>>n;
    nqueen(n);
    // write your code here
    return 0;
}