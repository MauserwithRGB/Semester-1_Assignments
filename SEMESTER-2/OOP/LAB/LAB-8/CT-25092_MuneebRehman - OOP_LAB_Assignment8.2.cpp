#include <iostream>
#include <string>

class Character
{
protected:
    std::string name;
    int level;
    int health;
public:
    Character(std::string n, int l, int h) : name(n), level(l), health(h) {}
    virtual void display() = 0;
    virtual ~Character() {}
};

class Warrior : virtual public Character
{
protected:
    int strength;
    std::string meleeWeapon;
public:
    Warrior(int s, std::string mW, std::string n, int l, int h)
        : Character(n, l, h), strength(s), meleeWeapon(mW) {}
    void slash() { std::cout << name << " slashes with " << meleeWeapon << "!\n"; }
};

class Mage : virtual public Character
{
protected:
    int intelligence;
    std::string spellProficiency;
public:
    Mage(int i, std::string sp, std::string n, int l, int h)
        : Character(n, l, h), intelligence(i), spellProficiency(sp) {}
    void fireball() { std::cout << name << " casts Fireball!\n"; }
};

class Archer : virtual public Character
{
protected:
    int dexterity;
    std::string rangedWeapon;
public:
    Archer(int d, std::string rW, std::string n, int l, int h)
        : Character(n, l, h), dexterity(d), rangedWeapon(rW) {}
    void rapidShot() { std::cout << name << " fires a rapid shot with " << rangedWeapon << "!\n"; }
    void display() override {
        std::cout << "=== Archer ===\n"
                  << "Name: "      << name       << "\n"
                  << "Level: "     << level      << "\n"
                  << "Health: "    << health     << "\n"
                  << "Dexterity: " << dexterity  << "\n"
                  << "Weapon: "    << rangedWeapon << "\n";
    }
};

class NPC : virtual public Character
{
    std::string dialogue;
public:
    NPC(std::string dlg, std::string n, int l, int h)
        : Character(n, l, h), dialogue(dlg) {}
    void speak() { std::cout << name << " says: " << dialogue << "\n"; }
    void display() override {
        std::cout << "=== NPC ===\n"
                  << "Name: "    << name    << "\n"
                  << "Level: "   << level   << "\n"
                  << "Health: "  << health  << "\n"
                  << "Dialogue: "<< dialogue << "\n";
    }
};

class Mighty : public Warrior, public Mage
{
public:
    Mighty(int s, std::string mW, int i, std::string sp, std::string n, int l, int h)
        : Character(n, l, h), Warrior(s, mW, n, l, h), Mage(i, sp, n, l, h) {}
    void display() override {
        std::cout << "=== Mighty ===\n"
                  << "Name: "         << name           << "\n"
                  << "Level: "        << level          << "\n"
                  << "Health: "       << health         << "\n"
                  << "Strength: "     << strength       << "\n"
                  << "Weapon: "       << meleeWeapon    << "\n"
                  << "Intelligence: " << intelligence   << "\n"
                  << "Spell Prof: "   << spellProficiency << "\n";
    }
};

int main()
{
    Archer archer(90, "Longbow", "Legolas", 10, 150);
    archer.display();
    archer.rapidShot();

    NPC npc("Welcome to the village!", "Villager", 1, 50);
    npc.display();
    npc.speak();

    Mighty mighty(95, "Greatsword", 88, "Arcane", "Gandalf", 20, 300);
    mighty.display();
    mighty.slash();
    mighty.fireball();
}