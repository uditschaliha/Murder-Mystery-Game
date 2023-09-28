int getNumber(int minNum, int maxNum) 
{
    int number;
    bool validInput = false;

    while (!validInput) {
        cin >> number;
        
        if (cin.fail()) {
            cout << "Invalid input! Please enter a valid integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (number < minNum || number > maxNum) {
            cout << "Invalid input! Please enter a number between " << minNum << " and " << maxNum << ".\n";
        }
        else {
            validInput = true;
        }
    }

    return number;
}