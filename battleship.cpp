const int BOARD_SIZE = 5;
const int NUM_SHIPS = 3;


void printPlayerBoard(const vector<vector<char>>& board) {
    cout << "   ";
    for (int col = 0; col < BOARD_SIZE; ++col) {
        cout << col << " ";
    }
    cout << endl;
    for (int row = 0; row < BOARD_SIZE; ++row) {
        cout << row << " ";
        for (int col = 0; col < BOARD_SIZE; ++col) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}


void printComputerView(const vector<vector<char>>& board) {
    cout << "   ";
    for (int col = 0; col < BOARD_SIZE; ++col) {
        cout << col << " ";
    }
    cout << endl;
    for (int row = 0; row < BOARD_SIZE; ++row) {
        cout << row << " ";
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board[row][col] == 'X' || board[row][col] == 'O') {
                cout << board[row][col] << " ";
            }
            else {
                cout << ' ' << " "; 
            }
        }
        cout << endl;
    }
}


void placeShips(vector<vector<char>>& board, const string& playerName) {
    cout << playerName << ", enter the location of your ships." << endl;
    for (int i = 0; i < NUM_SHIPS; ++i) {
        int row, col;
        do {
            cout << "Enter the location of ship " << i + 1 << " (row and column): ";
            cin >> row >> col;
        } while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ');

        board[row][col] = 'S';
    }
}


void placeComputerShips(vector<vector<char>>& board) {
    cout << "Computer is placing its ships..." << endl;
    for (int i = 0; i < NUM_SHIPS; ++i) {
        int row, col;
        do {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } while (board[row][col] != ' ');

        board[row][col] = 'S';
    }
}


void computerMove(vector<vector<char>>& playerBoard, vector<vector<char>>& computerBoard) {
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (playerBoard[row][col] == 'X' || playerBoard[row][col] == 'O');

    cout << "Computer's move: " << row << " " << col << endl;

    if (playerBoard[row][col] == 'S') {
        cout << "Computer hit your ship!" << endl;
        playerBoard[row][col] = 'X'; 
    }
    else {
        cout << "Computer missed." << endl;
        playerBoard[row][col] = 'O'; 
    }
}

bool battleship() {
    vector<vector<char>> playerBoard(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
    vector<vector<char>> computerBoard(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));

    cout << "Welcome to Battleship!" << endl;
    cout << "There are a total of 4 rows and columns on the board, to select a coordinate type the row, press enter and then type the column. Good Luck! \n";
    placeShips(playerBoard, "Player");
    placeComputerShips(computerBoard);
    cout << "Your ships are placed. Let's start the game!" << endl;

    srand(static_cast<unsigned>(time(0)));

    int numPlayerHits = 0;
    int numComputerHits = 0;
    while (numPlayerHits < NUM_SHIPS && numComputerHits < NUM_SHIPS) {
        
        int row, col;
        cout << "Your move (row and column): ";
        cin >> row >> col;

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (computerBoard[row][col] == 'S') {
            cout << "You hit an enemy ship!" << endl;
            computerBoard[row][col] = 'X';
            numPlayerHits++;
        }
        else if (computerBoard[row][col] == ' ' || computerBoard[row][col] == 'O') {
            cout << "You missed." << endl;
            computerBoard[row][col] = 'O'; 
        }
        else {
            cout << "You already hit this location. Try again." << endl;
            continue;
        }

        if (numPlayerHits == NUM_SHIPS) {
            cout << "Congratulations! You sank all enemy ships." << endl;
            return true;
            break;
        }

        
        computerMove(playerBoard, computerBoard);

        
        cout << "Your board:" << endl;
        printPlayerBoard(playerBoard);
        cout << "Computer's view:" << endl;
        printComputerView(computerBoard);

        
        numComputerHits = 0;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (playerBoard[i][j] == 'X') {
                    numComputerHits++;
                }
            }
        }
        if (numComputerHits == NUM_SHIPS) {
            cout << "Computer sank all your ships. You lose!" << endl;
            return false;
            break;
        }
    }

    return false;
}
