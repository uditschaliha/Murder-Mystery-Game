bool guessNumber() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed the random number generator

    const int MIN_RANGE = 1; // Minimum range value
    const int MAX_RANGE = 100; // Maximum range value
    const int MAX_ATTEMPTS = 5; // Maximum number of attempts

    int secretNumber = std::rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE; // Generate the secret number
    int attemptsLeft = MAX_ATTEMPTS;

    std::cout << "Welcome to Guess the Number!" << std::endl;
    std::cout << "I have selected a number between " << MIN_RANGE << " and " << MAX_RANGE << "." << std::endl;
    std::cout << "You have " << MAX_ATTEMPTS << " attempts to guess the correct number." << std::endl;

    while (attemptsLeft > 0) {
        std::cout << "Attempts left: " << attemptsLeft << std::endl;

        int guess;
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number: " << secretNumber << std::endl;
            return true;
            break;

        }
        else if (guess < secretNumber) {
            std::cout << "Too low. ";
        }
        else {
            std::cout << "Too high. ";
        }

        if (attemptsLeft > 1) {
            if (std::abs(guess - secretNumber) <= 5) {
                std::cout << "You're close!" << std::endl;
            }
            else {
                std::cout << "Try again!" << std::endl;
            }
        }
        else {
            std::cout << "This is your last attempt!" << std::endl;
        }

        attemptsLeft--;
    }

    if (attemptsLeft == 0) {
        std::cout << "Sorry, you ran out of attempts. The correct number was: " << secretNumber << std::endl;
        return false;
    }

    std::cout << "Thank you for playing Guess the Number. Goodbye!" << std::endl;

    return false;
}