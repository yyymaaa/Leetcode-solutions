#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool isAlphabeticPalindrome(std::string code) {
    std::string letters_only;
    std::copy_if(code.begin(), code.end(),
                 std::back_inserter(letters_only),
                 [](unsigned char c){return std::isalpha(c); });

    for (char& c : letters_only) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }

    return std::equal(letters_only.begin(), letters_only.end(), letters_only.rbegin());
}

int main() {
    std::string testCode = "A1b2B!a";
    
    bool result = isAlphabeticPalindrome(testCode);
    
    std::cout << "Input: " << testCode << std::endl;
    std::cout << "Output: " << result << std::endl;
    
    return 0;
}