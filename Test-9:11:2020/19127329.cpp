#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#define INPUT_FILE_NAME     "input.txt"
#define OUTPUT_FILE_NAME    "output.txt"

using namespace std;

struct Animal {
    char Type;
    string ID;
    float Weight;
    Animal* pNext;
};

struct AnimalList {
    Animal* pFirst;
    Animal* pLast;
};

void readAnimal(ifstream&, Animal&);
void readAnimalList(const string &, AnimalList*&);
void saveAnimal(ofstream&, Animal*);
void questionD(const string &, AnimalList*);
Animal* makeNode(char, const string&, float);
void add(AnimalList*&, const Animal&);
void addHead(AnimalList*&, const Animal&);
void addTail(AnimalList*&, const Animal&);
void removeAllList(AnimalList*&);
void printAnimal(Animal*);
void printAnimalList(AnimalList*);
bool isValidAnimal(Animal*);
void printAnimalInvalid(AnimalList*);

int main(int argc, char *argv[]) {
    AnimalList* animalList = nullptr;
    readAnimalList(INPUT_FILE_NAME, animalList);

    if (strcmp(argv[1], "-b") == 0) {
        //cout << "Chua lam duoc" << endl;
        printAnimalList(animalList);
    } else if (strcmp(argv[1], "-c") == 0) {
        //cout << "Chua lam duoc" << endl;
        printAnimalInvalid(animalList);
    } else if (strcmp(argv[1], "-d") == 0) {
        cout << "Chua lam duoc" << endl;
        //questionD(OUTPUT_FILE_NAME, animalList);
    }

    removeAllList(animalList);

    return 0;
}

void readAnimal(ifstream &fin, Animal &animal) {
    fin >> animal.Type;
    fin >> animal.ID;
    fin >> animal.Weight;
}

void readAnimalList(const string &filename, AnimalList*& animalList) {
    ifstream fin(filename);

    if (fin) {
        animalList = new AnimalList;

        while (!fin.eof()) {
            Animal animal;
            readAnimal(fin, animal);
            add(animalList, animal);
        }
    }
}

void saveAnimal(ofstream& fout, Animal* animal) {
    if (animal != nullptr) {
        fout << animal->Type << " "
            << animal->ID << " "
            << animal->Weight;
    }
}

void questionD(const string &filename, AnimalList* animalList) {
    if (animalList != nullptr) {
        ofstream fout(filename);

        if (fout) {
            for (Animal* p = animalList->pFirst; p; p = p->pNext) {
                if (isValidAnimal(p)) {
                    if ((p->Type == 'C' && p->Weight > 2.5) || (p->Type == 'D' && p->Weight > 3)) {
                        printAnimal(p);
                        cout << endl;
                    }
       
                } else {
                    saveAnimal(fout, p);
                    
                    if (p->pNext != nullptr)
                        fout << endl;
                }
            }
        }
    }
}

Animal* makeNode(char type, const string &id, float weight) {
    Animal* animal = new Animal;
    animal->Type = type;
    animal->ID = id;
    animal->Weight = weight;
    animal->pNext = nullptr;

    return animal;
}

void add(AnimalList* &animalList, const Animal &animal) {
    if (animal.Type == 'C')
        addHead(animalList, animal);
    else 
        addTail(animalList, animal);
}

void addHead(AnimalList* &animalList, const Animal &animal) {
    if (animalList == nullptr)
        animalList = new AnimalList;

    Animal* p = makeNode(animal.Type, animal.ID, animal.Weight);
    if (animalList->pFirst == nullptr) {
        animalList->pFirst = animalList->pLast = p;
    } else {
        p->pNext = animalList->pFirst;
        animalList->pFirst = p;
    }
}

void addTail(AnimalList* &animalList, const Animal &animal) {
    if (animalList == nullptr)
        animalList = new AnimalList;

    Animal* p = makeNode(animal.Type, animal.ID, animal.Weight);
    if (animalList->pFirst == nullptr) {
        animalList->pFirst = animalList->pLast = p;
    } else {
        animalList->pLast->pNext = p;
        animalList->pLast = animalList->pLast->pNext;
    }
}

void removeAllList(AnimalList* &animalList) {
    if (animalList != nullptr) {
        Animal* p = animalList->pFirst;

        while (p != nullptr) {
            animalList->pFirst = animalList->pFirst->pNext;
            delete p;
            p = animalList->pFirst;
        }

        delete animalList;
        animalList = nullptr;
    }
}

void printAnimal(Animal* animal) {
    if (animal != nullptr) {
        cout << animal->Type << " "
            << animal->ID << " "
            << animal->Weight;
    }
}

void printAnimalList(AnimalList* animalList) {
    for (Animal* p = animalList->pFirst; p; p = p->pNext) {
        printAnimal(p);
        cout << endl;
    }
}

bool isValidAnimal(Animal* animal) {
    if (animal == nullptr)
        return false;

    if ((animal->Type != 'C' && animal->Type != 'D') || animal->ID.length() != 3)
        return false;
    if (animal->Weight < 0)
        return false;
    if (animal->Type == 'C' && (animal->Weight <= 1 || animal->Weight >= 3.5))
        return false;
    if (animal->Type == 'D' && (animal->Weight <= 1.5 || animal->Weight >= 5.5))
        return false;

    return true;
}

void printAnimalInvalid(AnimalList* animalList) {
    if (animalList != nullptr) {
        for (Animal* p = animalList->pFirst; p; p = p->pNext)
            if (!isValidAnimal(p))
                cout << p->Type << " " << p->ID << endl;
    }
}