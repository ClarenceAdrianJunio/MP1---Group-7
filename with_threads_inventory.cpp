#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <mutex>
using namespace std;

const int NUM_PRODUCTS = 1000;
vector<int> stocks(NUM_PRODUCTS);
int lowStockCount = 0;
mutex mtx;

void checkStocks(int start, int end) {
    for (int i = start; i <= end; ++i) {
        if (stocks[i] < 10) {
            lock_guard<mutex> lock(mtx);
            cout << "[ALERT] Product " << i << ": " << stocks[i] << " units left" << endl;
            ++lowStockCount;
        }
    }
}

void runThreadsCheck() {
    thread t1(checkStocks, 0, 249);
    thread t2(checkStocks, 250, 499);
    thread t3(checkStocks, 500, 749);
    thread t4(checkStocks, 750, 999);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << "Total low-stock items: " << lowStockCount << endl;
    cout << "Checked by: Deanne Yzabelle E. Centeno" << endl;
}

int main() {
    int choice;
    cout << "Select stock input mode:\n";
    cout << "1. All stock = 100 (No alerts expected)\n";
    cout << "2. All stock = 5 (All products trigger alerts)\n";
    cout << "3. Mixed stock (random values)\n";
    cout << "4. Manual input\n";
    cout << "Enter choice (1-4): ";
    cin >> choice;

    lowStockCount = 0;

    if (choice == 1) {
        for (int i = 0; i < NUM_PRODUCTS; ++i) stocks[i] = 100;
    }
    else if (choice == 2) {
        for (int i = 0; i < NUM_PRODUCTS; ++i) stocks[i] = 5;
    }
    else if (choice == 3) {
        srand(time(0));
        for (int i = 0; i < NUM_PRODUCTS; ++i) {
            stocks[i] = rand() % 101;
        }
    }
    else if (choice == 4) {
        cout << "Enter stock for " << NUM_PRODUCTS << " products (0-100):\n";
        for (int i = 0; i < NUM_PRODUCTS; ++i) {
            int inputStock;
            cin >> inputStock;
            if (inputStock < 0) inputStock = 0;
            if (inputStock > 100) inputStock = 100;
            stocks[i] = inputStock;
        }
    }
    else {
        cout << "Invalid choice. Exiting.\n";
        return 1;
    }

    runThreadsCheck();

    return 0;
}

