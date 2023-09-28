
string conclusion(const vector<string>& roomSolves, int j) 

{
    if (j == 1)
    {
        string murderer;

        cout << "After all this investigation, it's time for a conclusion." << endl;
        cout << "Who is the murderer? Enter the name: ";
        cin.ignore(); 
        std::getline(cin, murderer); 

        // The following code was written based on a stackOverflow post with the same problem
        size_t start = murderer.find_first_not_of(" \t");
        size_t end = murderer.find_last_not_of(" \t");
        if (start != std::string::npos && end != std::string::npos) {
            murderer = murderer.substr(start, end - start + 1);
        }
        else {
            
            murderer = "";
        }
        //stackoverflow code ends here
        cout << (murderer == "Tony Parker") << endl;
        if (murderer == "Tony Parker" && roomSolves.size() >= 3) {
            cout << "All the evidence points to Tony Parker. It all makes sense. Tony Parker has been arrested and the case is now closed... \n" << endl;
        }
        else if (murderer == "Tony Parker" && roomSolves.size() < 3)
        {
            cout << "Correct culprit, but you dind't have enough clues so the murderer got away scot-free. You are a loser. \n" << endl; 
        }
        
        else if (murderer == "Mr.Murhan Uhri" && roomSolves.size() >= 3)
        {
            cout << "Nobody can believe you. You start explaining, \"To find the culprit, you should always find the person that benefits the most.\" \n"
                << " \" By killing his brother and posing as Oscar he gets all the inheritance without any conflict. Additionally by framing Tony Parker he also eliminates his biggest business rival. This whole thing was planned by him from the start.\" \n";
            cout << "It turns out you were invited by Mr.Murhan Uhri with the sole purpose of framing Tony Parker! But even he underestimated your skills. \n";
            cout << "You've seen through all the tricks and deception and solved the mystery. You truly are the ultimate detective. But the culprit won't surrender this easily. \n";
        }
        
        else if (murderer != "Tony Parker" && murderer != "Mr.Murhan Uhri")
        {
            cout << "You selected the wrong culprit. By the time the trial was settled several of the suspects had left the country and vanished. This case will now never be solved. \n" << endl;
        }

        return murderer;
    }

    if (j == 2)
    {
        cout << "You beat his ass and handed him over to the police. You're the ultimate detective";
        return "wow";
    }

    if (j == 3)
    {
        cout << "In his mad rage, Tony Parker beat you to death. It doesn't matter if he was the culprit because after killing you he's definitely going to jail.";
    }
}

