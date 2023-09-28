string shuffleWord(const string& word) {
    string shuffledWord = word;
    int length = shuffledWord.length();

    for (int i = 0; i < length - 1; ++i) {
        int j = i + rand() % (length - i);
        std::swap(shuffledWord[i], shuffledWord[j]);
    }

    return shuffledWord;
}

// Function to play the game

bool jumble() {

    // Vector of words to be used in the game
    vector<string> words = { "programming", "algorithm", "encryption", "technology", "cybersecurity" };
    const int numWords = words.size();

    // Shuffle the order of the words
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());

    int wordIndex = 0; // Index to keep track of the current word

    // Welcome message
    cout << "Welcome to Word Spaghetti!\n";
    cout << "Figure out the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n";
    cout << "Enter 'skip' to skip to the next word.\n";

    int score = 0;
    int totalGuesses = 0;

    // Main game loop
    while (wordIndex < numWords) {
        string selectedWord = words[wordIndex];

        // Shuffle the selected word
        string shuffledWord = shuffleWord(selectedWord);

        // Display the current word number
        cout << "\nWord " << (wordIndex + 1) << " of " << numWords << endl;

        // Display the jumbled word
        cout << "The jumble is: " << shuffledWord << endl;

        // Player's guess
        cout << "Your guess: ";
        string guess;
        cin >> guess;

        // Checking if the player needs a hint
        if (guess == "hint") {
            int hintLength = selectedWord.length() / 2;
            cout << "Hint: The first " << hintLength << " letters are: " << selectedWord.substr(0, hintLength) << endl;
            score -= 2;  // Deduct 2 points for using a hint
            continue;
        }

        // Checking if the player wants to quit
        if (guess == "quit") {
            cout << "Byebye loser\n";
            return false;
        }

        // Checking if the player wants to skip to the next word
        if (guess == "skip") {
            cout << "Skipping to the next word...\n";
            wordIndex++;
            continue;
        }

        // Increment the total number of guesses
        totalGuesses++;

        // Check if the player's guess is correct
        if (guess == selectedWord) {
            int wordLength = selectedWord.length();
            int pointsEarned = wordLength * 2 - totalGuesses;

            if (pointsEarned > 0) {
                score += pointsEarned;
            }

            cout << "Wohooo! You got it right, congrats.\n";
            cout << "You earned " << pointsEarned << " points for this word.\n";
            cout << "Your total score is: " << score << "\n";


            wordIndex++;
        }
        else {
            cout << "Oops, that doesn't look right. Try again?\n";
        }
    }

    cout << "You have completed all the words. Well done!\n";
    cout << "Thanks for playing, you will now move to the next phase.\n";
    if (score > 60)
    {
        return true;
    }

    return false;
}