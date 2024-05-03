

#include <iostream>
#include <vector>
using namespace std;

void printsol(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<char>> &board, int n, int row, int col)
{

    int i = row;
    int j = col;

    // check left row
    while (j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }

    i = row;
    j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }

    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve(vector<vector<char>> &board, int n, int col)
{
    // base case
    if (col >= n)
    {
        printsol(board, n);
        return;
    }

    // 1 case

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, n, row, col))
        {
            // queen
            board[row][col] = 'Q';

            // recursive call
            solve(board, n, col + 1);

            // backtrack
            board[row][col] = '-';
        }
    }
}

int main()
{

    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    solve(board, n, col);

    return 0;
}