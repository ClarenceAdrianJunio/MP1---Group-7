#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

float total_temp = 0;

void generate_Temp(int num_steps){
    cout << "\nGenerating... " << endl;
    for (int i = 0; i < num_steps; i++){
        float generated_temp = (rand() % 101) - 50;
        cout << "Generated Temp #" << i + 1 << ": " << generated_temp << "°C" << endl;
        total_temp += generated_temp;  
    }
}
int main(){
    float avg_temp;
    srand(time(0));
    
    generate_Temp(10000);
    
    avg_temp = total_temp / 10000;
    
    cout << "\nAverage temperature: " << avg_temp << "°C" << endl;
    cout << "Clarence Adrian M. Junio";
    
    return 0;
}
