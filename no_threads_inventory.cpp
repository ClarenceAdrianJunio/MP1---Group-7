#include <iostream>
#include <vector>
#include <cstdlib>   
#include <ctime>     
using namespace std;

int main() {
    const int NUM_PRODUCTS = 1000;
    vector<int> stocks(NUM_PRODUCTS);
    int lowStockCount = 0;

    srand(time(0));

    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        stocks[i] = rand() % 101; 
        if (stocks[i] < 10) {
            cout << "[ALERT] Product " << i << ": " << stocks[i] << " units left" << endl;
            ++lowStockCount;
        }
    }

    cout << "Total low-stock items: " << lowStockCount << endl;
    cout << "Checked by: Deanne Yzabelle E. Centeno" << endl;
    return 0;
}

