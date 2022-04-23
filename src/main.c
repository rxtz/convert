/**
 * Angle Converter
 * @author rxtz
 * @date 2022-04-15
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  double a; // bebesita

  while (1) {
    char inp[16];
    printf("Angle: ");
    scanf("%s", inp);

    if ((a = strtod(inp, NULL))) {
      break;
    }
  }

  char unit = ' ';

  while (unit != 's' && unit != 'c' && unit != 'r') {
    printf("Sexagesimal/Centesimal/Radian [s/c/r]: ");
    scanf(" %s", &unit);
  }

  double sex, cen, rad;

  // Expression is not assignable. C++ valid
  // ((unit == 's') ? sex : (unit == 'c') ? cen : rad) = a;

  (unit == 's') ? sex = a : (unit == 'c') ? cen = a : (rad = a);

  if (unit != 's') {
    sex = (unit == 'c') ? cen * 9 / 10 : rad * 180;
  }
  if (unit != 'c') {
    cen = sex * 10 / 9;
  }
  if (unit != 'r') {
    rad = sex / 180;
  }

  printf("%.2lf°\n%.2lfᵍ\n%.2lfπ rad\n", sex, cen, rad);

  return 0;
}
