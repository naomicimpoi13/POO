#include "sqlite3.h"
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
  int id;
  string nume, prenume, specializare;
  double medie;
  sqlite3 *db;

public:
  Student(const string &dbFile) {
    sqlite3_open(dbFile.c_str(), &db);

    sqlite3_exec(
        db,
        "CREATE TABLE IF NOT EXISTS studenti "
        "(id INTEGER PRIMARY KEY, nume TEXT, prenume TEXT, specializare TEXT, medie REAL);",
        nullptr,
        nullptr,
        nullptr);
  }

  ~Student() { sqlite3_close(db); }

  void Salveaza(string nume, string prenume, string specializare,
                double medie) {
    string sql =
        "INSERT INTO studenti (nume, prenume, specializare, medie) VALUES ('" +
        nume + "', '" + prenume + "', '" + specializare + "', " +
        to_string(medie) + ");";

    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
    cout << "SQL executat: " << sql << "\n";
    cout << "** Student salvat!\n\n";
  }

  void AfiseazaToti() {
    cout << "\n--- Lista studenti ---\n";
    sqlite3_exec(
        db, "SELECT * FROM studenti;",
        [](void *, int, char **row, char **colName) {
          cout << "ID: " << row[0] << "\n"
               << "Nume: " << row[1] << "\n"
               << "Prenume: " << row[2] << "\n"
               << "Specializare: " << row[3] << "\n"
               << "Medie: " << row[4] << "\n"
               << "---\n";
          return 0;
        },
        nullptr, nullptr);
  }

  
  void AfiseazaStudentiMedieMaiMareCa(double medie) {
    cout << "\n--- Studenti cu medie >= " << medie << " ---\n";

    string sql = "SELECT * FROM studenti WHERE medie >= " + to_string(medie) + ";";

    sqlite3_exec(
        db,
        sql.c_str(),
        [](void *, int, char **row, char **colName) {
          cout << "ID: " << row[0] << "\n"
               << "Nume: " << row[1] << "\n"
               << "Prenume: " << row[2] << "\n"
               << "Specializare: " << row[3] << "\n"
               << "Medie: " << row[4] << "\n"
               << "---\n";
          return 0;
        },
        nullptr, nullptr);
  }


  void AfiseazaStudentiNumeIncepeCU(char litera) {
    cout << "\n--- Studenti cu nume care incepe cu '" << litera << "' ---\n";

    string sql = "SELECT * FROM studenti WHERE nume LIKE '" + string(1, litera) + "%';";

    sqlite3_exec(
        db,
        sql.c_str(),
        [](void *, int, char **row, char **colName) {
          cout << "ID: " << row[0] << "\n"
               << "Nume: " << row[1] << "\n"
               << "Prenume: " << row[2] << "\n"
               << "Specializare: " << row[3] << "\n"
               << "Medie: " << row[4] << "\n"
               << "---\n";
          return 0;
        },
        nullptr, nullptr);
  }
};

int main() {
  Student s("studenti.db");

  s.Salveaza("Popescu", "Ion", "IE", 9.5);
  s.Salveaza("Ionescu", "Maria", "MI", 8.2);
  s.Salveaza("Irinescu", "Teodor", "MI", 9.1);

  s.AfiseazaToti();

  // test metode noi
  s.AfiseazaStudentiMedieMaiMareCa(9);
  s.AfiseazaStudentiNumeIncepeCU('I');

  return 0;
}