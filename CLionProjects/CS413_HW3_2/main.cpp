#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compare two numbers for sorting
bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

// Function to find the largest number by concatenating the input sequence of numbers
string findLargestNumber(vector<string>& nums) {
    // Sort the numbers using the custom comparison function
    sort(nums.begin(), nums.end(), compare);

    // Concatenate the sorted numbers to form the largest number
    string largestNumber;
    for (const string& num : nums) {
        largestNumber += num;
    }

    return largestNumber;
}

int main() {
    vector<string> nums;
    string input;

    // Ask user for input
    cout << "Enter numbers (press Enter to use default values): ";
    getline(cin, input);

    // If user provides input, split it by spaces and add to nums vector
    if (input.empty()) {
        nums = {"5", "52", "57", "517", "532", "569", "581"};
    } else {
        size_t start = 0, end;
        while ((end = input.find(' ', start)) != string::npos) {
            nums.push_back(input.substr(start, end - start));
            start = end + 1;
        }
        nums.push_back(input.substr(start));
    }

    // Find the largest number
    string largestNumber = findLargestNumber(nums);

    // Output the largest number
    cout << "The largest number by concatenating the input sequence of numbers is: " << largestNumber << endl;

    return 0;
}
