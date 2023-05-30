#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

string readTextFile(const string& filename) {
    ifstream file(filename); // Otwarcie pliku do odczytu
    string content;
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close(); // Zamknięcie pliku
    } else {
        cerr << "Nie można otworzyć pliku " << filename << endl;
    }

    return content;
}
string polkula(double deklinacja){
    if (deklinacja < 0){
        return "POLUDNIOWA";
    }
    else{
        return "POLNOCNA";
    }

}

double doParsekow(double lataSwietlne){
    return lataSwietlne/3.26;
}

double doAwg(double owg, double r){
    return owg-5*log10(doParsekow(r)) + 5;
}

void poOdleglosci(const string& filename) {
    ifstream plik(filename);
    ofstream plikLokalne("./odleglosci/Lokalne.txt");
    ofstream plikSrednoDalekie("./odleglosci/SrednioDalekie.txt");
    ofstream plikDalekie("./odleglosci/Dalekie.txt");

    string nazwa, klasa_gwiazdy, gwiazdozbior;
    double masa, owg, odleglosc_lata_swietlne, temperatura, deklinacja;
    cout << "nazwa" << " " << "klasa_gwiazdy" << " " << "polkula" << " " << "awg" << " " << "parseki" << " " << "masa" << " " << "temperatura" << endl;
    while (plik >> nazwa >> klasa_gwiazdy >> deklinacja >> owg >> odleglosc_lata_swietlne >> gwiazdozbior >> temperatura
                >> masa) {

        cout << nazwa << " " << klasa_gwiazdy << " " << polkula(deklinacja) << " " << doAwg(owg, odleglosc_lata_swietlne) << " " <<
             doParsekow(odleglosc_lata_swietlne) << " " << masa << " " << temperatura << " " << endl;

    }
}


int main () {
    string filename = "input.txt";
    string fileContent = readTextFile(filename);

    poOdleglosci("input.txt");

    cout << "Zawartosc pliku " << filename << ":" << endl;
    cout << fileContent << endl;

    return 0;
}


