#ifndef TICKS_H
#define TICKS_H

#include <ctime>

static clock_t start;
static clock_t end;

inline void beginn() {
  start = clock();
}

inline void endd() {
  end = clock();
}

inline clock_t ticks() {
  return end-start;
}

#endif
