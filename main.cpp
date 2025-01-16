#include <iostream>
#include "PPM.h"
#include "renderer.h"

int main(int argc, char* argv[]) {

  if (argc < 2) {
    std::cout << "Usage: ./main <FILENAME>\n";
    return 1;
  } else if (argc > 2) {
    std::cout << "Too many arguments provided.\n";
    return 1;
  }

  PPM newPPM = PPM(argv[1]);
  initScreen(newPPM);
  newPPM.getPPM();
  return 0;
}
