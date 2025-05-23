#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define RED	"\033[1;91m"
# define RES	"\033[0m"

class Zombie
{
    private:
		std::string _name;
    public :
		Zombie();
		Zombie(std::string n);
		~Zombie();
		void Setname(std::string n);
		void Announce(void);
};

Zombie *zombieHorde( int N, std::string name );

#endif
