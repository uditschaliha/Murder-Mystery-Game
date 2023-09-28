struct Question {
    string questionText;
    string correctAnswer;
};

bool quiz()
{
    vector<Question> questions = {
        {"What is the capital of France?", "Paris"},
        {"Which planet is known as the Red Planet?", "Mars"},
        {"What is the largest ocean on Earth?", "Pacific"},
        {"Who painted the Mona Lisa?", "Leonardo da Vinci"},
        {"What is the tallest mountain in the world?", "Mount Everest"}
    };

    int score = 0;

    cout << "Welcome to the Question and Answer Game!" << endl;
    cout << "Answer the following questions." << endl;

    for (const Question& question : questions)
    {
        cout << question.questionText << endl;
        string userAnswer;
        cout << "Your answer: ";
        getline(cin, userAnswer);

        if (userAnswer == question.correctAnswer)
        {
            cout << "Correct!" << endl;
            ++score;
        }
        else
        {
            cout << "Incorrect. The correct answer is: " << question.correctAnswer << endl;
        }

        cout << endl;
    }

    cout << "Quiz finished. Your final score is: " << score << " out of " << questions.size() << endl;

    if (score>=3)
    {
        return true;
    }

    else
    {
        return false;
    }
    
}