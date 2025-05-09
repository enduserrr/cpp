#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) {
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    if (this != &rhs) {
        _unsortedSequence = rhs._unsortedSequence;
    }
    return *this;
}


void PmergeMe::parseInput(int argc, char **argv) {
    _unsortedSequence.clear();
    for (int i = 1; i < argc; ++i) {
        std::string s_arg = argv[i];
        if (s_arg.empty()) {
            throw std::runtime_error("Empty argument string encountered.");
        }
        for (size_t j = 0; j < s_arg.length(); ++j) {
            if (!isdigit(s_arg[j])) {
                throw std::runtime_error("Invalid character in input: '" + std::string(1, s_arg[j]) + "'. Only positive integers allowed.");
            }
        }

        long long val;
        std::stringstream ss(s_arg);
        ss >> val;

        if (ss.fail() || !ss.eof()) {
             throw std::runtime_error("Invalid number format: " + s_arg);
        }
        if (val <= 0) {
            throw std::runtime_error("Input numbers must be positive: " + s_arg);
        }
        if (val > std::numeric_limits<int>::max()) {
            throw std::runtime_error("Input number exceeds maximum integer value: " + s_arg);
        }
        _unsortedSequence.push_back(static_cast<int>(val));
    }
    if (_unsortedSequence.empty() && argc > 1) {
         throw std::runtime_error("No valid positive integers provided in input.");
    }
}

/**
 * @brief   Parses, sorts with two containers, and reports times.
 */
void PmergeMe::sortAndReport(int argc, char **argv) {
    parseInput(argc, argv); // Can throw, caught by main

    printSequence(_unsortedSequence, "Before:");

    // Process with vector
    IntVector vec_data = _unsortedSequence;
    clock_t start_vec = clock();
    fordJohnsonSort(vec_data);
    clock_t end_vec = clock();
    double time_vec = static_cast<double>(end_vec - start_vec) * 1000000.0 / CLOCKS_PER_SEC;

    printSequence(vec_data, "After:");

    // Process with deque
    IntDeque deq_data;
    for (size_t i = 0; i < _unsortedSequence.size(); ++i) {
        deq_data.push_back(_unsortedSequence[i]);
    }
    clock_t start_deq = clock();
    fordJohnsonSort(deq_data);
    clock_t end_deq = clock();
    double time_deq = static_cast<double>(end_deq - start_deq) * 1000000.0 / CLOCKS_PER_SEC;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << GB << "Sorted " << _unsortedSequence.size()
              << " elements (std::vector) in : " << RES << time_vec << " us" << std::endl;
    std::cout << GB << "Sorted " << _unsortedSequence.size()
              << " elements (std::deque) in  : " << RES << time_deq << " us" << std::endl;
}

/**
 * @brief   Top-level sort function for vector.
 */
void PmergeMe::fordJohnsonSort(IntVector& container) {
    if (container.size() < 2) {
        return;
    }

    PairVector pairs;
    int straggler = 0;
    bool hasStraggler = false;

    makePairs(container, pairs, straggler, hasStraggler);
    sortPairsByLarger(pairs); // Sorts pairs based on their larger element
    mergeAndInsert(container, pairs, straggler, hasStraggler);
}

/**
 * @brief   Groups elements into pairs (smaller, larger) and identifies a straggler if one exists.
 */
void PmergeMe::makePairs(const IntVector& S, PairVector& pairs, int& straggler, bool& hasStraggler) {
    hasStraggler = (S.size() % 2 != 0);
    size_t n = S.size();
    if (hasStraggler) {
        n--; 
        straggler = S.back();
    }

    for (size_t i = 0; i < n; i += 2) {
        if (S[i] < S[i+1]) {
            pairs.push_back(std::make_pair(S[i], S[i+1]));
        } else {
            pairs.push_back(std::make_pair(S[i+1], S[i]));
        }
    }
}

/**
 * @brief   Sorts pairs based on their larger elements (pair.second).
 */
