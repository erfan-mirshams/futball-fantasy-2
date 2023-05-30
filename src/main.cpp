#include "../include/general.h"
#include "../include/io.h"
#include "../include/system.h"

int main() {
  System sys;
  sys.readPremierLeagueInfo();
  sys.readWeeksInfo();
  return 0;
}
