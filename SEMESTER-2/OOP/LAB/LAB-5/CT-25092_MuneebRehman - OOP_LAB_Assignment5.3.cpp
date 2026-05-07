// Exercise 3: Weapons hierarchy - Multilevel inheritance
#include <iostream>

class Weapons
{
	public:
		void WeaponsDescription()
		{
			std::cout << "\nWeapons: Used for combat and defense purposes.";
		}
};

class HotWeapons : public Weapons
{
	public:
		void HotWeaponsDescription()
		{
			std::cout << "\nHot Weapons: Uses gunpowder or explodes to cause damage.";
		}
};

class Bombs : public HotWeapons
{
	public:
		void BombsDescription()
		{
			std::cout << "\nBombs: Explosive devices that blow up on detonation.";
		}
};

class NuclearBombs : public Bombs
{
	public:
		void NuclearBombsDescription()
		{
			std::cout << "\nNuclear Bombs: Extremely powerful bombs that blow up using nuclear fission and fusion reactions.";
		}
};

int main()
{
	std::cout << "=== Defense Organization Weapons Hierarchy ===\n";
	
	Weapons weapon1;
	std::cout << "\n--- Level 1: Weapons ---";
	weapon1.WeaponsDescription();
	
	HotWeapons weapon2;
	std::cout << "\n\n--- Level 2: Hot Weapons ---";
	weapon2.WeaponsDescription();
	weapon2.HotWeaponsDescription();
	
	Bombs weapon3;
	std::cout << "\n\n--- Level 3: Bombs ---";
	weapon3.WeaponsDescription();
	weapon3.HotWeaponsDescription();
	weapon3.BombsDescription();
	
	NuclearBombs weapon4;
	std::cout << "\n\n--- Level 4: Nuclear Bombs ---";
	weapon4.WeaponsDescription();
	weapon4.HotWeaponsDescription();
	weapon4.BombsDescription();
	weapon4.NuclearBombsDescription();
	
	std::cout << "\n\nHierarchy: Weapons -> Hot Weapons -> Bombs -> Nuclear Bombs\n";
}