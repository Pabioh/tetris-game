#include <iostream>
if (fullLine)
{
    board.erase(board.begin() + i);
    board.insert(board.begin(), vector<int>(WIDTH, 0));
    i++;
}
}
}

void rotateTetromino()
{
    vector<vector<int>> rotated;
    int rows = currentTetromino.shape.size();
    int cols = currentTetromino.shape[0].size();

    for (int j = 0; j < cols; j++)
    {
        vector<int> newRow;
        for (int i = rows - 1; i >= 0; i--)
        {
            newRow.push_back(currentTetromino.shape[i][j]);
        }
        rotated.push_back(newRow);
    }

    if (canMove(0, 0))
    {
        currentTetromino.shape = rotated;
    }
}

int main()
{
    srand(time(0));
    spawnTetromino();

    while (true)
    {
        drawBoard();

        if (_kbhit())
        {
            char key = _getch();
            if (key == 'a' && canMove(-1, 0))
                currentTetromino.x--;
            if (key == 'd' && canMove(1, 0))
                currentTetromino.x++;
            if (key == 's' && canMove(0, 1))
                currentTetromino.y++;
            if (key == 'w')
                rotateTetromino();
        }

        if (canMove(0, 1))
        {
            currentTetromino.y++;
        }
        else
        {
            placeTetromino();
            clearLines();
            spawnTetromino();

            if (!canMove(0, 0))
            {
                cout << "Game Over!" << endl;
                break;
            }
        }

        Sleep(100);
    }

    return 0;
}
