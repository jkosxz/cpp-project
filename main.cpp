#include <iostream>
#include <fstream>

using namespace std;

std::string readTextFile(const std::string& filename) {
    ifstream file(filename); // Otwarcie pliku do odczytu
    string content;
    string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        file.close(); // Zamknięcie pliku
    } else {
        std::cerr << "Nie można otworzyć pliku " << filename << std::endl;
    }

    return content;
}

int main () {
    string filename = "input.txt";
    string fileContent = readTextFile(filename);

    cout << "Zawartosc pliku " << filename << ":" << endl;
    cout << fileContent << endl;

    return 0;
}