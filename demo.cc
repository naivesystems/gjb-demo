#include <cstdlib>

void useAfterFree(int* p) {
  free(p);
  int k = *p;  // Defect
}

int badIfElse(int num) {
  if (num >= 0) {
    return -num;
  } else
    ;
  return num;
}

int goodIfElse(int num) {
  if (num >= 0) {
    return -num;
  } else {
    ; /* no deal with */
  }
  return num;
}

void infiniteLoop() {
  int counter;
  for (;;) {
    if (counter > 10) {
      break;
    }
  }

  counter = 0;
  while (1) {
    if (counter > 10) {
      break;
    }
  }
}

int unreachable(int flag) {
  int x = 1, y = 2, z = 3;
  switch (flag) {
    x = 5;
    case 0:
      x++;
      break;
    case 1:
      y++;
      break;
    case 2:
      z++;
    default:
      break;
  }
  return (0);
}

bool* isOpposite(int num1, int num2) {
  bool ifOpposite = num1 + num2 == 0;
  return &ifOpposite;
}

int main(void) {
  (void)infiniteLoop();

  int num1 = 1, num2 = -1;
  int num3 = 10 / (num1 + num2);
  bool* (*p)(int, int) = isOpposite;
  bool* ifOpposite = p(num1, num2);

  return 0;
}
