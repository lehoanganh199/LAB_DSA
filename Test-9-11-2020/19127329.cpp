#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>

#define INPUT_FILE_NAME     "input.txt"
#define OUTPUT_FILE_NAME    "output.txt"

#define CHICKEN             'C'
#define DUCK                'D'

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


bool isChicken(char type);
bool isDuck(char type);
bool isValidTypeAnimal(char type);
bool isValidAnimal(Animal*);

bool readAnimal(ifstream&, Animal&);
void readAnimalList(const string &, AnimalList*&);
void outputAnimal(ostream&, Animal*);

Animal* makeNode(char, const string&, float);
Animal* toPointer(const Animal&);

void add(AnimalList*&, const Animal&);
void addHead(AnimalList*&, const Animal&);
void addMiddle(AnimalList*&, const Animal&); // between chicken and duck.
void addTail(AnimalList*&, const Animal&);

void removeList(AnimalList*&);

void printAnimalList(AnimalList*); // question b.
void printAnimalInvalid(AnimalList*); // question c.
void questionD(const string &, AnimalList*);


int main(int argc, char* argv[]) {
    AnimalList* animalList = nullptr;
    readAnimalList(INPUT_FILE_NAME, animalList);

    if (strcmp(argv[1], "-b") == 0)
        printAnimalList(animalList);
    else if (strcmp(argv[1], "-c") == 0)
        printAnimalInvalid(animalList);
    else if (strcmp(argv[1], "-d") == 0)
        questionD(OUTPUT_FILE_NAME, animalList);

    removeList(animalList);

    return 0;
}


bool isChicken(char type) {
    return type == CHICKEN;
}

bool isDuck(char type) {
    return type == DUCK;
}

bool isValidTypeAnimal(char type) {
    return isChicken(type) || isDuck(type);
}

bool isValidAnimal(Animal* animal) {
    if (animal == nullptr)
        return false;

    if ((isValidTypeAnimal(animal->Type == false)) || animal->ID.length() != 3)
        return false;
    if (animal->Weight < 0)
        return false;
    if (isChicken(animal->Type) && (animal->Weight <= 1 || animal->Weight >= 3.5))
        return false;
    if (isDuck(animal->Type) && (animal->Weight <= 1.5 || animal->Weight >= 5.5))
        return false;

    return true;
}

bool readAnimal(ifstream &fin, Animal &animal) {
    stringstream ss;
    string data;

    getline(fin, data);
    if (data == "\n" || data.empty())
        return false;

    ss << data;

    ss >> animal.Type
        >> animal.ID
        >> animal.Weight;

    return true;
}

void readAnimalList(const string &filename, AnimalList*& animalList) {
    ifstream fin(filename);

    if (fin) {
        if (animalList != nullptr)
            delete animalList;

        animalList = new AnimalList;

        while (!fin.eof()) {
            Animal animal;
            
            if (readAnimal(fin, animal) == false);
                break;

            add(animalList, animal);
        }

        fin.close();
    }
}

void outputAnimal(ostream &outDev, Animal* animal) {
    if (animal != nullptr) {
        outDev << animal->Type << " "
            << animal->ID << " "
            << animal->Weight;
    }
}

Animal* makeNode(char type, const string &id, float weight) {
    Animal* animal = new Animal;
    
    if (animal != nullptr) {
        animal->Type = type;
        animal->ID = id;
        animal->Weight = weight;
        animal->pNext = nullptr;
    }

    return animal;
}

Animal* toPointer(const Animal &animal) {
    return makeNode(animal.Type, animal.ID, animal.Weight);
}

void add(AnimalList* &animalList, const Animal &animal) {
    switch (animal.Type) {
    case CHICKEN:
        addHead(animalList, animal);
        break;
    case DUCK:
        addTail(animalList, animal);
        break;
    default:
        addMiddle(animaList, animal);
        break;
    }
}

void addHead(AnimalList* &animalList, const Animal &animal) {
    if (animalList == nullptr)
        animalList = new AnimalList;

    Animal* p = toPointer(animal);

    p->pNext = animalList->pFirst;
    animalList->pFirst = p->pNext;

    if (animalList->pLast == nullptr)
        animalList->pLast = animalList->pFirst;
}

void addMiddle(AnimalList* &animalList, const Animal &animal) {
    if (animalList == nullptr || animalList->pFirst == nullptr)
        addHead(animalList, animal);
    else {
        if (isDuck(animalList->pFirst->Type))
            addHead(animalList, animal);
        else if (isChicken(animalList->pLast->Type))
            addTail(animalList, animal);
        else {
            Animal* p = animalList->pFirst;

            while (p->pNext != nullptr && isDuck(p->pNext->Type) == false)
                p = p->pNext;

            Animal* next = p->pNext;
            p->pNext = toPointer(animal);
            p->pNext->pNext = next;
        }
    }
}

void addTail(AnimalList* &animalList, const Animal &animal) {
    if (animalList == nullptr)
        animalList = new AnimalList;

    Animal* p = toPointer(animal);
    if (animalList->pFirst == nullptr) {
        animalList->pFirst = animalList->pLast = p;
    } else {
        animalList->pLast->pNext = p;
        animalList->pLast = animalList->pLast->pNext;
    }
}

void removeList(AnimalList* &animalList) {
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

void printAnimalList(AnimalList* animalList) {
    for (Animal* p = animalList->pFirst; p; p = p->pNext) {
        outputAnimal(cout, p);
        cout << endl;
    }
}

void printAnimalInvalid(AnimalList* animalList) {
    if (animalList != nullptr) {
        for (Animal* p = animalList->pFirst; p; p = p->pNext)
            if (!isValidAnimal(p))
                cout << p->Type << " " << p->ID << endl;
    }
}

void questionD(const string &filename, AnimalList* animalList) {
    if (animalList != nullptr) {
        ofstream fout(filename);

        if (fout) {
            for (Animal* p = animalList->pFirst; p; p = p->pNext) {
                if (isValidAnimal(p)) {
                    if ((isChicken(p->Type) && p->Weight > 2.5) || (isDuck(p->Type) && p->Weight > 3)) {
                        outputAnimal(cout, p);
                        cout << endl;
                    } else {
                        outputAnimal(fout, p);
                        fout << endl;
                    }
                }
            }

            fout.close();
        }
    }
}
