using namespace std;
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <limits>
#include <ctime>
#include <sstream>
#include <chrono>
#include <thread>
#include "D:\Projects\Murder Mystery\getNumber.cpp"
#include "D:\Projects\Murder Mystery\Inventory.cpp"
#include "D:\Projects\Murder Mystery\changeRoom.cpp"
#include "D:\Projects\Murder Mystery\NumberGuess.cpp"
#include "D:\Projects\Murder Mystery\quiz.cpp"
#include "D:\Projects\Murder Mystery\RPSS.cpp"
#include "D:\Projects\Murder Mystery\Battle.cpp"
#include "D:\Projects\Murder Mystery\evidence.cpp"
#include "D:\Projects\Murder Mystery\hangman.cpp"
#include "D:\Projects\Murder Mystery\jumble.cpp"
#include "D:\Projects\Murder Mystery\math_game.cpp"
#include "D:\Projects\Murder Mystery\conclusion.cpp"
#include "D:\Projects\Murder Mystery\moveGame.cpp"
#include "D:\Projects\Murder Mystery\tictactoe.cpp"
#include "D:\Projects\Murder Mystery\Achievments.cpp"
#include "D:\Projects\Murder Mystery\battleship.cpp"



bool miniGame(string room)
{
    bool win;
    win = false;

    if (room == "Kitchen") 
    { 
        cout << "You decide to investigate the kitchen and look for clues";
        win = (quiz()); 
    }

    if (room == "Bedroom") 
    { 
        cout << "You've found a secret safe behind a painting. You decide to try to unlock it";
        win = (guessNumber()); 
    }
  
    if (room == "Guest Room") 
    { 
        cout << "You don't really trust Tony Parker so you decide to investigate the room he's staying in for clues";
        win = (Hangman()); 
    }
   
    if (room == "Greenhouse") { cout << "Despite a tedious investigation, you weren't able to find anything to help progress the case \n"; }
   
    if (room == "Wine Cellar") 
    { 
        cout << "The only person here is Oscar but you decide to do a general search anyway";
        win = (mathGame()); 
    }

    if (room == "body") 
    { 
        cout << "You've decided to investigate the body to see if there's any evidence of the murderer left behind.";
        win = (jumble()); 
    }

    if (room == "child") { win = RPSgame(); }

    if (room == "Attic") 
    { 
        cout << "Even though the attic is covered in dust indicating that it's been abandoned for years, you decide to give it a shot anyway.";
        Game runGame; win = runGame.Run(); 
    } 

    if (room == "Basement")
    {
        cout << "The basement has a lot of old family heirlooms and items collected by the family over decades. Even the owners don't fully know about it's contents";
        win = (battleship());
    }

    if (room == "butler") { win = (tictactoe); }
  
    return win;
}

