#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
float total_temp = 0.0;

void compute_sum(float temps[], int start, int end) {
    float sum = 0.0;
    for (int i = start; i < end; i++) {
        sum += temps[i];
    }

    mtx.lock();
    total_temp += sum;
    mtx.unlock();
}

void run_test(float temps[], int size) {
    total_temp = 0.0;

    if (size == 0) {
        cout << "\n Error: No temperature data provided!" << endl;
        return;
    }

    int part = size / 4;

    thread t1(compute_sum, temps, 0, part);
    thread t2(compute_sum, temps, part, part * 2);
    thread t3(compute_sum, temps, part * 2, part * 3);
    thread t4(compute_sum, temps, part * 3, size);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    float avg = total_temp / size;
    cout << "\nAverage temperature: " << avg << "°C" << endl;
    cout << "Clarence Adrian M. Junio" << endl;
}

int main() {
    float temps[10000];

    // General Output
    srand((time(0)));
    for (int i = 0; i < 10000; i++) temps[i] = (rand() % 101) - 50;
    run_test(temps, 10000);

    // All 10°C
    for (int i = 0; i < 10000; i++) temps[i] = 10.0;
    run_test(temps, 10000);

    // Alternating -10°C and 10°C
    for (int i = 0; i < 10000; i++) temps[i] = (i % 2 == 0) ? -10.0 : 10.0;
    run_test(temps, 10000);

    // Random with fixed seed
    srand(42);
    for (int i = 0; i < 10000; i++) temps[i] = (rand() % 101) - 50;
    run_test(temps, 10000);

    // Empty input
    run_test(temps, 0);

    return 0;
}
