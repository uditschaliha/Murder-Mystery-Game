

// Define the grid size
const int GRID_SIZE = 10;
// Define the maximum number of moves
const int MAX_MOVES = 15;

// Player class
class Player {
public:
    Player(int x, int y) : x(x), y(y) {}

    void Move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    int GetX() const { return x; }
    int GetY() const { return y; }

private:
    int x;
    int y;
};

// Game class
class Game {
public:
    Game() {
        // Initialize player
        player = new Player(0, 0);

        // Initialize obstacles and points
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                grid[i][j] = '.';
            }
        }

        srand(time(nullptr));
        int numObstacles = GRID_SIZE / 2;
        for (int i = 0; i < numObstacles; ++i) {
            int x = rand() % GRID_SIZE;
            int y = rand() % GRID_SIZE;
            grid[x][y] = 'O';
        }

        int numPoints = GRID_SIZE / 3;
        for (int i = 0; i < numPoints; ++i) {
            int x = rand() % GRID_SIZE;
            int y = rand() % GRID_SIZE;
            grid[x][y] = 'P';
        }
    }

    ~Game() {
        delete player;
    }

    bool Run() {
        int moves = 0;
        int score = 0;
        bool gameOver = false;
        while (!gameOver) {
            DisplayGrid();
            char input;
            std::cout << "Enter move (w/a/s/d, q to quit): ";
            std::cin >> input;
            std::cout << std::endl;

            if (input == 'q') {
                std::cout << "Quitting the game..." << std::endl;
                gameOver = true;
                continue;
            }

            int dx = 0, dy = 0;
            switch (input) {
            case 'w':
                dy = -1;
                break;
            case 'a':
                dx = -1;
                break;
            case 's':
                dy = 1;
                break;
            case 'd':
                dx = 1;
                break;
            default:
                std::cout << "Invalid move!" << std::endl;
                continue;
            }

            // Move player
            player->Move(dx, dy);

            // Check if player collected a point or hit an obstacle
            int playerX = player->GetX();
            int playerY = player->GetY();

            if (playerX < 0 || playerX >= GRID_SIZE || playerY < 0 || playerY >= GRID_SIZE) {
                std::cout << "You hit the wall! Game over." << std::endl;
                gameOver = true;
            }
            else {
                char cell = grid[playerX][playerY];
                if (cell == 'O') {
                    std::cout << "You hit an obstacle! Game over." << std::endl;
                    gameOver = true;
                }
                else if (cell == 'P') {
                    std::cout << "You collected a point!" << std::endl;
                    grid[playerX][playerY] = '.';
                    score++;
                }
            }

            // Increment move counter
            moves++;
            if (moves >= MAX_MOVES) {
                std::cout << "Maximum number of moves reached! Game over." << std::endl;
                gameOver = true;
            }
        }

        std::cout << "Game over!" << std::endl;
        std::cout << "Final score: " << score << std::endl;
        if (score >= 2) { return true; }
        else { return false; }
    }

private:
    void DisplayGrid() {
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (i == player->GetX() && j == player->GetY())
                    std::cout << 'X';
                else
                    std::cout << grid[i][j];
            }
            std::cout << std::endl;
        }
    }

    Player* player;
    char grid[GRID_SIZE][GRID_SIZE];
};