bool witness(const string& room, bool advance)
{
    bool convo = false;
    string response;

    if (room == "Kitchen")
    {
        if (!advance)
        {
            cout << "I've been stuck in the kitchen the entire day since I was preparing for the feast tonight. \n"
                << "You're free to look around but I don't think you'll find anything useful here. \n";
        }
        
        if (advance) 
        {
            cout << "I don't know how this bottle got here. I swear I'm innocent \n"
                << "I don't have any idea who put this here. They must've done it while I was out for my smoking break. \n";
        }
    }

    if (room == "Bedroom")
    {
        if (!advance)
        {
            cout << "You seem much sadder than people normally are when their boss dies. It seems that you're hiding something... \n"
                << "Emily: We had been working together for many years. If you find any clues here then please let me know, I'll be sure to help you. \n"
                << "Emily wishes you luck on her investigation. \n"; 
        }

        if (advance)
        {
            cout << "Well according to these documents, it seems the inheritaance issue between Oscar and Mr.Murhan Uhri was already settled so I don't think he would have any reason to murder him. \n"
                << "However, there seems to be a big deal that both Tony Parker and Murhan Uhri were fighting over. I think you should check out Tony Parker. \n";
        }
    }

    if (room == "Guest Room")
    {
        if (!advance)
        {
            cout << "Tony Parker isn't very happy to see you poking around his room."
                << "If you think I murdered him then you're not a very good detective. \n"
                << "I think you're just wasting your time here. \n";
        }

        if (advance)
        {
            cout << "You confront Tony Parker about the gun you've found \n"
                << "Tony Parker: This ins't my gun. I know you're trying to frame me! I won't let you succeed! \n"
                << "Get ready to fight Tony Parker! \n";
            return true;

        }
    }

    if (room == "child" && !advance)
    {
        cout << "There's only a kid there. \n"
            << "This is the butler's son, Duncan Robinson, he's been playing here for hours and hasn't been told about the murder. \n"
            << "Duncan: Would you like to play Rock Paper Scissors with me? \n"
            << "Spend time playing a game with Duncan? Y/N \n";
        cin >> response;

        if (response == "Y" || response == "y") {convo = miniGame("child");}
                
    }

    if (room == "child" && advance)
    {
        cout << "Duncan seems to have disappeared. Or perhaps he was never really here at all... \n"
            << "Wait, no, he's playing in mud under a tree. Best not to disturb him. \n";
    }

    if (room == "Wine Cellar")
    {
        cout << "Oscar: I'm telling you, it was the suit of armor that killed him. \n The suit of armor is a murderer, it's a killer armor \n";
        cout << "It looks like Oscar has started smoking pot again. He's not in a state to answer any questions. \n";
    }

    if (room == "Living Room")
    {
        cout << "Perhaps a game to help you relax, Detective? Y/N?"; 
        cin >> response;
        if (response == "Y" || response == "y") { convo = miniGame("butler"); }
    }

    if (room == "police")
    {
        cout << "You managed to fix the telephone with the missing part. \n"
            << "Unfortunately the pizza restaurant delivery service is closed due to the blizzard. In a fit of rage, you destroyed the telephone. \n";
    }

    if (room == "Basement" || room == "Attic")
    {
        cout << "These rooms have been abandoned for ages. If the murderer is hiding here then he's doing a very good job of concealing his tracks. \n";
    }

    return convo;
}

