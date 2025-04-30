# TEMPLATE CONTAINERS, ITERATORS, ALGORITHMS

## STL Components
* Containers: Data structures storing collections of objects.
* Algorithms: Functions performing operations on data within a container
  * find()
  * max_element()
* Iterator: Objects acting like pointers, giving access to elements within cointainers and linking algos to them
  * begin() & end() return STL iterators (technically STL container member funcs not iterators themselves)
* Function Objects: Objects that can be called like funcs, mostly used to customize algorithms

## Ex00

## Ex01

## Ex02
* std::stack uses an underlying container (e.g. std::deque by default) which has begin() and end() but the std::stack adapter hides these from its public interface on purpose.
* MutantStack class enables iterating through std::stack container
* Functions begin() & end() return iterators to the beginning and end of the container
