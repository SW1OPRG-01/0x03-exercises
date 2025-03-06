#include "penalty_calculator.h"

using namespace std;

double calculate_violation_percent(float speed_measurement, int speed_limit) {
  return abs(speed_measurement - speed_limit) / (speed_limit) * 100;
}

int calculate_fine(vector<int> fines, float speed_measurement, int speed_limit) {
  return fines[calculate_violation_percent(speed_measurement, speed_limit) / 10  - 1];
}

int calculate_high_speed_fine(int value) {
    return 1200 + ((value - 140) / 10) * 600;
}

bool speed_limit_high(int speed_limit) {
  return speed_limit == 100 || speed_limit == 110 || speed_limit == 120 || speed_limit == 130;
}

bool speed_limit_normal(int speed_limit) {
  return speed_limit == 30 || speed_limit == 40 || speed_limit == 45 || speed_limit == 50 || speed_limit == 60 || speed_limit == 70 || speed_limit == 80 || speed_limit == 90;
}

vector<int> rate(int speed_limit, int vehicle_type) {

  vector<int> rate_1 = { 1200, 1800, 1800, 2400, 2400, 3000, 3600, 4200, 5400, 6000 };
  vector<int> rate_2 = { 1200, 1800, 2400, 3000, 3600, 4200, 5400, 6000, 7800, 9000 };
  vector<int> rate_3 = { 1800, 1800, 2400, 3000, 3600, 4200, 5400, 6000, 7800, 9000 };

  if(vehicle_type == 0) {
    if(speed_limit_high(speed_limit)) {
      return rate_2;
    } else {
      return rate_1;
    }
  } else {
    return rate_3;
  }
}