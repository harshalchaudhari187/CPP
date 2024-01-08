//print the given number in words

#include <iostream>
#include <string>

std::string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
std::string teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
std::string tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

std::string convertToWords(int num) {
    if (num < 10) {
        return ones[num];
    }
    else if (num < 20) {
        return teens[num - 10];
    }
    else if (num < 100) {
        return tens[num / 10] + (num % 10 != 0 ? " " + ones[num % 10] : "");
    }
    else if (num < 1000) {
        return ones[num / 100] + " Hundred" + (num % 100 != 0 ? " " + convertToWords(num % 100) : "");
    }
    else if (num < 1000000) {
        return convertToWords(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + convertToWords(num % 1000) : "");
    }
    else {
        return convertToWords(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + convertToWords(num % 1000000) : "");
    }
}

int main() {
    int N;
    std::cout << "Enter a positive integer: ";
    std::cin >> N;

    if (N < 1) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    std::string result = convertToWords(N);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
