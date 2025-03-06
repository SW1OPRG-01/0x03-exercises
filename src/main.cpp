#include <iostream>
#include "penalty_calculator.h"

using namespace std;

int main() {

  float speed_measurement = 0;
  int speed_limit = 0;
  int vehicle_type = 0;

  while(true) {
    cout << endl << "Vehicle type" << endl << "  (0) Cars (<=3.500 kg) and motorcycles" << endl << "  (1) Heavy vehicles (>3.500 kg) and cars with trailers (<=3.500 kg)" << endl << "Enter vehicle type: ";
    cin >> vehicle_type;

    if(vehicle_type != 0 && vehicle_type != 1) {
      cout << endl <<  "Invalid vehicle type" << endl; 
    } else {
      cout << "Enter speed limit: ";
      cin >> speed_limit;

      if(speed_limit_high(speed_limit) || speed_limit_normal(speed_limit)) {

        cout << "Enter speed measurement: ";
        cin >> speed_measurement;

        if(speed_measurement > speed_limit) {
          int violation = calculate_violation_percent(speed_measurement, speed_limit);
          int fine = calculate_fine(rate(speed_limit, vehicle_type), speed_measurement, speed_limit);
          int high_speed = 0;

          if(speed_measurement >= 140) {
            high_speed += calculate_high_speed_fine(speed_measurement);
          }

          if(speed_limit_normal(speed_limit) && violation >= 30) {
            high_speed += 1200;
          }

          cout << "Penalty: " << fine + high_speed << " (" << fine << " + " << high_speed << ")" << endl;
        }
      } else {
        cout << "Invalid speed limit" << endl;
      }
    }
  }
  return 0;
}
