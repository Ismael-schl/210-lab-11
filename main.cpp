// COMSC-210 | Lab 11 | Ismael Hadi
#include <iostream>
#include <string>

using namespace std;


struct Fish {
    double avgSize = 0.0;
    string color;
    string* diet = nullptr;
    int dietCount = 0;
    int dietCapacity = 0;
};

void addDiet(Fish &fish, const string &food);

Fish &addFish(Fish *&fishes, int &count, int &capacity, const string &color, double avgSize);

void printFish(const Fish *fishes, int count);

void freeFish(Fish *fishes, int count);

int main() {
    char ender = 'a';
    Fish* fishes = nullptr;
    int fishCount = 0;
    int fishCapacity = 0;
    
    Fish *f = &addFish(fishes, fishCount, fishCapacity, "orange", 3.5);
    addDiet(*f, "algae");
    addDiet(*f, "shrimp");
    addDiet(*f, "crabs");

    addFish(fishes, fishCount, fishCapacity, "blue", 1.2);

    f = &addFish(fishes, fishCount, fishCapacity, "brown", 0.8);
    addDiet(*f, "worms");

    printFish(fishes, fishCount);
    cout << "Would you like to learn about more fish? If yes, press y, then enter. Otherwise, press n, then enter.";
    cin >> ender;
    if (ender == 'n') {
        freeFish(fishes, fishCount);
        return 0;
    }
    
    f = &addFish(fishes, fishCount, fishCapacity, "green", 2.1);
    addDiet(*f, "krill");

    f = &addFish(fishes, fishCount, fishCapacity, "red", 3.3);
    addDiet(*f, "krill");
    
    addDiet(fishes[1], "minnows");
    printFish(fishes, fishCount);

    freeFish(fishes, fishCount);
    return 0;
}

void addDiet(Fish &fish, const string &food) {
    if (fish.dietCount == fish.dietCapacity) {
        int newCapacity = fish.dietCapacity;
        if (fish.dietCapacity == 0){
            newCapacity = 2;
        }
        else {
        newCapacity = fish.dietCapacity *2;
        }
        string *bigger = new string[newCapacity];
        for (int i = 0; i <fish.dietCount; i++) {
        bigger[i] = fish.diet[i];
        }
        delete[] fish.diet;
        fish.diet = bigger;
        fish.dietCapacity = newCapacity;
    }
    fish.diet[fish.dietCount] = food;
    fish.dietCount++;
}

Fish &addFish(Fish *&fishes, int &count, int &capacity, const string &color, double avgSize){
    int capacityNew = capacity;
    if (count == capacity) {
        if (capacity == 0){
            capacityNew = 2;
        }
        else {
        capacityNew = capacity *2;
        }
        Fish *bigger = new Fish[capacityNew];
        for (int i = 0; i <capacity; i++) {
        bigger[i] = fishes[i];
        }
        delete[] fishes;
        fishes = bigger;
        capacity = capacityNew;
    }
    fishes[count].color = color;
    fishes[count].avgSize = avgSize;
    count++;
    return fishes[count - 1];
}

void printFish(const Fish *fishes, int count) {
    for (int i = 0; i < count; i++) {
        cout << "Average size in feet: " << fishes[i].avgSize << endl;
        cout << "Fish color: " << fishes[i].color << endl;
        if (fishes[i].diet == nullptr) {
            cout << "No diet reported" << endl;
        }
        else {
            cout << "Fish diet: ";
                for (int j = 0; j < fishes[i].dietCount; j++) {
                cout << fishes[i].diet[j] << " ";
            }
            cout << endl;
    
        }
    }
}

void freeFish(Fish *fishes, int count) {
    for (int i = 0; i < count; i++) {
        delete[] fishes[i].diet;
    }
    delete[] fishes;
}