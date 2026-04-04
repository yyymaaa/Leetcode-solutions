#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

int bitwiseComplement(int n) {
    if (n == 0) return 1;
    
    std::string binaryForm = "";
    int temp = n;

    while (temp > 0) {
        binaryForm += (temp % 2 == 0) ? '0' : '1';
        temp /= 2;
    }

    std::reverse(binaryForm.begin(), binaryForm.end());

    
   for (char &digit : binaryForm) {
        digit = (digit == '1') ? '0' : '1';
    }

   return (int)std::stoull(binaryForm, nullptr, 2);
}

int main() {
    int num = 5;
    std::cout << "Complement of " << num << " is: " << bitwiseComplement(num) << std::endl;
    return 0;
}