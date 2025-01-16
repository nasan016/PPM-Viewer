#include <fstream>
#include <iostream>
#include <sstream>
#include "PPM.h"

PPM::PPM(FileName infile) {
  fileName = infile;

  std::ifstream file(infile);

  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file\n";
    return;
  }

  std::string line;
  int iterator = 0;
  int idx = 0;

  while (std::getline(file, line)) {
    std::istringstream stream(line);

    std::istringstream checkComment(line);
    char comment; //this checks for a '#' and skips
    checkComment >> comment;

    if (comment == '#') continue;

    switch(iterator) {
      case 0:
        setHeader(line);
        break;

      case 1:
        ImageSize size;
        stream >> size[0] >> size[1];
        setSize(size);
        break;

      case 2:
        ColorRange range;
        stream >> range;
        setColorRange(range);
        break;
    }

    ++iterator;

    if (iterator > 3) {
      for (size_t i = 0; i < size[0]; ++i) {
        ColorArr arr;
        stream >> arr[0] >> arr[1] >> arr[2];
        createPixelMap(arr, idx);
      }
      ++idx;
    }

  }
}

void PPM::setHeader(const Header& _header) {
  header = _header;
}

void PPM::setSize(const ImageSize& _size) {
  size = _size;
}

void PPM::setColorRange(ColorRange _range) {
  range = _range;
}

void PPM::createPixelMap(const ColorArr& arr, int currRow) {
  if (currRow == pixMap.size()) {
    VectColorArr newVectColorArr;
    pixMap.push_back(newVectColorArr);
  }

  (pixMap[currRow]).push_back(arr);
}

void PPM::getPPM() const{
  std::cout << "Header: " << header << '\n';
  std::cout << "Size: " << size[0] << " x " << size[1] << '\n';
  std::cout << "Range: " << range << '\n';
  std::cout << '\n';
  std::cout << "Pixels:\n";

  for (const auto& vect : pixMap) {
    for (const auto& arr : vect) {
      std::cout << '(' << arr[0] << ',' << arr[1] << ',' << arr[2] << ')' << " ";
    }
    std::cout << '\n';
  }
}

RGBValues PPM::getPixelMap() const {
  return pixMap;
}

FileName PPM::getFileName() const {
  return fileName;
}