int actionMenu(string room)
{
    bool body = true;
    bool wire = false;
    bool cops = false;
    bool wireend = true;
    bool gun = false;
    bool tonybattle = false;
    bool end = true;
    bool butler = false;
    int ans;
    string clue;
    vector <string> roomSolves {};
    inventory inv;
    Achievement ach;
    Character player("Detective", 100, 6, 3, false);
    Character playergun ("Detective", 100, 6, 3, true);
    Character tony("Tony", 100, 8, 1, false);
    Character oscar("Boss", 100, 7, 2, false);
    Character oscar2("Armored Boss", 120, 6, 6, false);
    
    while (true)
    {
       cout << "You are currently in the " + room;
       cout << "\n";
       cout << "Would you like to: \n";
       if (body && room == "Living Room")
       {
           cout << "0. Examine the body \n";
       }
       cout << "1.Investigate the current room \n"
            << "2.Interrogate the witness \n"
            << "3.Change rooms \n"
            << "4.Check your progress \n"
            << "5.Check Inventory \n"
            << "6.Check Achievemnts \n";
       
       if (wire && (!cops))
       {
           cout << "7. Fix the telephone \n";
       }
        
       if (body) { ans = getNumber(0, 6); }
       else { ans = getNumber(1, 6); }
        
        if (ans == 0)
        {
            if (miniGame("body"))
            {
                body = false;
                clue = evidence("Weed");
                inv.addItem(clue);
                room = "Living Room";
                ach.addAchievement("Snoop Dogg: Examine Mr.Murhan Uhri's body");
            }
        }

        if (ans == 1)
        {

            if (room == "Living Room")
            {
                string check;
                cout << "Are you sure you want to end the game? Y/N ";
                cin >> check;
                if (check == "Y") { break; }
            }

            else if (room == "Attic")
            {
                if (miniGame(room))
                {
                    cout << "You don't find any evidence but you did find this odd ring that seems to be glowing. Nothing wrong in equipping it you suppose. \n";
                    ach.addAchievement("Sacred Ring: Obtain the ring from the attic");
                    player.incDef(2);
                    playergun.incDef(2);
                }
            }

            else if (room == "Basement")
            {
                if (miniGame(room))
                {
                    cout << "You don't find any evidence but you did find some strangely light gauntlets. You suddenly feel like you've increased your fighting powers by wearing them. \n";
                    ach.addAchievement("Brawler's Gauntlets: Find the gauntlets in the basement");
                    player.incDef(4);
                    playergun.incDef(4);
                }
            }

            else

            {
                cout << "Game time \n";
                if (miniGame(room))
                {
                    if (room == "Guest Room" && !gun) { gun = true; ach.addAchievement("This is America: Find Tony Parker's gun"); }
                    
                    
                    if (find(roomSolves.begin(), roomSolves.end(), room) == roomSolves.end())
                    {
                        clue = evidence(room);
                        roomSolves.push_back(room);
                        inv.addItem(clue);
                    }
                }
            }

        }

        if (ans == 2) 
        { 
            
           if (room == "Greenhouse")
           {
               if (!wireend)
               {
                   witness("child", true);
               }
               
               
               if (wireend)
               {
                   if (witness("child", false))
                   {
                       ach.addAchievement("I love beating children: Beat Duncan in rock paper scissors");
                       cout << "Duncan: I can't believe I lost! \n";
                       cout << "Thank you for playing with me. You can have this as a reward \n";
                       cout << "Do you want: \n"
                           << "1. A health potion \n"
                           << "2. A mysterious box \n"
                           << "Remember: The potion is a potion, but the box can be anything; "
                           << "It can even be a health potion! You know how useful those things are \n";

                       if (getNumber(1, 2) == 1)
                       {
                           cout << "You decide to take the potion \n";
                           inv.addItem_c("Health potion", 2);
                           wireend = false;
                       }

                       else
                       {
                           cout << "You have successfully obtained a special item. It turns out to be the missing telephone piece. \nDuncan has no idea who threw it in the greenhouse. \n";
                           wire = true;
                           wireend = false;
                           
                       }
                   }
               }

               
           }

           if (room == "Living Room")
           {
               if (!butler)
               {
                   if (witness(room, false))
                   {
                       cout << "Congratulations on your victory detective. Here's your reward. \n";
                           inv.addItem_c("Health potion", 2);
                           butler = true;
                   }

               }

               if (butler)
               {
                   cout << "Good luck on your search!";
               }
           }
           
           
           else if (find(roomSolves.begin(), roomSolves.end(), room) == roomSolves.end())
           {
               witness(room, false);
           }

           else if (find(roomSolves.begin(), roomSolves.end(), room) != roomSolves.end())
           {
               if (room == "Guest Room" && !tonybattle)
               {
                   witness(room, true);
                   if (battle(playergun,tony, inv))
                   {
                       cout << "You have defeated Tony Parker. He is now unconscious \n";
                       tonybattle = true;
                       ach.addAchievement("Catch these hands: Defeat Tony Parker");
                   }

                   else
                   {
                       ach.addAchievement("American Psycho: Lose to Tony Parker in a fight");
                       conclusion(roomSolves, 3);
                       end = false;
                       break;
                   }
               }




               else if (room == "Guest Room" && tonybattle) { cout << "There is nobody to talk to in that room \n"; }
               else { witness(room, true); }
           }
            
           
        }
      
        if (ans == 3) { room = (changeRoom(room)); }
       
        if (ans == 4)
        {
            cout << "You have solved the following rooms: \n";
            for (int i = 0; i < roomSolves.size(); i++)
            {
                cout << (i + 1) << ". " << roomSolves[i] << "\n";
            }
            cout << "Your total solves are " << roomSolves.size() << " room(s) \n";
        }

        if (ans == 5) { inv.displayInv(); inv.displayInv_C(); }

        if (ans == 6) { ach.displayAchievements(); }
        
        if (ans == 7 && (wire)) { witness("police", false); wire = false; cops = true; ach.addAchievement("Whoops: Call the food delivery service"); }
               
    }

    if (end) 
    {
        if (conclusion(roomSolves, 1) == "Mr.Murhan Uhri")
        {
            ach.addAchievement("The Ultimate Detective: Find the true murderer");
            
            if (gun)
            {
                if (battle(playergun, oscar, inv))
                {
                    
                    
                    if (battle(playergun, oscar2, inv))
                    {
                        ach.addAchievement("Shaolin Detective: Win the final boss fight");
                        conclusion(roomSolves, 2);
                    }
                }
            }

            else
            {
                if (battle(player, oscar, inv))
                {
                    cout << "Mr.Murhan Uhri has been defeated but he isn't ready to give up. \n"
                        << "He wears the suit of armor that was in the living room. \n"
                        << "Murhan Uhri: I told you this is a killer armor";

                    if (battle(player, oscar2, inv))
                    {
                        ach.addAchievement("Shaolin Detective: Win the final boss fight");
                        conclusion(roomSolves, 2);
                    }
                }
            }
        }
    }
    

 
    cout << "Here are all your achievements: \n";
    ach.displayAchievements();
    return ans;
}


