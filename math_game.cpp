
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char getRandomOperator() {
    char operators[] = {'+', '-', '*'};
    int index = rand() % 3;
    return operators[index];
}

int askMathQuestion(char op, int num1, int num2) {
    int result;
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
    }
    return result;
}

bool isInteger(const string& input) {
    stringstream ss(input);
    int value;
    return ss >> value && ss.eof();
}

bool mathGame() {
    srand(static_cast<unsigned int>(time(0)));

    int score;
    const int maxQuestions = 5;

    cout << "Welcome to the Math Game!\n";

    do {
        score = 0;
        cout << "You need to score at least 3 out of 5 to win.\n";

        for (int i = 1; i <= maxQuestions; ++i) {
            char op = getRandomOperator();
            int num1 = getRandomNumber(1, 10);
            int num2 = getRandomNumber(1, 10);

            cout << "Question " << i << ": ";
            cout << num1 << " " << op << " " << num2 << " = ";

            string userInput;
            cin >> userInput;

            if (!isInteger(userInput)) {
                cout << "Invalid input! Only integers are allowed. Try again.\n";
                i--; // Repeat the same question since it was invalid input
                continue;
            }

            int userAnswer = stoi(userInput);

            int correctAnswer = askMathQuestion(op, num1, num2);

            if (userAnswer == correctAnswer) {
                cout << "Correct!\n";
                score++;
            } else {
                cout << "Wrong! The correct answer is: " << correctAnswer << "\n";
            }
        }

        if (score >= 3) {
            cout << "Congratulations! You scored " << score << " out of " << maxQuestions << ". You win!\n"; return true;
        } else {
            cout << "Sorry, you scored " << score << " out of " << maxQuestions << ". You lose!\n"; return false;}

    } while (score < 3);

    return false;
}
