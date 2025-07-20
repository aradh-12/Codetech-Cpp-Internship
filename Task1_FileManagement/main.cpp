#include <iostream>   // For input and output operations
#include <fstream>    // For file stream handling (ifstream, ofstream)
#include <string>     // For using string class
using namespace std;

// Function to write data to a file (this will overwrite existing content)
void writeToFile(const string& filename) {
    ofstream file(filename);  // Open file in write mode
    if (!file) {
        cout << "Error opening file for writing.\n";
        return;
    }
    file << "This is the first line.\n";    // Writing first line
    file << "This is the second line.\n";   // Writing second line
    file.close();                           // Close the file after writing
    cout << "Data written successfully.\n"; // Confirm success on console
}

// Function to append data to a file (adds new data without deleting existing data)
void appendToFile(const string& filename) {
    ofstream file(filename, ios::app);   // Open file in append mode
    if (!file) {
        cout << "Error opening file for appending.\n";
        return;
    }
    file << "This is an appended line.\n";  // Appending new line to file
    file.close();                           // Close the file after appending
    cout << "Data appended successfully.\n"; // Confirm success on console
}

// Function to read data from a file and display it on the console
void readFromFile(const string& filename) {
    ifstream file(filename);  // Open file in read mode
    if (!file) {
        cout << "Error opening file for reading.\n";
        return;
    }
    string line;
    cout << "File Content:\n";  // Message for clarity
    while (getline(file, line)) {
        cout << line << endl;   // Output each line to console
    }
    file.close();  // Close the file after reading
}

// Main function to demonstrate file writing, appending, and reading
int main() {
    string filename = "output.txt"; // File to operate on

    writeToFile(filename);   // Step 1: Write new content to file
    appendToFile(filename);  // Step 2: Append extra content to file
    readFromFile(filename);  // Step 3: Read and display file content

    return 0;
