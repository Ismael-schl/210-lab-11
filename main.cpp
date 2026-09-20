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
    int count = 0;
    cout << "Enter the number of fish caught below, then press enter.";
    cin >> count;
    

    void freeFish(Fish *fishes, int count)
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
        cout << "Average size: " << fishes[i].avgSize << endl;
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