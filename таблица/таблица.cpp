#include <iostream>
#include <random>
#include <ctime>
using namespace std;

char matrix[20][20];

int main()
{
    int i, j;
    int c, r;
    int rows, coit;
    const int y = 8;
    const int x = 10;
    char answer;

    for (i = 0; i < 20; i++)
        for (j = 0; j < 20; j++)
        {
            if (i == 0 || i == 19 || j == 0 || j == 19)
                matrix[i][j] = '$';
            else
                matrix[i][j] = ' ';
        }
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
            cout << matrix[i][j] << ' ';
        cout << '\n';
    }
    srand(time(0));
    int points = 4;
    for (int k = 0; k < points; k++) {
        int row = rand() % 19;
        int col = rand() % 19;
        matrix[row][col] = '?';
    }
    do
    {
        cout << "ASALAM MALEYKM - PRINT STROKY (0-19): ";
        cin >> r;
        cout << "ASALAM MALEYKM - PRINT STOLBEC (0-19): ";
        cin >> c;

        if (r >= 0 && r < 20 && c >= 0 && c < 20)
            matrix[r][c] = '@';
        else
            cout << "NO.\n";

        
        if (matrix[r][c] == '?')
            cout << "ASALAM MALEYKM - POPAL ";
        else
            cout << " MIMO ";

        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
                cout << matrix[i][j] << ' ';
            cout << '\n';
        }

        cout << "NEXT? (y/n): ";
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');
    return 0;
}