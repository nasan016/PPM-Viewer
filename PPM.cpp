#include "PPM.h"

void PPM::setHeader(Header _header) {
  header = _header;
}

void PPM::setSize(const ImageSize& _size) {
  size = _size;
}
void PPM::setColorRange(ColorRange _range) {
  range = _range;
}

void PPM::createPixelMap(const ColorArr& arr) {
  static int curr_row = 0;
}
