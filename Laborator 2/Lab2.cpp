#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Invatator {
    string nume, scoala, clasa;
    int norma;
    double vechime;
    vector<string> calificari;

public:
    Invatator(string nume, string scoala, string clasa, int norma, double vechime) {
        this->nume = nume;
        this->scoala = scoala;
        this->clasa = clasa;
        this->norma = norma;
        this->vechime = vechime;
    }

    void Afiseaza() {
        cout << "Invatator: " << nume << endl;
        cout << "Scoala: " << scoala << endl;
        cout << "Clasa: " << clasa << endl;
        cout << "Norma: " << norma << endl;
        cout << "Vechime: " << vechime << " ani" << endl;
    }
};

int main() {
    Invatator inv("Cimpoi Naomi", "Scoala Gimnaziala Dornesti", "a III-a", 20, 3.7);

    inv.Afiseaza();

    return 0;
}