#include "PPM.h"
#include "renderer.h"

int main() {
  PPM newPPM = PPM("map.ppm");
  initScreen(newPPM);

  return 0;
}
