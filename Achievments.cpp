class Achievement {
private:
    vector<string> achievements;

public:
    void addAchievement(const string& achievement)
    {
        achievements.push_back(achievement);
        cout << "You have unlocked the achievement: ";
        cout << achievement << " \n";
    }

    void displayAchievements() const {
        if (achievements.empty()) {
            cout << "No achievements unlocked yet." << endl;
        }
        else 
        {
            cout << "List of Achievements Unlocked:" << endl;
            for (const auto& achievement : achievements) 
            {
                cout << "- " << achievement << endl;
            }
        }
    }
};

