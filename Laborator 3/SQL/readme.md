Pentru a folosi SQLite urmați următorii pași:
*Pasul 1:*
    Mergi pe sqlite.org/download.html
    Descarcă două arhive din secțiunea "Source Code" și "Precompiled Binaries for Windows":
        - sqlite-amalgamation-*.zip → conține sqlite3.h + sqlite3.c
        - sqlite-dll-win-x64-*.zip → conține sqlite3.dll + sqlite3.def

*Pasul 2:*
_Pasul 2.1:_
    Daca in proiectul vostru nu se regaseste .vscode/tasks.json dupa prima compilare acesta ar trebuie sa fie generat.
    Daca nu este generat mergeti la pasul urmator, daca il aveti deja generat sariti pasul 2.2.

_Pasul 2.2:_
        1. Creeaza folderul .vscode in folderul proiectului (daca nu exista)
        2. In VS Code: Ctrl+Shift+P → tasteaza:
                Tasks: Configure Default Build Task
            Alege:
                C/C++: g++ build active file
            Acum tasks.json a fost generat.

_Pasul 2.3:_
    Fisierele dezarhivate vor fi adaugate in proiect, arhitectura proiectului ar trebui sa arate astfel:
        proiect/
            |-- .vscode/
                |-- tasks.json
            |-- main.cpp
            |-- sqlite3.h       ← din amalgamation
            |-- sqlite3.c       ← din amalgamation
            |-- sqlite3.dll     ← din dll zip

    
    tasks.json trebuie sa arate astfel:
            {
            "version": "2.0.0",
            "tasks": [
                    {
                        "type": "cppbuild",
                        "label": "C/C++: g++ build active file",
                        "command": "C:/mingw64/bin/g++.exe",
                        "args": [
                            "-g",
                            "${workspaceFolder}/main.cpp",
→→→→                        "-x", "c", "${workspaceFolder}\\sqlite3.c", "-x", "c++", //aceasta linie trebuie adaugata fara 
                                                                                            comentariul actual
                            "-o",
                            "${workspaceFolder}/app.exe"
                        ],
                        "group": {
                            "kind": "build",
                            "isDefault": true
                        }
                    }
                ]
            }
    !!! Verifica ca "command" pointeaza corect catre g++.exe al tau. Calea poate fi C:/mingw64/bin/g++.exe sau C:/msys64/mingw64/bin/g++.exe — depinde cum ai instalat MinGW. Ca sa verifici calea catre g++ tasteaza in terminal: *where g++*

*Pasul 3:*
    Pentru compilare mergeti in terminal si navigati in folderul proiectul dv:
        cd "c:\Users\Petriceanu Denis\Desktop\ProjectsPOO\Laborator_5+6"
    Compilati proiectul:
        g++ -g main.cpp -x c sqlite3.c -x c++ -o app.exe
    Rulati fisierul rezultat:
        .\app.exe

!!!! Acest tutorial este realizat pentru cei care folosesc VSCode, informatiile pot fi folosite si pentru alte IDE-uri.