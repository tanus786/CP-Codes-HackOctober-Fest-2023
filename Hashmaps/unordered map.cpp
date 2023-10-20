#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

int main() {
    std::string text = "This is a sample text. This is a simple example.";

    // Create an unordered_map to store word frequencies
    std::unordered_map<std::string, int> wordFrequency;

    // Tokenize the text into words
    std::istringstream iss(text);
    std::string word;
    
    while (iss >> word) {
        // Remove punctuation and convert to lowercase (you may need a more comprehensive approach)
        for (char& c : word) {
            if (std::ispunct(c)) {
                c = ' ';
            }
            else {
                c = std::tolower(c);
            }
        }

        // Increment the frequency in the map
        if (!word.empty()) {
            wordFrequency[word]++;
        }
    }

    // Display the word frequencies
    for (const auto& pair : wordFrequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
