void displayBoard(const vector<vector<char>>& board) {
    for (const vector<char>& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}


bool isBoardFull(const vector<vector<char>>& board) {
    for (const vector<char>& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}


bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}


void computerMove(vector<vector<char>>& board) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = 'O';
}

bool tictactoe() {
    srand(static_cast<unsigned>(time(0)));

    vector<vector<char>> board(3, vector<char>(3, ' '));
    int row, col;
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "You are playing against the computer." << endl;

    while (!isBoardFull(board) && !checkWin(board, 'X') && !checkWin(board, 'O')) {
        // Display the board
        cout << "Current board:" << endl;
        displayBoard(board);

        // Player's move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;

            // Check if the player won
            if (checkWin(board, currentPlayer)) {
                cout << "Congratulations! Player " << currentPlayer << " wins!" << endl;
                displayBoard(board);
                return true;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

            // Computer's move
            computerMove(board);

            // Check if the computer won
            if (checkWin(board, 'O')) {
                cout << "The computer wins! Better luck next time." << endl;
                displayBoard(board);
                return false;
            }

            // Switch player
            currentPlayer = 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    // Check if it's a tie
    if (isBoardFull(board) && !checkWin(board, 'X') && !checkWin(board, 'O')) {
        cout << "It's a tie! Good game." << endl;
        displayBoard(board);
        return false;
    }

    return false;
}