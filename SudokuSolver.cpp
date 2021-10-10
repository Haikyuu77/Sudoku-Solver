#include <bits/stdc++.h>
using namespace std;
class board
{
    static board *m;
    vector<vector<int>> matrix;
    board()
    {
        vector<vector<int>> b(9, vector<int>(9, 0));
        matrix.assign(b.begin(), b.end());
    }

public:
    static board *getinstance()
    {
        if (m == NULL)
        {
            m = new board();
        }
        return m;
    }
    void mat(vector<vector<int>> res)
    {
        matrix.assign(res.begin(), res.end());
    }
    bool isvalid(int x, int row, int col)
    {
        if (x == 0 || x > 9)
        {
            cout << "Invalid number!";
            return false;
        }
        for (int i = 0; i < 9; i++)
        {
            if (matrix[i][col] == x)
                return false;
        }
        for (int i = 0; i < 9; i++)
        {
            if (matrix[row][i] == x)
                return false;
        }
        int x1 = (row / 3) * 3;
        int y1 = (col / 3) * 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrix[x1 + i][y1 + j] == x)
                    return false;
            }
        }
        return true;
    }
    bool generate(int row = 0, int col = 0)
    {
        if (row == 9)
            return true;

        if (col == 9)
            return generate(row + 1, 0);

        if (matrix[row][col] != 0)
            return generate(row, col + 1);

        for (int i = 1; i <= 9; i++)
        {
            if (this->isvalid(i, row, col))
            {
                matrix[row][col] = i;
                if (generate(row, col + 1))
                    return true;
                matrix[row][col] = 0;
            }
        }
        return false;
    }
    void print_board()
    {
        for (int i = 0; i < 9; i++)
        {
            cout << endl;
            for (int j = 0; j < 9; j++)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }
};
board *board ::m = 0;

int main()
{
    vector<vector<int>> res(9, vector<int>(9, 0));
    board *b = board::getinstance();
    b->mat(res);
    b->generate();
    b->print_board();
}
/* sample unique sudoku input
{{3, 0, 6, 5, 0, 8, 4, 0, 0},
{5, 2, 0, 0, 0, 0, 0, 0, 0},
{0, 8, 7, 0, 0, 0, 0, 3, 1},
{0, 0, 3, 0, 1, 0, 0, 8, 0},
{9, 0, 0, 8, 6, 3, 0, 0, 5},
{0, 5, 0, 0, 9, 0, 6, 0, 0},
{1, 3, 0, 0, 0, 0, 2, 5, 0},
{0, 0, 0, 0, 0, 0, 0, 7, 4},
{0, 0, 5, 2, 0, 6, 3, 0, 0}}; */
