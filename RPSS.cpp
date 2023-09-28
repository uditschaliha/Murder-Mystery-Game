
enum class Choice {
    ROCK,
    PAPER,
    SCISSORS
};

enum class Result {
    WIN,
    LOSS,
    DRAW
};

class RPSGame {
public:
    RPSGame() : playerScore(0), opponentScore(0), roundsPlayed(0) {}
    Result playRound(Choice playerChoice);
    int getPlayerScore() const { return playerScore; }
    int getOpponentScore() const { return opponentScore; }
    bool isGameOver() const { return playerScore == 3 || opponentScore == 3; }

private:
    int playerScore;
    int opponentScore;
    int roundsPlayed;
};

Result RPSGame::playRound(Choice playerChoice) {
    Choice opponentChoice = static_cast<Choice>(rand() % 3);

    if (playerChoice == opponentChoice) {
        return Result::DRAW;
    } else if (
        (playerChoice == Choice::ROCK && opponentChoice == Choice::SCISSORS) ||
        (playerChoice == Choice::PAPER && opponentChoice == Choice::ROCK) ||
        (playerChoice == Choice::SCISSORS && opponentChoice == Choice::PAPER)
    ) {
        playerScore++;
        roundsPlayed++;
        return Result::WIN;
    } else {
        opponentScore++;
        roundsPlayed++;
        return Result::LOSS;
    }
}

bool RPSgame() {
    RPSGame game;

    while (!game.isGameOver()) {
        int playerChoice;
        
        while (true)
        {
            cout << "Enter your choice (0 = Rock, 1 = Paper, 2 = Scissors): ";
            cin >> playerChoice;
            if (playerChoice >= 0 && playerChoice <= 2) { break; }
        }
        
        Result roundResult = game.playRound(static_cast<Choice>(playerChoice));
        cout << "Result: ";

        switch (roundResult) {
            case Result::WIN:
                cout << "You win!" << std::endl;
                break;
            case Result::LOSS:
                cout << "You lose!" << std::endl;
                break;
            case Result::DRAW:
                cout << "It's a draw!" << std::endl;
                break;
        }

        cout << "Player Score: " << game.getPlayerScore() << std::endl;
        cout << "Duncan's Score: " << game.getOpponentScore() << std::endl;
        cout << "---------------------------" << std::endl;
    }

    if (game.getPlayerScore() > game.getOpponentScore()) {
        cout << "Congratulations! You won the game!" << std::endl; return true;
    } else {
        cout << "Game over. You lost to a 6 year old." << std::endl; return false;
    }

    return false;
}
