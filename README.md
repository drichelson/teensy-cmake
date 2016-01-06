# teensy-cmake
Mac only! help make this work on other platforms.
teensy-cmake is a template for Teensy projects that uses CMake to build your sketches.
It is forked from https://github.com/xya/teensy-cmake and is intended to be simpler and also it works on Mac OS.
This lets you develop for Teensy using your favorite text editor and terminal. 
I use Clion: https://www.jetbrains.com/clion/ which can easily import CMake projects. 
CLion is a great IDE and even has a Serial console plugin available so you never need to open the Arduino IDE again.

This has been tested on Mac OS 10.11.2 with a Teensy 3.2
# Requirements- install newer/older versions at your peril!

 * Install homebrew if you don't have it: http://brew.sh/
 * Cmake. To install run ```brew install cmake```
 * XCode (perhaps not needed, but it typically installs a variety of useful tools)
 * Arduino 1.6.7: https://www.arduino.cc/download_handler.php?f=/arduino-1.6.7-macosx.zip
 * Teensyduino 1.27: https://www.pjrc.com/teensy/td_127/teensyduino.dmg
 * TyQT (https://github.com/Koromix/ty) 0.7.0 prerelease: https://www.dropbox.com/s/du62rjurw1mdg75/TyQt-0.6.3-250-g0a71b13-osx.dmg?dl=0 discussed here: https://forum.pjrc.com/threads/27825-Teensy-Qt?p=90594&viewfull=1%23post90594

Once all the above items have been installed it is probably a good idea to test out your Teensy with the Arduino app. Try uploading an example sketch.

Create a build directory:

# Building

```bash
mkdir build
cd build
```

Run CMake:
```bash
cmake ..
```

Build with:
```bash
make -j main
```

# Flashing sketches to the Teensy
```bash
make -j main_Upload
```

# Custom configuration

For some sketches, the Teensy needs to run in a different 'USB mode'. You can set this in the sketch's CMakeLists.txt file:

```
set(TEENSY_USB_MODE MIDI)

add_teensy_executable(...)
```

You can set the 'default' mode in the CMake GUI ('TEENSY_USB_MODE' variable).

# Importing libraries

Here is a simple example of how to import a library:

```
import_arduino_library(Bounce)

add_teensy_executable(...)
```
