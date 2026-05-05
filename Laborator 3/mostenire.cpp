#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cadru_didactic {
public:
    string nume, scoala, clasa;
    int norma;
    double vechime;

    void setNume(string nume) { this->nume = nume; }
    void setScoala(string scoala) { this->scoala = scoala; }
    void setClasa(string clasa) { this->clasa = clasa; }
    void setNorma(int norma) { this->norma = norma; }
    void setVechime(double vechime) { this->vechime = vechime; }

    void Afiseaza() {
        cout << "Cadru didactic: " << nume << endl;
        cout << "Scoala: " << scoala << endl;
        cout << "Clasa: " << clasa << endl;
        cout << "Norma: " << norma << " ore" << endl;
        cout << "Vechime: " << vechime << " ani" << endl;
    }
};

class Director : public Cadru_didactic {
public:
    int numarSubordonati;

    void setSubordonati(int sub) { numarSubordonati = sub; }

    void AfiseazaDirector() {
        Cadru_didactic::Afiseaza();
        cout << "Functie: Director" << endl;
        cout << "Numar cadre subordonate: " << numarSubordonati << endl;
    }
};

int main() {
    
    cout << "\n----------------------\n" << endl;

    
    cout << "Date Cadru didactic" << endl;
    Cadru_didactic inv;
    inv.setNume("Cimpoi Naomi");
    inv.setScoala("Scoala Gimnaziala Dornesti");
    inv.setClasa("a III-a");
    inv.setNorma(20);
    inv.setVechime(3.7);
    inv.Afiseaza();

    cout << "\n \n" << endl;

    
    cout << "Date Director" << endl;
    Director dir;
    dir.setNume("Biliciuc Lavinia Nicoleta");
    dir.setScoala("Scoala Gimnaziala Dornesti");
    dir.setClasa("la ciclul gimnazial");
    dir.setNorma(40);
    dir.setVechime(32.5);
    
    dir.setSubordonati(50);

    dir.AfiseazaDirector();

    return 0;
}