#include "Zombie.hpp"

int main()
{
    Zombie *Z;
    int	N = 5;

    Z = zombieHorde(N,"Zombie");
    for (size_t i = 0; i < N; i++) {
      std::cout << "Horde: " << i << "_";
      Z[i].Announce();
    }
    delete[] Z;
}
