#include "character.h"

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
}

void character::set_HP(int &n)
{
    HP = n;
}

void character::set_RemHP(int &n)
{
    Remaining_HP = n;
}

void character::set_Def(int &n)
{
    Def = n;
}

void character::set_HealthPotions(int &n)
{
    HealthPotionsCount = n;
}

//Metode

void character::Heal()
{
    Remaining_HP += healPotionRestorationEffect;
    if(Remaining_HP > HP)
        Remaining_HP = HP;
    HealthPotionsCount--;
}

void character::Attack(enemy &c)
{
    int damageDealt = AttackDamage * std::min(c.HP/c.Def, 1);
    c.Remaining_HP = std::max(c.Remaining_HP - damageDealt, 0);
}

void enemy::Attack(character &c)
{
    int damageDealt = AttackDamage * std::min(c.get_HP()/c.get_Def(), 1);
    int newHP = std::max(c.get_RemHP() - damageDealt, 0);
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
        Remaining_HP += baseHP;
        Def += baseDef;
    }
}

std::ostream& operator<<(std::ostream& of, character &c)
{
    std::cout<<"\n\n\nPlayer name: "<<c.get_name()<<"\n\n";
    std::cout<<"Level: "<<c.get_lvl()<<"\n";
    std::cout<<"Total HP: "<<c.get_HP()<<"\n";
    std::cout<<"HP: "<<c.get_RemHP()<<"\n";
    std::cout<<"Defense: "<<c.get_Def()<<"\n";
    std::cout<<"Attack Damage: "<<c.get_AD()<<"\n\n";
    std::cout<<"You have "<<c.get_HealthPotions()<<" potions left!\n\n\n";
}

std::istream &operator>>(std::istream& is, character&c)
{
    int ad,hp,def;
    std::string name;
    is >> name >> hp >> def >> ad;
    return is;
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