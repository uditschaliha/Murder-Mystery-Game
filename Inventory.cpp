class inventory
{
public:
    int totalItems;
    vector<string> itemList;
    map<string, int> items;

    inventory()
    {
        totalItems = 0;
        itemList = {};

    }

    void displayInv()
    {
        cout << "Current inventory: \n";
        
        if (itemList.size() == 0) {cout << "You have no items in your inventory. \n";}
        
        for (int i = 0; i < itemList.size(); i++)
        {
            cout << i + 1 << ". " << itemList[i] << "\n";
        }
    }

    void addItem(string item)
    {
        if (find(itemList.begin(), itemList.end(), item) == itemList.end())

        {
            itemList.push_back(item);
            totalItems++;
        }
    }

      void addItem_c(const string& itemName, int quantity) 
    {
        items[itemName] += quantity;
    }

    void removeItem(const string& itemName, int quantity) 
    {
        items[itemName] -= quantity;
        if (items[itemName] <= 0) 
        {
            items.erase(itemName);
        }
    }

    int getItemQuantity(const string& itemName) const 
    {
        if (items.count(itemName) == 0) 
        {
            return 0;
        }
        return items.at(itemName);
    }

    void displayInv_C() const 
    {
        cout << "Consumables: " << endl;
        for (const auto& item : items) 
        {
            cout << item.first << ": " << item.second << endl;
        }
    }


    bool useHealthPotion() {
        if (items["Health potion"] > 0) {
            items["Health potion"]--; 
            return true;
        }
        return false; 
    }


};








