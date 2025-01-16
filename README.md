# Tic Tac Toe Game with AI

This is a console-based Tic Tac Toe game written in C++ that supports two gameplay modes: **Human vs. Human** and **Human vs. AI**. The AI in the game has three difficulty levels: Beginner, Intermediate, and Hard, using strategies including the Minimax algorithm.

## Features

- **Human vs. Human Mode**: Two players can play against each other on the same device.
- **Human vs. AI Mode**: Play against an AI opponent with three levels of difficulty:
  - **Beginner**: AI picks random moves.
  - **Intermediate**: AI combines random moves and strategic decisions.
  - **Hard**: AI uses the Minimax algorithm for optimal play.
- **Dynamic Board Display**: Updates the board after every move.
- **Game Status Check**: Automatically detects wins, losses, or draws.
- **Coin Toss**: Determines who starts the game in Human vs. AI mode.

## How to Play

### 1. Compilation
Compile the code using any C++ compiler, such as g++:
```bash
g++ -o TicTacToe main.cpp
```

### 2. Execution
Run the compiled program:
```bash
./TicTacToe
```

### 3. Game Modes
You will be prompted to choose a game mode:
- Enter `1` for Human vs. Human.
- Enter `2` for Human vs. AI.

If you choose Human vs. AI, you will also select a difficulty level:
- Enter `1` for Beginner.
- Enter `2` for Intermediate.
- Enter `3` for Hard.

### 4. Gameplay
Players or the AI take turns entering the number corresponding to their chosen square (1-9). The board layout is as follows:

```
     |       |     
  1  |   2   |   3
_____|_______|_____
     |       |     
  4  |   5   |   6
_____|_______|_____
     |       |     
  7  |   8   |   9
     |       |     
```

The goal is to align three of your marks (X or O) horizontally, vertically, or diagonally before your opponent does.

### 5. Game End
The game ends when:
- A player wins.
- The board is full, resulting in a draw.

## Code Structure

- **`checkWin1` and `checkWin2`**: Check the game state for wins, losses, or draws in Human vs. Human and AI modes, respectively.
- **`board`**: Displays the game board.
- **`minimax`**: Implements the Minimax algorithm for optimal AI decision-making.
- **`beginnerMove`, `intermediateMove`, and `hardMove`**: Generate AI moves for different difficulty levels.
- **`makeMove`**: Chooses an AI move based on the selected difficulty.
- **`flipCoin`**: Simulates a coin toss to decide who starts in Human vs. AI mode.
- **`gameMode` and `difficulty`**: Handle user input for selecting game mode and AI difficulty.
- **`vsHuman` and `vsAI`**: Main gameplay loops for Human vs. Human and Human vs. AI modes.

## Dependencies

- Standard C++ library
- Random number generator (`<ctime>`)

## Future Enhancements

- Add a graphical user interface (GUI).
- Support for online multiplayer.
- Enhanced AI with learning capabilities.

## License

This project is open-source and available under the MIT License.
```
