#include <cstddef>
#include <string>

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
public:
  Token(TokenType type) : type_{type} {}

private:
  TokenType type_;
  std::string lexeme_;
  std::size_t position_;
};

class Lexer {
public:
  Lexer(std::string source) : source_{source} {};

  Token nextToken();
  bool isAtEnd() const;
  char peek() const;
  char advance();
  bool match(char expected);

private:
  std::string source_;
  std::size_t current_ = 0;
  std::size_t line_ = 1;
};

} // namespace lexer
