// LeapFrog.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define BEGIN -1
#define END 65536


bool customComp(std::vector<int> a, std::vector<int> b)
{ 
    return a[1] > b[1]; 
}

std::vector<int> leapFrogJoin(std::vector<std::vector<int>> records)
{
    std::vector<int> new_record{ BEGIN };
    int num_records = records.size();
    std::vector<std::vector<int>::iterator> recordsIterators;

    for (int record = 0; record < num_records; record++) {
        recordsIterators.push_back(records[record].begin());
    }


    while (*recordsIterators.front() != END)
    {
        recordsIterators.front()++;
        // sync
        int max = *recordsIterators.front();
        int min = *recordsIterators.back();
        int p = 1;
        while (max != min)
        {
            recordsIterators[p] = std::lower_bound(recordsIterators[p], records[p].end(), max);
            max = *recordsIterators[p];
            p = (p + 1) % num_records;
            min = *recordsIterators[p];
        }
        new_record.push_back(*recordsIterators.front());
    }
    return new_record;
}

int main()
{
    std::cout << "Record 1: ";


    std::vector<int> record1{ BEGIN, 2, 3, 5, 12, 15, 29, 30, 42, 43, END };
    std::vector<int> record2{ BEGIN, 5, 6, 8, 12, 22, 25, 29, 32, 42, 45, END };
    std::vector<int> record3{ BEGIN, 1, 2, 5, 9, 10, 29, 34, 35, 37, 42, END };

    std::vector<std::vector<int>> records {record1, record2, record3};

    int num = 1;
    for (auto const& record : records) {

        std::cout << "\nRecord " << num++ << " : ";
        for (auto const& i : record) {
            std::cout << i << " ";
        }

    }


    std::cout << "\nSorting the records to get the first element to be greater.\n";

    std::sort(records.begin(), records.end(), customComp);



    num = 1;
    for (auto const& record : records) {

        std::cout << "\nRecord " << num++ << " : ";
        for (auto const& i : record) {
            std::cout << i << " ";
        }

    }


    auto ptr = record1.begin();

    std::cout << "\n" << *ptr << "\n";

    ptr = std::lower_bound(ptr, record1.end(), 13);

    std::cout << *ptr << "\n";



    auto res = leapFrogJoin(records);
    std::cout << "\n\n Result : ";
    for (auto const& i : res) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
