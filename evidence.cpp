string evidence (string room)
{
    string evi;

    if (room == "Guest Room")
    {
        cout << "You find a loose tile and see that there's something hidden under the tile. \n";
        evi = "Gun - The same type of gun that was used in the murder. It has Tony Parker's name inscribed on it. \n";
        cout << evi;
    }
    
    if (room == "Kitchen")
    {
        cout << "You find a secret bottle hidden among the kitchen ingredients \n";
        evi = "Chloroform - An empty bottle of chloroform that was hidden in the kitchen \n";
        cout << evi;
    }

    if (room == "Bedroom")
    {
        cout << "You open a secret safe behind a painting and manage to unlock it. \n";
        evi = "Documents - A list of documents that describe the victim's company situation \n";
        cout << evi;
    }

    if (room == "Wine Cellar")
    {
        cout << "You find a business card dropped under the wine boxes. \n";
        evi = "Business Card - A card that belong to the vicitm. Found in the wine cellar. \n";
        cout << evi;
    }

    if (room == "Weed")
    {
        cout << "You find something unexpected among the victim's secret pocket. \n";
        evi = "A packet of recreational drugs found in a secret pocket. Perhaps they were a gift from Oscar \n";
        cout << evi;
    }

   return evi;
}