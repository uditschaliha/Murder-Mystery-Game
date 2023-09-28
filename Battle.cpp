class Character {
public:
    string name;
    int health;
    int maxHealth;
    int attackPower;
    int defense;
    bool hasGun;

    Character(const string& name, int health, int attackPower, int defense, bool gun)
        : name(name), health(health), maxHealth(health), attackPower(attackPower), defense(defense), hasGun(gun) {}

    int calculateDamage() {
        
        double randomFactor = (rand() % 41 + 80) / 100.0; 
        return static_cast<int>(attackPower * randomFactor);
    }

    void takeDamage(int damage) 
    {
        health -= max(0, damage - defense);
    }

    bool isAlive() const {
        return health > 0;
    }

    bool useGun() {
        if (hasGun) {
            hasGun = false;
            return true; 
        }
        return false; 
    }

    void heal(int amount) 
    {        
        health = min(health + amount, maxHealth);
    }

    void displayHealth()
    {
        cout << name << " has " << health << " HP left \n";
    }

    void incDef(int x) { defense += x; }
    void incAtt(int y) { attackPower += y; }
};

string getAttackChoice() {
    string choice;
    cout << "Choose your attack (punch, kick, gun, heal): ";
    cin >> choice;
    return choice;
}


bool battle(Character& player, Character& opponent, inventory& playerInventory) {
    srand(static_cast<unsigned int>(time(nullptr))); 

    while (player.isAlive() && opponent.isAlive()) {
        
        string playerAttack = getAttackChoice();
        int playerDamage = 0;

        if (playerAttack == "punch") 
        {
            playerDamage = player.calculateDamage();
            cout << player.name << " punches " << opponent.name << " for " << playerDamage << " damage.\n";
        } 
        else if (playerAttack == "kick") 
        {
            playerDamage = player.calculateDamage();
            cout << player.name << " kicks " << opponent.name << " for " << playerDamage << " damage.\n";
        } 
        else if (playerAttack == "gun") 
        {
            if (player.useGun()) 
            {
                playerDamage = player.calculateDamage() * 15; 
                cout << player.name << " uses a gun on " << opponent.name << " for " << playerDamage << " damage.\n";
            } 
            else 
            {
                cout << player.name << " has already used the gun and can't use it again.\n";
                continue; 
            }
        } 
        else if (playerAttack == "heal") 
        {
            if (playerInventory.useHealthPotion()) 
            {
                player.heal(20); 
                cout << player.name << " uses a healing potion and heals for 20 HP. Current HP: " << player.health << ".\n";
            } 
            else 
            {
                cout << "You don't have any health potions in your inventory.\n";
            }
        } 
        else 
        {
            cout << "Invalid attack choice. Try again.\n";
            continue; 
        }

        opponent.takeDamage(playerDamage);
        opponent.displayHealth();

        
        if (!opponent.isAlive()) { break; }

        
        int opponentDamage = opponent.calculateDamage();
        cout << opponent.name << " attacks " << player.name << " for " << opponentDamage << " damage.\n";
        player.takeDamage(opponentDamage);
        player.displayHealth();
    }

    if (player.isAlive()) {
        cout << player.name << " wins!\n"; return true;
    } else {
        cout << opponent.name << " wins!\n"; return false;
    }
}