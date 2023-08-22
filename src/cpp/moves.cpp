#include "moveutils.hpp"

namespace hello {

void up(matrix &prev) {
  int c, p;
  for (int j = 0; j < 4; j++) {
    c = 0;
    p = 0;
    for (int i = 0; i < 4; i++) {
      if (prev[i][j] == 0)
        continue;
      if (p == 0)
        p = prev[i][j];
      else if (p == prev[i][j]) {
        prev[c][j] = 2 * p;
        c++;
        p = 0;
      } else {
        prev[c][j] = p;
        c++;
        p = prev[i][j];
      }
    }
    if (p != 0) {
      prev[c][j] = p;
      c++;
    }
    for (int i = c; i < 4; i++)
      prev[i][j] = 0;
  }
}

void down(matrix &prev) {
  int c, p;
  for (int j = 0; j < 4; j++) {
    c = 3;
    p = 0;
    for (int i = 3; i >= 0; i--) {
      if (prev[i][j] == 0)
        continue;
      if (p == 0)
        p = prev[i][j];
      else if (p == prev[i][j]) {
        prev[c][j] = 2 * p;
        c--;
        p = 0;
      } else {
        prev[c][j] = p;
        c--;
        p = prev[i][j];
      }
    }
    if (p != 0) {
      prev[c][j] = p;
      c--;
    }
    for (int i = 0; i <= c; i++)
      prev[i][j] = 0;
  }
}

void left(matrix &prev) {
  int c, p;
  for (int i = 0; i < 4; i++) {
    c = 0;
    p = 0;
    for (int j = 0; j < 4; j++) {
      if (prev[i][j] == 0)
        continue;
      if (p == 0)
        p = prev[i][j];
      else if (p == prev[i][j]) {
        prev[i][c] = 2 * p;
        c++;
        p = 0;
      } else {
        prev[i][c] = p;
        c++;
        p = prev[i][j];
      }
    }
    if (p != 0) {
      prev[i][c] = p;
      c++;
    }
    for (int j = c; j < 4; j++)
      prev[i][j] = 0;
  }
}

void right(matrix &prev) {
  int c, p;
  for (int i = 0; i < 4; i++) {
    c = 3;
    p = 0;
    for (int j = 3; j >= 0; j--) {
      if (prev[i][j] == 0)
        continue;
      if (p == 0)
        p = prev[i][j];
      else if (p == prev[i][j]) {
        prev[i][c] = 2 * p;
        c--;
        p = 0;
      } else {
        prev[i][c] = p;
        c--;
        p = prev[i][j];
      }
    }
    if (p != 0) {
      prev[i][c] = p;
      c--;
    }
    for (int j = 0; j <= c; j++)
      prev[i][j] = 0;
  }
}

}
