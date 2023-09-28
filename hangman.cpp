
vector<string> initializeFruitList() {
    vector<string> fruitList = {
        "apple", "banana", "orange", "mango", "grape", "strawberry",
        "watermelon", "kiwi", "papaya", "pineapple", "pear", "cherry",
        "blueberry", "raspberry", "blackberry", "lemon", "plum", "avocado", "guava"
    };
    return fruitList;
}


string chooseRandomWord(const vector<string>& fruitList) {
    int randomIndex = rand() % fruitList.size();
    return fruitList[randomIndex];
}

string getMaskedWord(const string& word, const vector<bool>& guessedLetters) {
    string maskedWord;
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessedLetters[i]) {
            maskedWord += word[i];
        } else {
            maskedWord += '_';
        }
    }
    return maskedWord;
}

bool Hangman() {
    srand(static_cast<unsigned>(time(0)));

    vector<string> fruitList = initializeFruitList();
    string word = chooseRandomWord(fruitList);

    const int maxAttempts = 6;
    int attempts = 0;
    vector<bool> guessedLetters(word.length(), false);
    char guess;

    cout << "Welcome to Hangman! Guess the fruit word. Clue: It has " << word.length() << " letters." << endl;

    while (attempts < maxAttempts) {
        cout << "\nAttempts left: " << maxAttempts - attempts << endl;
        cout << "Guessed letters: ";
        for (size_t i = 0; i < guessedLetters.size(); ++i) {
            if (guessedLetters[i]) {
                cout << word[i] << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;

        cout << "Enter your guess: ";
        cin >> guess;

        bool found = false;
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == guess) {
                guessedLetters[i] = true;
                found = true;
            }
        }

        if (!found) {
            ++attempts;
            cout << "Incorrect guess!" << endl;
        }

        string maskedWord = getMaskedWord(word, guessedLetters);
        if (maskedWord == word) {
            cout << "\nCongratulations! You guessed the word: " << word << endl;
            return true;
        }
    }

    if (attempts >= maxAttempts) {
        cout << "\nGame over! The word was: " << word << endl;
        return false;
    }

    return 0;
}
