#ifndef WEAPON_H
#define WEAPON_H

# include <iostream>
# include <string>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(std::string a);
        ~Weapon();
        std:: string &GetType();
        void SetType(std::string str);
};

#endif
