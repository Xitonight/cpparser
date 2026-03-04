#include <cstddef>
#include <string>
#include <vector>

namespace lexer {

enum class TokenType {
  Number,
  Plus,
  Minus,
  Star,
  Slash,
  LParenthesis,
  RParenthesis,
  End
};

class Token {
  TokenType type_;
  std::string lexeme_;
  std::size_t position_;

public:
  Token(TokenType type) : type_{type} {}
};

class tokenizer {
  std::vector<Token> tokens_;

public:
  std::vector<Token> tokens() const { return tokens_; }
};

} // namespace lexer
