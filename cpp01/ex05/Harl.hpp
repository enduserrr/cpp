#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define GC     "\033[3;90m"
# define WB     "\033[1;97m"
# define BB     "\033[1;96m"
# define YB     "\033[1;93m"
# define RB     "\033[1;91m"
# define RES    "\033[0m"

class Harl
{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
	public:
		Harl();
		~Harl();
		void Complain(std::string level);
};

#endif
