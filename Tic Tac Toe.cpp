#include <Windows.h>
// Using for linux sleep
//#include<unistd.h>
#include <iostream>

#include <limits>
#include <cstddef>
#include <sstream>
#include <cstdlib>
#include <ctime>
#undef max

using namespace std;

int replay();
void board();

// Each square of the board
char square[10] = { 'o',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

void waitEnter()
{
    cout << "\nPress enter to continue...";
    cin.clear();
    cin.ignore(1000, '\n');
}

int winCheck() // Are there 3 in a row?
{
    int won = 1;
    int tie = 0;
    int nextTurn = -1;

    if (square[1] == square[2] && square[2] == square[3] && square[1] != ' ')
    {
        return won;
    }
    else if (square[4] == square[5] && square[5] == square[6] && square[4] != ' ')
    {
        return won;
    }
    else if (square[7] == square[8] && square[8] == square[9] && square[7] != ' ')
    {
        return won;
    }
    else if (square[1] == square[4] && square[4] == square[7] && square[1] != ' ')
    {
        return won;
    }
    else if (square[2] == square[5] && square[5] == square[8] && square[2] != ' ')
    {
        return won;
    }
    else if (square[3] == square[6] && square[6] == square[9] && square[3] != ' ')
    {
        return won;
    }
    else if (square[1] == square[5] && square[5] == square[9] && square[1] != ' ')
    {
        return won;
    }
    else if (square[3] == square[5] && square[5] == square[7] && square[3] != ' ')
    {
        return won;
    }
    // Is the board full and you tied?
    else if (square[1] != ' ' && square[2] != ' ' && square[3] != ' ' &&
        square[4] != ' ' && square[5] != ' ' && square[6] != ' ' &&
        square[7] != ' ' && square[8] != ' ' && square[9] != ' ')
    {
        return tie;
    }
    // Else the game is still going
    else
    {
        return nextTurn;
    }
}

void board()
{
    system("cls");
    cout << "\n\t  Tic Tac Toe" << endl << endl;
    cout << "X Goes first      O Goes second" << endl << endl;
    cout << "Controls:" << endl
         << " 1 2 3" << endl
         << " 4 5 6" << endl
         << " 7 8 9" << endl << endl;

    cout << "\t" << "    |     |   " << endl;
    cout << "\t" << " " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "        " << "____|_____|____" << endl;
    cout << "\t" << "    |     |   " << endl;
    cout << "\t" << " " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "        " << "____|_____|____" << endl;
    cout << "\t" << "    |     |   " << endl;
    cout << "\t" << " " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "\t" << "    |     |   " << endl << endl << endl;
}


int main()
{
    srand(time(NULL));
    int playerTurn = 1;
    int player = 0;
    int i = -1;
    int choice = 0;
    char mark;
    char cpuMark;
    int cpuPlayer;
    char gamemode;
    bool firstRound = true;

    do
    {
        board();
        cout << "Choose a gamemode: " << endl
            << "(1) Player vs Player" << endl
            << "(2) Player vs CPU (Easy)" << endl
            << "Enter: ";
        cin >> gamemode;

        if (gamemode != '1' && gamemode != '2')
        {
            cout << "INVALID OPTION \n";
            Sleep(600);
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            break;
        }

    } while (true);
    
    do {
        
        
        playerTurn = (playerTurn % 2) ? 1 : 2;
        if (gamemode == '1')
        {
             mark = (playerTurn == 1) ? 'X' : 'O';
        }
            
        if (gamemode == '2')
        {
            while (firstRound)
            {
                do
                {

                    board();


                    cout << "Do you want to be X or O" << endl
                        << "Enter: ";
                    char input;
                    cin >> input;

                    if (input != 'X' && input != 'x' && input != 'O' && input != 'o')
                    {
                        cout << "INVALID OPTION\n";
                        Sleep(600);
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    else
                    {
                        if (input == 'X' || input == 'x')
                        {
                            player = 1;
                            mark = 'X';
                            cpuMark = 'O';
                            
                        }
                        else
                        {
                            player = 2;
                            mark = 'O';
                            cpuMark = 'X';
                            
                        }

                        input = toupper(input);
                        cpuPlayer = (input == 'O') ? 1 : 2;
                        firstRound = false;
                        break;
                    }

                } while (true);

                firstRound = false;
            }
            
            if (cpuPlayer == playerTurn)
            {
                int random = (rand() % 9) + 1;
                while (true)
                {
                    if (square[random] == ' ')
                    {
                        board();
                        square[random] = cpuMark;
                        cout << "CPU is thinking...";
                        Sleep(600);
                        i = winCheck();
                        break;
                    }
                    else
                    {
                        random = (rand() % 9) + 1;
                    }
                }
            }
        }

        board();

        if (gamemode == '1')
        {
            cout << "Player " << playerTurn << ", make your move: ";
            cin >> choice;
        }
        else if (playerTurn == player && i == -1)
        {
            cout << "Make a move: ";
            cin >> choice;
        }
        if (gamemode == '1' || cpuPlayer != playerTurn)
        {
            // Is the entered choice available?
            if (choice == 1 && square[1] == ' ')
            {
                square[1] = mark;
            }
            else if (choice == 2 && square[2] == ' ')
            {
                square[2] = mark;
            }
            else if (choice == 3 && square[3] == ' ')
            {
                square[3] = mark;
            }
            else if (choice == 4 && square[4] == ' ')
            {
                square[4] = mark;
            }
            else if (choice == 5 && square[5] == ' ')
            {
                square[5] = mark;
            }
            else if (choice == 6 && square[6] == ' ')
            {
                square[6] = mark;
            }
            else if (choice == 7 && square[7] == ' ')
            {
                square[7] = mark;
            }
            else if (choice == 8 && square[8] == ' ')
            {
                square[8] = mark;
            }
            else if (choice == 9 && square[9] == ' ')
            {
                square[9] = mark;
            }
            // If its not available
            else
            {
                playerTurn--;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "INVALID INPUT\n";
                Sleep(700);
                board();
            }
            
        }
        i = winCheck();
        playerTurn++;
        firstRound = false;
        

    } while (i == -1);

    board();
    if (i == 1)
    {
        playerTurn--;
        if (gamemode == '1')
        {
            cout << "Congradulations player " << playerTurn << " you won!" << endl;
        }
        else if (playerTurn == player)
        {
            cout << "You won!" << endl;
                
        }
        else
        {
            cout << "You lost!" << endl;
                
        }
        
        replay();
    }
    else
    {
        cout << "DRAW!" << endl;
            
        replay();
    }
    return 0;
}

int replay()
{
    
    waitEnter();
    cin.ignore(1000, '\n');
    board();
    cout << "Play again? Y/N: ";

    char input;
    cin >> input;

    if (input == 'Y' || input == 'y')
    {
        for (int i = 1; i < 10; i++) //resetting the board
        {
            square[i] = ' ';
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
