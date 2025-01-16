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
using FileName = std::string;

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
    bool fileOpen { true };
    PPM(FileName infile);
    FileName getFileName() const;
    RGBValues getPixelMap() const;
    void getPPM() const;
};

#endif