void PmergeMe::sortPairsByLarger(PairVector& pairs) {
    std::sort(pairs.begin(), pairs.end(), ComparePairsByLargerVec());
}

/**
 * @brief   Merges sorted pairs and inserts pend elements using Jacobsthal sequence.
 */
void PmergeMe::mergeAndInsert(IntVector& S, PairVector& sorted_pairs, int straggler, bool hasStraggler) {
    IntVector mainChain;
    
    if (sorted_pairs.empty()) {
        S.clear();
        if (hasStraggler) {
            S.push_back(straggler);
        }
        return;
    }

    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        mainChain.push_back(sorted_pairs[i].second); // L_i elements
    }

    mainChain.insert(mainChain.begin(), sorted_pairs[0].first); // Insert s_1

    IntVector pendChain;
    for (size_t i = 1; i < sorted_pairs.size(); ++i) {
        pendChain.push_back(sorted_pairs[i].first); // s_2, s_3, ...
    }

    std::vector<int> jac_indices = generateJacobsthalInsertionSequence(pendChain.size());

    for (size_t i = 0; i < jac_indices.size(); ++i) {
        int pend_idx = jac_indices[i]; // 0-indexed for pendChain
        int value_to_insert = pendChain[pend_idx];
    
        int larger_partner = sorted_pairs[pend_idx + 1].second; 
        
        typename IntVector::iterator limit_it = std::lower_bound(mainChain.begin(), mainChain.end(), larger_partner);
        binaryInsert(mainChain, value_to_insert, limit_it);
    }

    if (hasStraggler) {
        binaryInsert(mainChain, straggler, mainChain.end());
    }
    S = mainChain;
}

/**
 * @brief   Inserts a value into a sorted chain using binary search up to end_it.
 */
void PmergeMe::binaryInsert(IntVector& chain, int value, typename IntVector::iterator end_it) {
   typename IntVector::iterator insert_pos = std::lower_bound(chain.begin(), end_it, value);
   chain.insert(insert_pos, value);
}

/**
 * @brief   Prints elements of an IntVector.
 */
void PmergeMe::printSequence(const IntVector& c, const std::string& prefix, size_t limit) {
    std::cout << WB << prefix << " " << RES;
    size_t count = 0;
    for (typename IntVector::const_iterator it = c.begin(); it != c.end(); ++it) {
        if (count >= limit && c.size() > limit + 2) {
            std::cout << "[...]";
            break;
        }
        std::cout << *it << (count == c.size() - 1 || (count == limit -1 && c.size() > limit + 2) ? "" : " ");
        count++;
    }
    std::cout << std::endl;
}

/**
 * @brief   Top-level sort function for deque.
 */
void PmergeMe::fordJohnsonSort(IntDeque& container) {
    if (container.size() < 2) {
        return;
    }

    PairDeque pairs;
    int straggler = 0;
    bool hasStraggler = false;

    makePairs(container, pairs, straggler, hasStraggler);
    sortPairsByLarger(pairs);
    mergeAndInsert(container, pairs, straggler, hasStraggler);
}

/**
 * @brief   Groups elements into pairs for std::deque.
 */
void PmergeMe::makePairs(const IntDeque& S, PairDeque& pairs, int& straggler, bool& hasStraggler) {
    hasStraggler = (S.size() % 2 != 0);
    size_t n = S.size();
    if (hasStraggler) {
        n--;
        straggler = S.back();
    }

    for (size_t i = 0; i < n; i += 2) {
        if (S[i] < S[i+1]) {
            pairs.push_back(std::make_pair(S[i], S[i+1]));
        } else {
            pairs.push_back(std::make_pair(S[i+1], S[i]));
        }
    }
}

/**
 * @brief   Sorts pairs for deque.
 */
void PmergeMe::sortPairsByLarger(PairDeque& pairs) {
    std::sort(pairs.begin(), pairs.end(), ComparePairsByLargerDeq());
}

/**
 * @brief   Merges sorted pairs and inserts for deque.
 */
