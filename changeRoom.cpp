string changeRoom(string room)
{
    array<string, 8> roomList{"Living Room", "Kitchen", "Bedroom", "Guest Room", "Greenhouse", "Wine Cellar", "Attic", "Basement"};
    string newRoom = room;
    int map;

    while (true)
    {
        cout << "You are currently in the " << room;
        cout << "\n";
        cout << "Please select a room from the following:\n";

        for (int i = 0; i <= roomList.size() - 1; i++)
        {
            cout << i << "." << roomList[i];
            cout << "\n";
        }

        cin >> map;

        if (map < roomList.size() && map >= 0)
        {
            newRoom = roomList[map];
            cout << "You have moved to a new room";
            cout << endl;
            return newRoom;

        }
        else
        {
            cout << "Invalid entry. Please enter a number between 0 and " << roomList.size() - 1;
        }

    }
}