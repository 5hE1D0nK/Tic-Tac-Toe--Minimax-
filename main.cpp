#include <iostream>
#include <vector>
#include <limits>
#include <ctime>

using namespace std;

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Check game status for Human mode
int checkWin1()
{
    if (square[1] == square[2] && square[2] == square[3]) return (square[1] == 'X') ? 1 : 2;
    else if (square[4] == square[5] && square[5] == square[6]) return (square[4] == 'X') ? 1 : 2;
    else if (square[7] == square[8] && square[8] == square[9]) return (square[7] == 'X') ? 1 : 2;
    else if (square[1] == square[4] && square[4] == square[7]) return (square[1] == 'X') ? 1 : 2;
    else if (square[2] == square[5] && square[5] == square[8]) return (square[2] == 'X') ? 1 : 2;
    else if (square[3] == square[6] && square[6] == square[9]) return (square[3] == 'X') ? 1 : 2;
    else if (square[1] == square[5] && square[5] == square[9]) return (square[1] == 'X') ? 1 : 2;
    else if (square[3] == square[5] && square[5] == square[7]) return (square[3] == 'X') ? 1 : 2;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9') return 0;
    else return -1;
}

// Check game status for AI mode
int checkWin2()
{
    if (square[1] == square[2] && square[2] == square[3]) return 1;
    else if (square[4] == square[5] && square[5] == square[6]) return 1;
    else if (square[7] == square[8] && square[8] == square[9]) return 1;
    else if (square[1] == square[4] && square[4] == square[7]) return 1;
    else if (square[2] == square[5] && square[5] == square[8]) return 1;
    else if (square[3] == square[6] && square[6] == square[9]) return 1;
    else if (square[1] == square[5] && square[5] == square[9]) return 1;
    else if (square[3] == square[5] && square[5] == square[7]) return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9') return 0;
    else return -1;
}

// Draw the board
void board(int mode)
{
    cout << "\n\nTic Tac Toe Game\n";
    cout << ((mode == 1) ? "Player 1 (X) - Player 2 (O)\n\n" : "You (X) - AI (O)\n\n");
    cout << "     |       |     \n";
    cout << "  " << square[1] << "  |   " << square[2] << "   |   " << square[3] << "\n";
    cout << "_____|_______|_____\n";
    cout << "     |       |     \n";
    cout << "  " << square[4] << "  |   " << square[5] << "   |   " << square[6] << "\n";
    cout << "_____|_______|_____\n";
    cout << "     |       |     \n";
    cout << "  " << square[7] << "  |   " << square[8] << "   |   " << square[9] << "\n";
    cout << "     |       |     \n";
}

// AI Move using Minimax
int minimax(bool isMaximizing)
{
    int score = checkWin2();
    if (score == 1) return isMaximizing ? -10 : 10;  // AI wins, return +10
    if (score == 0) return 0;  // Draw

    int bestScore = isMaximizing ? numeric_limits<int>::min() : numeric_limits<int>::max();

    // Consider every possible move
    for (int i = 1; i <= 9; i++) {
        if (square[i] != 'X' && square[i] != 'O') {
            char original = square[i];
            square[i] = isMaximizing ? 'O' : 'X';  // Make the move
            int currentScore = minimax(!isMaximizing);
            square[i] = original;  // Undo the move

            // Maximize for AI (O) and minimize for player (X)
            bestScore = isMaximizing ? max(bestScore, currentScore) : min(bestScore, currentScore);
        }
    }
    return bestScore;
}

// Beginner AI move
int beginnerMove() {
    vector<int> availableMoves;
    for (int i = 1; i <= 9; i++) {
        if (square[i] != 'X' && square[i] != 'O') {
            availableMoves.push_back(i);
        }
    }
    // Pick a random move
    if (!availableMoves.empty()) {
        int index = rand() % availableMoves.size();
        return availableMoves[index];
    }
    return -1; // No moves available
}

// Intermediate AI Move
int intermediateMove() {
    vector<int> availableMoves;

    // Collect all available moves
    for (int i = 1; i <= 9; i++) {
        if (square[i] != 'X' && square[i] != 'O') {
            availableMoves.push_back(i);
        }
    }

    // Decide whether to make the best move or a random move
    int decision = rand() % 10;
    if (decision < 5) // 50% chance to make the best move
    { 
        int bestScore = numeric_limits<int>::min();
        int move = -1;

        for (int i : availableMoves) {
            char original = square[i];
            square[i] = 'O';
            int score = minimax(false);
            square[i] = original;

            if (score > bestScore) {
                bestScore = score;
                move = i;
            }
        }
        return move;
    } 
    else // 50% chance to make a random move
    { 
        int randomIndex = rand() % availableMoves.size();
        return availableMoves[randomIndex];
    }
}

