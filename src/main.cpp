#include <iostream>
#include <lexer/lexer.h>
#include <ostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "ERROR: missing arguments" << std::endl;
    return 1;
  }

  std::string source = "a=1*2*3";

  lexer::Tokenizer tokenizer(source);

  std::cerr << tokenizer.advance() << std::endl;

  return 0;
}
