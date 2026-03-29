#include <cli.h>
#include <lexer.h>

int main(int argc, char *argv[]) {
  cli::CliHelper cliHelper{argc, argv};
  auto options = cliHelper.parse();

  return 0;
}