// Hard AI Move (Full Minimax)
int hardMove()
{
    vector<int> availableMoves;

    for (int i = 1; i <= 9; i++) {
        if (square[i] != 'X' && square[i] != 'O') {
            availableMoves.push_back(i);
        }
    }

    int bestScore = numeric_limits<int>::min();
    int move = -1;

    for (int i : availableMoves) {
        char original = square[i];
        square[i] = 'O';
        int score = minimax(false);
        square[i] = original;

        if (score > bestScore) {
            bestScore = score;
            move = i;
        }
    }
    return move;
}

// Determine move based on difficulty
int makeMove(int level) {
    if (level == 1) 
    {
        return beginnerMove();
    } 
    else if (level == 2) 
    {
        return intermediateMove();
    }
    
    return hardMove();

}

// Coin flip to determine who starts
bool flipCoin()
{
    cout << "Select Heads or Tails to see who goes first: ";
    string start;
    cin >> start;

    cout << "\n\nFlipping a coin to decide who starts..." << endl;
    srand(static_cast<unsigned>(time(0)));
    int result = rand() % 2;

    cout << "Coin result: " << (result == 0 ? "Heads" : "Tails") << endl;
    return (start == "Heads" && result == 0) || (start == "Tails" && result == 1);
}

// Set game mode
int gameMode()
{
    cout << "\n\nChoose Game Mode\n\n";
    cout << "1 = Human vs Human\n";
    cout << "2 = Human vs AI\n";
    cout << "Game Mode: ";
    int mode;
    cin >> mode;
    return mode;
}

// Set difficulty level
int difficulty()
{
    cout << "\n\nChoose difficulty level:\n";
    cout << "1 = Beginner\n";
    cout << "2 = Intermediate\n";
    cout << "3 = Hard\n";
    cout << "Difficulty level: ";
    int level;
    cin >> level;
    return level;
}

// Human mode
int vsHuman(int i)
{
    int player = 1, choice;
    char mark;
    do
    {
        board(1);
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter the number: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';


        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice)
        {
            square[choice] = mark;
        }
        else
        {
            cout << "INVALID MOVE!";
            player--;
            cin.ignore();
            cin.get();
        }
                                                                    
        i = checkWin1();
        player = (player % 2) + 1;
    } while (i == -1);

    board(1);

    if (i == 1)
    {
        cout << "\n\aCONGRATULATIONS! PLAYER 1 (X) WINS!\n";
    }
    else if (i == 2)
    {
        cout << "\n\aCONGRATULATIONS! PLAYER 2 (O) WINS!\n";
    }
    else
    {
        cout << "\n\aGAME DRAW!\n";
    }

    return i;
}

// AI mode
int vsAI(int level, int i)
{
    int player = flipCoin() ? 1 : 2;
    cout << (player == 1 ? "You (X) start!" : "AI (O) starts!") << endl;

    int choice;
    do
    {
        board(2);
        if (player == 1)
        {
            cout << "Enter the number: ";
            cin >> choice;
            if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice)
                square[choice] = 'X';
            else
            {
                cout << "INVALID MOVE! Try again.\n";
                continue;
            }
        }
        else
        {
            cout << "AI is making a move...\n";
            choice = makeMove(level);
            square[choice] = 'O';
        }

        i = checkWin1();
        player = (player % 2) + 1;
    } while (i == -1);

    board(2);

    if (i == 1)
    {
        cout << "\n\aCONGRATULATIONS! YOU WON!\n";
    }
    else if (i == 2)
    {
        cout << "\n\aGAME OVER\n";
    }
    else
    {
        cout << "\n\aGAME DRAW!\n";
    }

    return i;
}

// Main function
int main()
{
    int mode = gameMode();
    int i;

    if (mode == 1)
    {
        i = vsHuman(i);
    }
    else if (mode == 2)
    {
        int level = difficulty();
        i = vsAI(level, i);
    }

    cin.ignore();
    cin.get();
    return 0;
}
