#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

int score = 0;

void upmove(int a[4][4])
{
    int i, j, li, ri;
    for (j = 0; j < 4; j++)
    {
        li = 0, ri = j;
        for (i = 1; i < 4; i++)
        {
            if (a[i][j] != 0)
            {
                if (a[i - 1][j] == 0 || a[i - 1][j] == a[i][j])
                {
                    if (a[li][ri] == a[i][j])
                    {
                        a[li][ri] *= 2;
                        a[i][j] = 0;
                        score += a[li][ri];
                    }
                    else
                    {
                        if (a[li][ri] == 0)
                        {
                            a[li][ri] = a[i][j];
                            a[i][j] = 0;
                        }
                        else
                        {
                            a[++li][ri] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                }
                else
                    li++;
            }
        }
    }
}

void downmove(int a[4][4])
{
    int i, j, li, ri;
    for (j = 0; j < 4; j++)
    {
        li = 3, ri = j;
        for (i = 2; i >= 0; i--)
        {
            if (a[i][j] != 0)
            {
                if (a[i + 1][j] == 0 || a[i + 1][j] == a[i][j])
                {
                    if (a[li][ri] == a[i][j])
                    {
                        a[li][ri] *= 2;
                        a[i][j] = 0;
                        score += a[li][ri];
                    }
                    else
                    {
                        if (a[li][ri] == 0)
                        {
                            a[li][ri] = a[i][j];
                            a[i][j] = 0;
                        }
                        else
                        {
                            a[--li][ri] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                }
                else
                    li--;
            }
        }
    }
}

void leftmove(int a[4][4])
{
    int i, j, li, ri;
    for (i = 0; i < 4; i++)
    {
        li = i, ri = 0;
        for (j = 1; j < 4; j++)
        {
            if (a[i][j] != 0)
            {
                if (a[i][j - 1] == 0 || a[i][j - 1] == a[i][j])
                {
                    if (a[li][ri] == a[i][j])
                    {
                        a[li][ri] *= 2;
                        a[i][j] = 0;
                        score += a[li][ri];
                    }
                    else
                    {
                        if (a[li][ri] == 0)
                        {
                            a[li][ri] = a[i][j];
                            a[i][j] = 0;
                        }
                        else
                        {
                            a[li][++ri] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                }
                else
                    ri++;
            }
        }
    }
}

void rightmove(int a[4][4])
{
    int i, j, li, ri;
    for (i = 0; i < 4; i++)
    {
        li = i, ri = 3;
        for (j = 2; j >= 0; j--)
        {
            if (a[i][j] != 0)
            {
                if (a[i][j + 1] == 0 || a[i][j + 1] == a[i][j])
                {
                    if (a[li][ri] == a[i][j])
                    {
                        a[li][ri] *= 2;
                        a[i][j] = 0;
                        score += a[li][ri];
                    }
                    else
                    {
                        if (a[li][ri] == 0)
                        {
                            a[li][ri] = a[i][j];
                            a[i][j] = 0;
                        }
                        else
                        {
                            a[li][--ri] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                }
                else
                    ri--;
            }
        }
    }
}

bool checkover(int a[4][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
                return false;
            if (i != 3 && a[i][j] == a[i + 1][j])
                return false;
            if (j != 3 && a[i][j] == a[i][j + 1])
                return false;
        }
    }
    return true;
}

int main()
{
    int a[4][4] = {0};
    char ch;
    int i, j, p, q, r, s, li, ri;
    srand(time(0));

    p = rand() % 4;
    q = rand() % 4;
    r = rand() % 4;
    s = rand() % 4;

    while (r == p && s == q)
    {
        r = rand() % 4;
        s = rand() % 4;
    }

    a[p][q] = (rand() % 2 + 1) * 2;
    a[r][s] = (rand() % 2 + 1) * 2;

    cout << "\nInstructions:";
    cout << "\nUse the 'WASD' keys to move the numbers up, left, down, and right respectively.";
    cout << "\nCombine the same numbers to reach the 2048 tile.";
    cout << "\nPress 'Q' to quit the game.";
    cout << "\n--------------------------------------------------------";
    cout << "\nPress any key to start the game.";
    cin >> ch;

    while (1)
    {
        system("cls");

        cout << "\n--------------------------------------------------------";
        cout << "\nScore: " << score;
        cout << "\n--------------------------------------------------------";
        cout << "\n\n";
        for (i = 0; i < 4; i++)
        {
            cout << setw(6);
            for (j = 0; j < 4; j++)
                cout << a[i][j] << setw(6);
            cout << "\n\n";
        }
        cout << "\n--------------------------------------------------------";

        if (checkover(a))
        {
            cout << "\n\nGame Over!\n\n";
            break;
        }

        char move;
        cout << "\n\nEnter your move (W/A/S/D): ";
        cin >> move;

        if (move == 'W' || move == 'w')
            upmove(a);
        else if (move == 'A' || move == 'a')
            leftmove(a);
        else if (move == 'S' || move == 's')
            downmove(a);
        else if (move == 'D' || move == 'd')
            rightmove(a);
        else if (move == 'Q' || move == 'q')
        {
            cout << "\n\nGame Over!\n\n";
            break;
        }

        int count = 0;
        int x, y;
        while (1)
        {
            x = rand() % 4;
            y = rand() % 4;
            if (a[x][y] == 0)
            {
                a[x][y] = (rand() % 2 + 1) * 2;
                break;
            }
            count++;
            if (count > 16)
                break;
        }
    }

    return 0;
}
