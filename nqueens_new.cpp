#include<bits/stdc++.h>
using namespace std;
int cnt=0;

bool isSafe(int n,int row,int col,vector<vector<char>> &board)
{
    int i=0,j=0;

    //checking for the row
    for(i=0;i<col;i++)
    {
        if(board[row][i]=='Q')
        {
            return false;
        }
    }


    //Check for upper diagonal

    i=row;
    j=col;
    while(i>=0 && j>=0)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
        i--;
        j--;
    }


    //check lower diagonal
    i=row;
    j=col;
    while (i<n && j>=0)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void printsol(vector<vector<char>>& board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"=====================================\n";
}

void Nqueens(int n,vector<vector<char>> &board,int col)
{
    cnt++;
    if(col>=n)
    {
        printsol(board);
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(isSafe(n,i,col,board))
        {
           
            board[i][col] = 'Q';
            Nqueens(n, board, col + 1);
            board[i][col] = '.';
        }
    }
}

int main()
{
    int n=0;
    cout<<"Enter the number of queens : ";
    cin>>n;
    vector<vector<char>> board(n,vector<char>(n,'.'));
    cout<<"All the possible ways to place queens on "<<n<<" x "<<n<<" board without killing each other are : "<<endl;
    Nqueens(n,board,0);
    cout<<cnt<<endl;


  
}