# PPM File Viewer

<div align="center">
  <img width="612" alt="banner" alt="Screenshot 2025-01-16 at 7 26 09 AM" src="https://github.com/user-attachments/assets/34265db8-a57f-404a-9f76-0548b7e11eb8">
</div>

Displays ASCII (P3) PPM Files.

## Features

* **Click and Drag**: Pan around the image.
* **Mouse Wheel**: Zoom in and out for a closer look at pixel details.

## Requirements

* **C++ 17** or later
* **raylib**

For raylib installation instructions visit https://www.raylib.com/

## Build Instructions

**Using Makefile**
1. Clone the repository

```
git clone https://github.com/nasan016/PPM-Viewer.git
cd PPM-Viewer
```

2. Build the project:

```
make
```

3. Run the program:

```
./main <path-to-ppm-file>
```

*You may need to edit the path in Makefile to the location of your raylib installation.*

## Usage

Run the executable with a PPM file as the argument:

```
./main ppm/simple2x2.ppm
```
