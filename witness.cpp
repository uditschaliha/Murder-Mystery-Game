bool witness(const string& room)
{
    bool convo = false;
    
    if (room == "Kitchen")
    {
        cout << "I didn't kill him";
    }

    if (room == "Bedroom")
    {
        cout << "I didn't kill him";
    }

    if (room == "Guest Room")
    {
        cout << "I didn't kill him";
    }

    if (room == "Greenhouse")
    {
        cout << "There's only a kid there \n"
            << "Steal his candy";
        convo = miniGame("child");
    }

    if (room == "Wine Cellar")
    {
        cout << "I didn't kill him";
    }

    if (room == "Living Room")
    {
        cout << "I didn't kill him";
    }

    return convo;

}