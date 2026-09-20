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

string* addDiet(string* diet);

Fish &addFish(Fish *&fishes, int &count, int &capacity, const string &color, double avgSize);

int main() {
    
}

string* addDiet(string* diet) {
    string food;
    cout >> "What does this fish eat? Enter an item then press enter, then press 1. When complete, press 0";
    while ()
}
