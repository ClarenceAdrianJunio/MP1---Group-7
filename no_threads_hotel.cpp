#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int rooms[50] = {0}; 
    int success_count = 0;

    ofstream outfile("booking_log.txt");

    srand(time(0));

    for (int i = 0; i < 100; ++i) {
        int room_id = rand() % 50;

        if (rooms[room_id] == 0) {
            rooms[room_id] = 1;
            success_count++;
            cout << "Booked room: " << room_id << endl;
            outfile << "Booked room: " << room_id << endl;
        } else {
            cout << "Failed to book room: " << room_id << " (already taken)" << endl;
            outfile << "Failed to book room: " << room_id << " (already taken)" << endl;
        }
    }

    cout << "Total bookings: " << success_count << "/100" << endl;
    cout << "Clarence Junio" << endl;

    outfile << "Total bookings: " << success_count << "/100" << endl;
    outfile << "Clarence Junio" << endl;
    outfile.close();

    return 0;
}