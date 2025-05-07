/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:30:10 by asalo             #+#    #+#             */
/*   Updated: 2025/05/07 12:30:25 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <utility> // For std::pair
#include <algorithm> // For std::sort, std::lower_bound, std::distance
#include <limits>    // For std::numeric_limits
#include <ctime>     // For clock_t, clock, CLOCKS_PER_SEC
#include <iomanip>   // For std::fixed, std::setprecision
#include <sstream>   // For std::stringstream
#include <stdexcept> // For std::runtime_error

class PmergeMe {
    private:
        std::vector<int> _unsortedSequence;

        typedef std::vector<int> IntVector;
        typedef std::vector<std::pair<int, int> > PairVector;

        void fordJohnsonSort(IntVector& container);
        void makePairs(const IntVector& S, PairVector& pairs, int& straggler, bool& hasStraggler);
        struct ComparePairsByLargerVec { // Helper struct for sorting pairs by their second element
            bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
                return a.second < b.second;
            }
        };
        void sortPairsByLarger(PairVector& pairs);
        void mergeAndInsert(IntVector& S, PairVector& sorted_pairs, int straggler, bool hasStraggler);
        void binaryInsert(IntVector& chain, int value, typename IntVector::iterator end_it);
        void printSequence(const IntVector& c, const std::string& prefix, size_t limit = 10);

        typedef std::deque<int> IntDeque;
        typedef std::deque<std::pair<int, int> > PairDeque;

        void fordJohnsonSort(IntDeque& container);
        void makePairs(const IntDeque& S, PairDeque& pairs, int& straggler, bool& hasStraggler);
        struct ComparePairsByLargerDeq { // Helper struct for sorting pairs by their second element
            bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
                return a.second < b.second;
            }
        };
        void sortPairsByLarger(PairDeque& pairs);
        void mergeAndInsert(IntDeque& S, PairDeque& sorted_pairs, int straggler, bool hasStraggler);
        void binaryInsert(IntDeque& chain, int value, typename IntDeque::iterator end_it);
        void printSequence(const IntDeque& c, const std::string& prefix, size_t limit = 10);

        std::vector<int> generateJacobsthalInsertionSequence(size_t num_pend_elements);
        void parseInput(int argc, char **argv);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);

        void sortAndReport(int argc, char **argv);
};

#endif