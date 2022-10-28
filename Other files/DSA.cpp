#include <bits/stdc++.h>
using namespace std;

// The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.

void displayBoard(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isSafe(int board[][20], int n, int x, int y)
{
    // Checking Column
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
            return false;
    }
    // Checking Left Diagonal
    int i = x;
    int j = y;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }

    // Checking Right Diagonal
    i = x;
    j = y;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j++;
    }
    return true;
}

bool solve(int n, int board[][20], int i)
{
    // Base Case
    if (i == n)
    {
        displayBoard(n, board);
        return true;
    }
    // Recursive Case
    // Trying to place queen in every row
    for (int j = 0; j < n; j++)
    {
        // Checking whether current position is safe or not
        if (isSafe(board, n, i, j))
        {
            board[i][j] = 1;
            if (solve(n, board, i + 1))
            {
                return true;
            }
            // Backtracking
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    // Change dimensions of board according to requirement
    int board[20][20] = {0};
    int n;
    cout << "Enter the number of queens to be placed \n";
    cin >> n;
    if (n > 20)
    {
        cout << "Cannot place more than 20 (board size) \n";
        return 0;
    }
    solve(n, board, 0);
}
