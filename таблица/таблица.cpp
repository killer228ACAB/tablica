#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char korabli[20] [20] ;
char player_screen[20][20]; 
int main()
{
    int i, j, c, r;
    char answer;
    for (i = 0; i < 20; i++)
        for (j = 0; j < 20; j++)
        {
            if (i == 0 || i == 19 || j == 0 || j == 19)
            {
                korabli[i][j] = '$'; // матрица korabli не видна пользователю, там лежить информация о кораблях
                player_screen[i][j] = '$'; // матрица player_screen видна пользователю 
            }
            else
            {
                korabli[i][j] = ' '; // тут заполняется только границы матрицы (шобы было как поля) 
                player_screen[i][j] = ' '; // если значение не 20, то ставит пустое место 
            }
        }
    srand(time(0)); // тут корабли на рандом ставяться 
    const int points = 2; // число кораблей на поле
    int hits = 0; // попадение
    for (int k = 0; k < points; k++)
    {
        int row = 1 + rand() % 19; // ограничение для постановки кораблей на поле
        int col = 1 + rand() % 19;// ограничение для постановки кораблей на поле
        korabli[row][col] = '?'; // знак корабля ( можно любой тк пользователь не видит их)
    }
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
            cout << player_screen[i][j] << ' ';
        cout << '\n';
    }
    do
    {
        cout << "ASALAM-MALEKYM-STROKA (0-19): "; // ввод строки
        cin >> r; // запоминает значение 
        cout << "ASALAM-MALEKYM-STOLBEC (0-19): "; // ввод столбца
        cin >> c; // запоминает значение 

        if (r < 0 || r > 19 || c < 0 || c > 19) // проверят стоит ли там корабль 
        {
            cout << "ne-a\n"; // если нету - выводит нет
        }
        else if (korabli[r][c] == '?') // если там стоит ?(корабль)
        {
            cout << "popadenie\n"; // выводит - попадение
            hits++; // добалвяет +1 к хитам(попадением)
            player_screen[r][c] = '@'; // ставит на его место @(был выстрел и корабль поврежден)
        }
        else if (player_screen[r][c] == '.') // если стоит . - выстрел был
        {
            cout << "delal vistrel\n"; // выводит что был выстрел в этом место 
        }
        else if (player_screen[r][c] == '@') // если в этом месте был @(был выстрел и корабль поврежден)
        {
            cout << "podbil\n"; // выводит что был выстрел в этом место 
        }
        else
        {
            cout << "ne-a\n"; // иначе пишет нет, и ставит точку на месте выстре 
            player_screen[r][c] = '.'; // ставит точку на место выстрела
        }
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
                cout << player_screen[i][j] << ' ';
            cout << '\n';
        }
        if (hits == points) // сравнивает число попадений с кораблями 
        {
            cout << "wiiiiin\n"; // если они равны, то выводит победу
            break;
        }
        cout << "dalee??? (y/n): "; // предлогает продолжить игру 
        cin >> answer;
    } while (answer == 'y' || answer == 'Y'); // нажать Y - далее N - программа закончит программу 
    return 0;
}