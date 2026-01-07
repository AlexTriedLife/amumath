#ifndef ALGEBRA_H
#define ALGEBRA_H
#include <memory>
#include <variant>

// A tree for ast (operators and values)
// TODO: setup templates, implement a lexer, tokens, and parser in order to
// evaluate symbolic expressions
namespace amumath {
namespace algebra {

struct Node {
  // Either an operator(char) or a value(double)
  std::variant<double, char> value;
  // Left node of tree
  std::unique_ptr<Node> left;
  // Right node of tree
  std::unique_ptr<Node> right;

  // Leaf constructor (number only)
  Node(double val) : value(val), left(nullptr), right(nullptr) {}
  // Operator constructor
  Node(char op, std::unique_ptr<Node> l, std::unique_ptr<Node> r)
      : value(op), left(std::move(l)), right(std::move(r)) {}
};

// Evaluate a numerical expression like 2 + 2 * 5 then return the result
inline double evaluate(const Node *node) {
  // If node holds a double it is a leaf node
  if (std::holds_alternative<double>(node->value)) {
    return std::get<double>(node->value);
  }

  // If not a leaf node, it is an operator
  char op = std::get<char>(node->value);

  // Recursively evaluate children to get to bottoms(leaves)
  double l_val = evaluate(node->left.get());
  double r_val = evaluate(node->right.get());

  // Calculate result
  switch (op) {
  case '+':
    return l_val + r_val;
  case '-':
    return l_val - r_val;
  case '*':
    return l_val * r_val;
  case '/':
    return l_val / r_val;
  default:
    return 0.0;
  }
}

} // namespace algebra
} // namespace amumath

#endif // ALGEBRA_H
