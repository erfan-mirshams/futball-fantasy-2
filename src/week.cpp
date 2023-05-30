#include "../include/week.h"

Week::Week() {}

Week::~Week() {
  for (auto g : games) {
    delete g;
  }
}
