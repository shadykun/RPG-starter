#include "character.h"
#include <cmath>

character::character()
{
    name = "Luigi";
    lvl = baseLvl;
    AttackDamage = baseAD;
    HP = baseHP;
    Def = baseDef;
    Remaining_HP = HP;
    HealthPotionsCount = startHealthPotionsCount;
}

character::character(std::string Name, int AD, int Hp, int defense)
{
    name = Name;
    lvl = baseLvl;
    AttackDamage = AD;
    HP = Hp;
    Def = defense;
    Remaining_HP = HP;
    HealthPotionsCount = startHealthPotionsCount;
}

//gets

std::string character::get_name()
{
    return name;
}

int character::get_lvl()
{
    return lvl;
}

int character::get_AD()
{
    return AttackDamage;
}

int character::get_Def()
{
    return Def;
}

int character::get_HP()
{
    return HP;
}
int character::get_RemHP()
{
    return Remaining_HP;
}

int character::get_HealthPotions()
{
    return HealthPotionsCount;
}

//sets

void character::set_name(std::string &Name)
{
    name = Name;
}

void character::set_lvl(int &n)
{
    lvl = n;
}

void character::set_AD(int &n)
{
    AttackDamage = n;
    if(AttackDamage > maxAD)
        AttackDamage = maxAD;
}

void character::set_HP(int &n)
{
    HP = n;
    if(HP > maxHP)
        HP = maxHP;
}

void character::set_RemHP(int &n)
{
    Remaining_HP = n;
    if(Remaining_HP > HP)
        Remaining_HP = HP;
}

void character::set_Def(int &n)
{
    Def = n;
    if(Def > maxDef)
        Def = maxDef;
}

void character::set_HealthPotions(int n)
{
    HealthPotionsCount = n;
}

//Metode

void character::Heal()
{
    if (HealthPotionsCount == 0)
    {
        std::cout << "\nNo more life potions!\n";
        return;
    }
    Remaining_HP += healPotionRestorationEffect;
    if(Remaining_HP > HP)
        Remaining_HP = HP;
    HealthPotionsCount--;
}//check Health potions count before

void character::Attack(enemy &c)
{
    float damageDealt = AttackDamage * std::min((float)(c.get_HP())/c.get_Def(), (float)1);
    int dmg = std::floor(damageDealt);
    int newHP = std::max(c.get_RemHP() - dmg, 0);
    c.set_RemHP(newHP);
}

void enemy::Attack(character &c)
{
    float damageDealt = AttackDamage * std::min((float)(c.get_HP())/c.get_Def(), (float)1);
    int dmg = std::floor(damageDealt);
    int newHP = std::max(c.get_RemHP() - dmg, 0);
    c.set_RemHP(newHP);
}

bool character::isAlive()
{
    if(Remaining_HP == 0)
        return 0;
    return 1;
}

void character::lvlUp()
{
    if(lvl < maxLvl)
    {
        lvl++;//set_lvl(get_lvl() + 1); dar asta e mai convenabil
        AttackDamage += baseAD;
        HP += baseHP;
        Remaining_HP = HP;
        Def += baseDef;
    }
}

/*
std::cout << MC
f << MC

aV = mV * x / 100

x = aV / mV * 100

*/

void bar(int maxVal, int actualVal)
{
    std::cout<<"[";
    for(int i = 0; i < 20; i++)
    {
        if(i < float(actualVal) / maxVal * 20)
            std::cout<<"|";
        else
            std::cout<<" ";
    }
    std::cout<<"]\n";
}

std::ostream& operator<<(std::ostream& of, character& c)
{
    of << "Player name: " << c.get_name() << "\n\n";
    of << "Level: " << c.get_lvl() << "\n";
    std::cout<<"HP ";
    bar(c.get_HP(), c.get_RemHP());
    of << "Defense: " << c.get_Def() << "\n";
    of << "Attack Damage: " << c.get_AD() << "\n\n";
    of << "You have " << c.get_HealthPotions() << " potions left!\n";
    return of;
}

std::istream &operator>>(std::istream& is, character&c)
{
    int ad,hp,def;
    std::string name;
    is >> name >> hp >> def >> ad;
    return is;
}

std::ostream& operator<<(std::ostream& of, enemy& c)
{
    of << "Enemy name: " << c.get_name() << "\n\n";
    of << "Level: " << c.get_lvl() << "\n";
    std::cout<<"HP ";
    bar(c.get_HP(), c.get_RemHP());
    of << "Defense: " << c.get_Def() << "\n";
    of << "Attack Damage: " << c.get_AD() << "\n";
    return of;
}

bool character::operator<(character &c)
{
    return (HP * AttackDamage * Def < c.get_HP() * c.get_AD() * c.get_Def());
}

bool character::operator>(character &c)
{
    return (HP * AttackDamage * Def > c.get_HP() * c.get_AD() * c.get_Def());
}

bool character::operator==(character &c)
{
    return (HP * AttackDamage * Def == c.get_HP() * c.get_AD() * c.get_Def());
}

bool character::operator!=(character &c)
{
    return (HP * AttackDamage * Def != c.get_HP() * c.get_AD() * c.get_Def());
}

character& character::operator++()
{
    lvlUp();
    return *this;
}

character character::operator++(int)
{
    lvlUp();
    return *this;
}

enemy::enemy()
{
    name = "Wario";
    lvl = baseLvl;
    AttackDamage = baseAD / 2;
    HP = baseHP / 2;
    Def = baseDef / 2;
    Remaining_HP = HP;
    HealthPotionsCount = 0;
}