void PmergeMe::mergeAndInsert(IntDeque& S, PairDeque& sorted_pairs, int straggler, bool hasStraggler) {
    IntDeque mainChain;

    if (sorted_pairs.empty()) {
        S.clear();
        if (hasStraggler) {
            S.push_back(straggler);
        }
        return;
    }
    
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        mainChain.push_back(sorted_pairs[i].second);
    }

    mainChain.push_front(sorted_pairs[0].first);

    IntDeque pendChain;
    for (size_t i = 1; i < sorted_pairs.size(); ++i) {
        pendChain.push_back(sorted_pairs[i].first);
    }

    std::vector<int> jac_indices = generateJacobsthalInsertionSequence(pendChain.size());

    for (size_t i = 0; i < jac_indices.size(); ++i) {
        int pend_idx = jac_indices[i];
        int value_to_insert = pendChain[pend_idx];
        int larger_partner = sorted_pairs[pend_idx + 1].second;
        
        typename IntDeque::iterator limit_it = std::lower_bound(mainChain.begin(), mainChain.end(), larger_partner);
        binaryInsert(mainChain, value_to_insert, limit_it);
    }

    if (hasStraggler) {
        binaryInsert(mainChain, straggler, mainChain.end());
    }
    S = mainChain;
}

/**
 * @brief   Inserts a value into a sorted deque.
 */
void PmergeMe::binaryInsert(IntDeque& chain, int value, typename IntDeque::iterator end_it) {
   typename IntDeque::iterator insert_pos = std::lower_bound(chain.begin(), end_it, value);
   chain.insert(insert_pos, value);
}

/**
 * @brief   Prints elements of an IntDeque.
 */
void PmergeMe::printSequence(const IntDeque& c, const std::string& prefix, size_t limit) {
    std::cout << prefix << " ";
    size_t count = 0;
    for (typename IntDeque::const_iterator it = c.begin(); it != c.end(); ++it) {
        if (count >= limit && c.size() > limit + 2) {
            std::cout << "[...]";
            break;
        }
        std::cout << *it << (count == c.size() - 1 || (count == limit -1 && c.size() > limit + 2) ? "" : " ");
        count++;
    }
    std::cout << std::endl;
}

/**
 * @brief   Generates a sequence of indices based on Jacobsthal numbers for optimal insertion order.
 */
std::vector<int> PmergeMe::generateJacobsthalInsertionSequence(size_t N) {
    if (N == 0) return std::vector<int>();

    std::vector<int> j_numbers;
    j_numbers.push_back(0);
    j_numbers.push_back(1);
    while (j_numbers.back() < (int)N) { 
        size_t s = j_numbers.size();
        j_numbers.push_back(j_numbers[s-1] + 2 * j_numbers[s-2]);
        if (s > 30) break; // Safety break for very large N, though N <= 1500 here
    }

    std::vector<int> indices;
    indices.reserve(N);
    std::vector<bool> inserted(N, false);
    size_t items_inserted_count = 0;

    for (size_t k = 2; k < j_numbers.size(); ++k) {
        int current_j_val = j_numbers[k];
        int prev_j_val = j_numbers[k-1];

        // Iterate downwards from current_j_val-1 to prev_j_val
        for (int pend_idx = current_j_val - 1; pend_idx >= prev_j_val; --pend_idx) {
            if (pend_idx < (int)N) { // Ensure index is within bounds of pendChain
                if (!inserted[pend_idx]) { // Check if not already added (shouldn't happen with correct Jacobsthal groups)
                    indices.push_back(pend_idx);
                    inserted[pend_idx] = true;
                    items_inserted_count++;
                }
            }
        }
        if (items_inserted_count == N) break;
    }
    
    for (int pend_idx = N - 1; pend_idx >= 0; --pend_idx) {
        if (!inserted[pend_idx]) {
            indices.push_back(pend_idx);
            inserted[pend_idx] = true;
            items_inserted_count++;
        }
    }
    return indices;
}