#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>
using namespace std;

int rooms[50] = {0};
int successCount = 0;
mutex mtx;
ofstream file("parallel_hotel_bookings.txt");

void bookRooms(int count) {
    for (int i = 0; i < count; i++) {
        int room = rand() % 50;
        mtx.lock();
        if (rooms[room] == 0) {
            rooms[room] = 1;
            cout << "Booked room: " << room << endl;
            file << "Booked room: " << room << endl;
            successCount++;
        } else {
            cout << "Failed to book room: " << room << " (already taken)" << endl;
            file << "Failed to book room: " << room << " (already taken)" << endl;
        }
        mtx.unlock();
    }
}

int main() {
    srand(42); // Consistent results
    thread t1(bookRooms, 1, 50);
    thread t2(bookRooms, 25);
    thread t3(bookRooms, 25);
    thread t4(bookRooms, 25);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    file.close();
    cout << "Total bookings: " << successCount << "/100" << endl;
    cout << "Daniel" << endl;
    return 0;
}
