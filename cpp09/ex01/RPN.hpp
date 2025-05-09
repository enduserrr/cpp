#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stdexcept>

/**
 * @brief   Reverse Polish Notation (RPN) is a wonky way to write math.
 *          Operators (+, -, *, /) come after the numbers (operands) they apply to.
 *          For example, 3 4 + means 3 + 4 (removes the need for parentheses).
 */
class RPN {
public:
    RPN();
    RPN(const RPN& src);
    RPN& operator=(const RPN& src);
    ~RPN();

    static int evaluate(const std::string& expression);
};

#endif