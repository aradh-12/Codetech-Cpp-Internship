#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>

using namespace std;

mutex mtx;

// Function to compress a single line using Run-Length Encoding
string compressLine(const string& line) {
    string compressed = "";
    int count = 1;
    for (int i = 1; i <= line.length(); i++) {
        if (line[i] == line[i - 1]) {
            count++;
        } else {
            compressed += line[i - 1] + to_string(count);
            count = 1;
        }
    }
    return compressed;
}

// Thread function to process a range of lines from input.txt
void compressPart(const vector<string>& lines, int start, int end, const string& outputFile) {
    ofstream out(outputFile, ios::app);
    for (int i = start; i <= end && i < lines.size(); i++) {
        string compressed = compressLine(lines[i]);
        lock_guard<mutex> lock(mtx); // Ensure safe writing from multiple threads
        out << compressed << endl;
    }
    out.close();
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "compressed.txt";

    ifstream in(inputFile);
    if (!in) {
        cout << "Error: Could not open input.txt" << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(in, line)) {
        lines.push_back(line);
    }
    in.close();

    // Clear the output file
    ofstream clear(outputFile);
    clear.close();

    // Split work across 2 threads
    int mid = lines.size() / 2;

    thread t1(compressPart, ref(lines), 0, mid - 1, outputFile);
    thread t2(compressPart, ref(lines), mid, lines.size() - 1, outputFile);

    t1.join();
    t2.join();

    cout << " Compression completed using 2 threads." << endl;
    return 0;
}