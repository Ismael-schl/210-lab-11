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

int main() {
    
}

void addDiet(Fish &fish, const string &food) {
    if (fish.dietCount == fish.dietCapacity) {
        int newCapacity = fish.dietCapacity;
        if (fish.dietCapacity == 0){
            newCapacity = 2;
        }
        else 
        newCapacity = fish.dietCapacity *2;
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
