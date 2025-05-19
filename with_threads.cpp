#include <iostream>
#include <thread> 

using namespace std;


void PrintWords(const string& word) {
    for (int i = 0; i < 800; ++i) {
        cout << word << " ";
    }
}

int main() {
    thread t1(PrintWords, "Be brave ");
    thread t2(PrintWords, "Fortitude ");
    thread t3(PrintWords, "Excellence ");
    thread t4(PrintWords, "Uprightness ");

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << "Daniel M. Banaag " << endl;
    return 0;
}