int main()
{
    char name[50];
    cout << "Welcome! What is your name? ";
    cin >> name;
    cout << "Hello, " << name << "! Welcome to our Murder Mystery game, \"The Murder of Mr.Murhan Uhri\" Let's begin.\n";
    cout << "The story takes place in Mordopfer manor. You, play the role of a famous detective who was invited to the party but you have no idea who invited you. \n";
        this_thread::sleep_for(chrono::seconds(10));
        cout << "The manor has belonged to Mr.Murhan Uhri's family for generations. He's a rich businessman who's hosting a party for some of his close friends and family today. \n"
            << "But it turns out that at one point all the guests had been rather scattered and during that time Mr.Murhan Uhri was shot in his own living room!!! \n";
        this_thread::sleep_for(chrono::seconds(8));
        cout << "You don't know who killed him and everybody was in separate rooms so there's no way to find the credibilty of a witness. Only an ultimate detective could solve this case and reach the true ending. \n "
            << "Will that be you, " << name << "? Only one way to find out. \n";
        this_thread::sleep_for(chrono::seconds(8));
    cout << "You start in the Living Room.\n When you're ready to solve the mystery, return to the living room and declare the end by pressing 1 and investigating the room. Good Luck!\n";
    this_thread::sleep_for(chrono::seconds(8));

    cout << "The butler has provided some information about the characters that might be helpful. \n";
    this_thread::sleep_for(chrono::seconds(8));
    cout << "There's Oscar, the victim's brother who is usually too busy smoking weed to do other things like look for a job or stop living in a van \n"
         << "He apparently had some disputes with the victim regarding some inheritance issues so he has a possible motive. \n";
    this_thread::sleep_for(chrono::seconds(8));
    cout << "There's Tony Parker, who was Oscar's friend but they also have a heated business rivalry. He has been staying here for 2 days. \n"
         << "Tony Parker and the victim had been fighting over a big business deal lately so there was a lot of friction between them. I assume he was invited so that the two could reconcile with each other. \n";
    this_thread::sleep_for(chrono::seconds(8));
    cout << "Another guest is Emily Bennet, who was the victim's assistant and personal advisor. \n"
        << "According to some office gossip she was in love with Mr.Murhan Uhri but that's a very unreliable source. \n";
    cout << "There's the chef Steve Nash but I don't think he has much motive. \n";
    cout << "At last, there's the handsome butler David Robinson, who is definitely not suspicious at all and should be left alone. \n";
    cout << " \n (Reminder: the details are provided by the butler.) \n";
    actionMenu("Living Room");
    cout << " \n The End. Thanks for playing.";
    return 0;

}

