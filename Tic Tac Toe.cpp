
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <limits>
#include <cstddef>
#include <sstream>
#undef max

using namespace std;

int replay();

char square[10] = { 'o','1', '2', '3', '4', '5', '6', '7', '8', '9' };

int winCheck()
{
    if (square[1] == square[2] && square[2] == square[3])
    {
        return 1; 
    }
    else if (square[4] == square[5] && square[5] == square[6])
    {
        return 1;
    }
    else if (square[7] == square[8] && square[8] == square[9])
    {
        return 1;
    }
    else if (square[1] == square[4] && square[4] == square[7])
    {
        return 1;
    }
    else if (square[2] == square[5] && square[5] == square[8])
    {
        return 1;
    }
    else if (square[3] == square[6] && square[6] == square[9])
    {
        return 1;
    }
    else if (square[1] == square[5] && square[5] == square[9])
    {
        return 1;
    }
    else if (square[3] == square[5] && square[5] == square[7])
    {
        return 1;
    }
    else if (square[1] != '1' && square[2] != '2' && square[3] != '1' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void board()
{
    system("cls");
    cout << "\n\n\n\t  Tic Tac Toe\n\n\n";
    cout << "Player 1 is X      Player 2 is O" << endl << endl << endl;
    
    cout << "\t" <<                    "    |     |   " << endl;
    cout << "\t" << " " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "        " <<              "____|_____|____" << endl;
    cout << "\t" <<                    "    |     |   " << endl;
    cout << "\t" << " " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "        " <<              "____|_____|____" << endl;
    cout << "\t" <<                    "    |     |   " << endl;
    cout << "\t" << " " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "\t" <<                    "    |     |   " << endl << endl << endl;
}


int main()
{
    int player = 1;
    int i = 0;
    int choice = 0;
    char mark;

    do {
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';
        board();

        cout << "Player " << player << ", enter a number: ";
        cin >> choice;
       

        if (choice == 1 && square[1] == '1')
        {
            square[1] = mark;
        }
        else if (choice == 2 && square[2] == '2')
        {
            square[2] = mark;
        }
        else if (choice == 3 && square[3] == '3')
        {
            square[3] = mark;
        }
        else if (choice == 4 && square[4] == '4')
        {
            square[4] = mark;
        }
        else if (choice == 5 && square[5] == '5')
        {
            square[5] = mark;
        }
        else if (choice == 6 && square[6] == '6')
        {
            square[6] = mark;
        }
        else if (choice == 7 && square[7] == '7')
        {
            square[7] = mark;
        }
        else if (choice == 8 && square[8] == '8')
        {
            square[8] = mark;
        }
        else if (choice == 9 && square[9] == '9')
        {
            square[9] = mark;
        }
        else
        {
            player--;
            if (cin.fail())
            {
                cin.clear();
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "INVALID INPUT\n";
            Sleep(600);
            board();
        }

        i = winCheck();
        player++;

    } while (i == -1);
    
    board();
    if (i == 1)
    {
        player--;
        cout << "Congradulations player " << player << " you won!" << endl;
        system("pause");
        replay();
    }
    else
    {
        cout << "DRAW!" << endl;
        system("pause");
        replay();
    }
    return 0;
}

int replay()
{
    board();

    stringstream ss;

    cout << "Play again? Y/N: ";

    char input;
    cin >> input;

    if (input == 'Y' || input == 'y')
    {
        for (int i = 1; i < 10; i++) //resetting the board
        {
            ss << i;
            char temp;
            ss >> temp;
            ss.clear();
            square[i] = temp;
        }
        
        main();
    }
    else if (input == 'N' || input == 'n')
    {
        return 0;
    }
    else
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "INVALID ANSWER \n";
        Sleep(600);
        replay();
    }

}
