#include "RPN.hpp"
#include <stack>     // The chosen standard container (adapter)
#include <sstream>   // For tokenizing the string
#include <cctype>    // For std::isdigit

RPN::RPN() {}


RPN::RPN(const RPN& src) {
    (void)src;
}

RPN& RPN::operator=(const RPN& src) {
    (void)src;
    return *this;
}

RPN::~RPN() {}

/**
 * @brief   Stack container fits the RPN evaluation process well:
 *          operands are pushed, and when an operator is encountered,
 *          the last two operands are popped for calculation, with the result pushed back.
 */
int RPN::evaluate(const std::string& expression) {
    std::stack<int> operands;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.length() == 1 && std::isdigit(token[0])) {
            operands.push(token[0] - '0'); // Numbers are single digit < 10
        } else if (token.length() == 1 && (token == "+" || token == "-" || token == "*" || token == "/")) {
            if (operands.size() < 2) {
                throw std::runtime_error("Error");
            }
            int rhs = operands.top();
            operands.pop();
            int lhs = operands.top();
            operands.pop();

            if (token == "+") {
                operands.push(lhs + rhs);
            } else if (token == "-") {
                operands.push(lhs - rhs);
            } else if (token == "*") {
                operands.push(lhs * rhs);
            } else if (token == "/") {
                if (rhs == 0) {
                    throw std::runtime_error("Error"); // Division by zero
                }
                operands.push(lhs / rhs);
            }
        } else {
            // Invalid token (multi-digit number, non-operator char, brackets)
            throw std::runtime_error("Error");
        }
    }

    if (operands.size() != 1) {
        // Empty & only operator expressions & expressions leaving too many nb's on the stack
        throw std::runtime_error("Error");
    }

    return operands.top();
}