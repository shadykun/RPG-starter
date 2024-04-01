#pragma once
#include <iostream>
#include <ostream>
#include <istream>

typedef class enemy enemy;

class character
{
    //name, lvl, AD, HP, Def, Rem.HP, Health Potions count
    protected:
        std::string name;
        int lvl;
        int AttackDamage;
        int HP;
        int Def;
        int Remaining_HP;
        int HealthPotionsCount;

    private:
        static const int baseLvl {1};
        static const int baseAD = 8;
        static const int baseHP = 30;
        static const int baseDef = 45;

        static const int maxLvl = 10;
        static const int maxAD = 44;
        static const int maxHP = 300;
        static const int maxDef = 450;
        
        static const int healPotionRestorationEffect = 30;
        static const int startHealthPotionsCount = 4;

    public:
        character();
        character(std::string Name, int AD, int Hp, int defense);

    public:
        std::string get_name();
        int get_lvl();
        int get_AD();
        int get_HP();
        int get_RemHP();
        int get_Def();
        int get_HealthPotions();
        
    public:
        void set_name(std::string &Name);
        void set_lvl(int &n);
        void set_AD(int &n);
        void set_HP(int &n);
        void set_RemHP(int &n);
        void set_Def(int &n);
        void set_HealthPotions(int &n);

    public:
        void Heal();
        void Attack(enemy &c);
        bool isAlive();
        void lvlUp();
        friend std::ostream& operator<<(std::ostream& of, const character &c);
        bool operator<(character &c);
        bool operator>(character &c);
        bool operator==(character &c);
        bool operator!=(character &c);
        character& operator++();
        character operator++(int);
};

std::istream &operator>>(std::istream& is, character&c);

class enemy:public character
{
    public:
    void Attack(character &c);
};
