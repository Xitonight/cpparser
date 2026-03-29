#include <cli.h>
#include <file_utils.h>
#include <string>
#include <string_view>

namespace cli {

Options CliHelper::parse() {
  check();
  if (std::string_view(argv_[1]) == "-s") {
    return Options{argv_[2]};
  } else if (std::string_view(argv_[1]) == "-p") {
    return Options{io::readFile(argv_[2])};
  }
  return Options{};
}

void CliHelper::check() {
  bool hasError = false;

  if (argc_ == 1) {
    showError("Missing arguments.");
    hasError = true;
  }

  if (argc_ >= 2 && std::string_view{argv_[1]} != "-s" &&
      std::string_view{argv_[1]} != "-p") {
    showError("Invalid argument(s).");
    hasError = true;
  }

  if (argc_ == 2) {
    showError("Missing argument for " + std::string(argv_[1]) + ".");
    hasError = true;
  }

  if (argc_ > 3) {
    showError("Invalid argument(s).");
    hasError = true;
  }

  if (hasError) {
    showUsage(std::cout);
    exit(1);
  }
}

void CliHelper::showError(std::string_view msg) {
  std::cerr << Color::RED << "Error: " << msg << Color::RESET << std::endl
            << std::endl;
}

void CliHelper::showUsage(std::ostream &out) {
  out << "Usage" << std::endl << std::endl;
  out << "  parser -s <source-string>" << std::endl;
  out << "  parser -p <path-to-source>" << std::endl;
}

} // namespace cli
