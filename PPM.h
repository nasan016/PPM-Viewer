#ifndef PPM_H
#define PPM_H

#include <array>
#include <string>
#include <vector>

using RGBValues = std::vector<std::vector<std::array<int, 3>>>;
using ImageSize = std::array<int, 2>;
using Header = std::string_view;
using ColorRange = int;
using ColorArr = std::array<int, 3>;
using Row = int;
using Column = int;

/*
 * RGBValues looks like this:
 * { 
 *  {[255, 255, 255], [255, 255, 255]}, 
 *  {[255, 255, 255], [255, 255, 255]} 
 * }
 */

class PPM {
  private:
    Header header;
    ImageSize size;
    ColorRange range; 
    RGBValues pixMap;
    Row row;
    Column col;

  public:
    void setHeader(Header _header);
    void setSize(const ImageSize& _size);
    void setColorRange(ColorRange _range);
    void createPixelMap(const ColorArr& arr);
};

#endif
