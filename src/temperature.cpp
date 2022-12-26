/**
 * temperature
 * @author rxtz
 * @date 2021-03-03
 */

#include <iostream>
#include <limits>
#include "colors.h"

using namespace std;

int main(int argc, char *argv[]) {
  long double temp, c, f, k;
  char unit = ' ';

  if (argc > 2) {
    temp = stod(argv[1]);
    unit = argv[2][0];
  }
  else {
  input:

    cout << "Temperature: " GREEN;
    cin >> temp;
    cout << RESET;

    while (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      goto input;
    }

    while (unit != 'c' && unit != 'f' && unit != 'k') {
      cout << "Celsius/Fahrenheit/Kelvin [c/f/k]: " GREEN;
      cin >> unit;
      cout << RESET;
      unit = (char) tolower(unit);
    }
  }

  ((unit == 'c') ? c : (unit == 'f') ? f : k) = temp;

  if (unit != 'c') {
    c = (unit == 'f') ? (f - 32) * 5 / 9 : k - 273.15;
  }
  if (unit != 'f') {
    f = c * 9 / 5 + 32;
  }
  if (unit != 'k') {
    k = c + 273.15;
  }

  if (argc == 4 && argv[3][0] == '-') {
    cout << c << "c " << f << "f " << k << "k" << endl;
    return 0;
  }

  if (c <= 0) {
    cout << CYAN "Freezing" RESET << endl;
  }
  if (c >= 100) {
    cout << RED "Boiling" RESET << endl;
  }
  if (k == 0) {
    cout << YELLOW "Absolute zero" RESET << endl;
  }

  cout << c << " °C" << endl
    << f << " °F" << endl
    << k << " K" << endl;

  return 0;
}
