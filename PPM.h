#ifndef PPM_H
#define PPM_H

#include <array>
#include <string>
#include <vector>

using ColorArr = std::array<int, 3>;
using VectColorArr = std::vector<ColorArr>;
using RGBValues = std::vector<VectColorArr>;

using ImageSize = std::array<int, 2>;
using Header = std::string;
using ColorRange = int;
using FileName = std::string_view;

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
    FileName fileName;

    void setHeader(const Header& _header);
    void setSize(const ImageSize& _size);
    void setColorRange(ColorRange _range);
    void createPixelMap(const ColorArr& arr, int currRow);

  public:
    PPM(FileName infile);
    void getPPM();
};

#endif
