
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));

    const int SIZE = 5;
    int ships[SIZE][SIZE] = {};
    char shots[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            shots[i][j] = '~';

    int count = 0;

    while (count < 3)
    {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if (ships[x][y] == 0)
        {
            ships[x][y] = 1;
            count++;
        }
    }

    int shipsLeft = 3;
    int row, col;

    cout << "=== MORSEKYY BII ===\n";
    cout << "Znajdy 3 korabli!\n";
    cout << "~ - voda, X - popadannya, O - promakh\n";

    while (shipsLeft > 0)
    {
        cout << "\n  1 2 3 4 5\n";

        for (int i = 0; i < SIZE; i++)
        {
            cout << i + 1 << " ";

            for (int j = 0; j < SIZE; j++)
                cout << shots[i][j] << " ";

            cout << "\n";
        }

        cout << "\nZadachi ryadok (1-5): ";
        cin >> row;
        cout << "Zadachi stovpets (1-5): ";
        cin >> col;
        if (row < 1 || row > 5 || col < 1 || col > 5)
        {
            cout << "Nepravylni koordynaty!\n";
            continue;
        }

        row--;
        col--;

        if (shots[row][col] != '~')
        {
            cout << "Ty vzhe strilyav syudy!\n";
            continue;
        }
        if (ships[row][col] == 1)
        {
            cout << "VLUCHANNYA! Korabel potopleno!\n";
            shots[row][col] = 'X';
            shipsLeft--;
        }
        else
        {
            cout << "Promakh! Tut tilky voda.\n";
            shots[row][col] = 'O';
        }

        cout << "Zalyshylosya korabliv: " << shipsLeft << "\n";
    }

    cout << "\nPEREMOGA! Ty znayshov vsi korabli!\n";

    return 0;
}
