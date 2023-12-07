#include <iostream>

int main() {
    std::string input;
    std::cout << "Enter your input  terminate with Ctrl+Z \n";

    char ch;
    while (std::cin.get(ch)) {
        input += ch;
    }

    int spaceCount = 0;
    int lineBreakCount = 0;

    for (char c : input) {
        if (c == ' ') {
            spaceCount++;
        } else if (c == '\n') {
            lineBreakCount++;
        }
    }

    std::cout << "Number of blank spaces: " << spaceCount << std::endl;
    std::cout << "Number of line breaks: " << lineBreakCount << std::endl;

    return 0;
}
