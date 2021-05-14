# C++ Palette Analyzer

## Description

This program analyzes the colors used in the css file. It checks for the commonly used colors in the 
file and consider them as the color palette of the file. It then checks the color combination is good
for several color blindlness condition

### v0.2 Updates

Added Arrays/Vectors,Functions and rearrenged the project. Along with some bug fixes.

### v1.0 Updates

Reprogrammed the whole project and added classes and managed the codes along side a explaination on everything.


## Developer

Dhiab Almansoori

## Example

To run the program, give the following commands:


g++ --std=c++11 *.cpp -o cvp
./cvp


Here is an example of the program running:


Please enter file name: readme_example

The colors in the palette are
  HEX   COUNT
E7E7E7 1

Analysis:
There are 1 unique colors.

Commonly Used Colors:
  HEX   COUNT
E7E7E7   1
000000   0
000000   0
000000   0
000000   0
000000   0
000000   0
000000   0

Color Blindness Test
   CONDITION    RESULT
Protanopia    : Failed       
Protanomaly   : Failed       
Deuteranopia  : Failed       
Deuteranomaly : Failed       
Tritanopia    : Failed       
Tritanomaly   : Failed       
Achromatopsia : Failed       
Achromatomaly : Failed


## C++ Guide

### Variables and Data Types

Variables and custom classes were used to contain the important information of the color
such as its components: red, green, and blue.

### Console Input and Output

We used cout and cin extensively throughout the program to get user input and display the 
output of the program. We also used printf for cases where there is a special requirement
for the formatting.

### Decisions

If and else constructs are used to provide proper manipulation of the user input and
the color values.

### Iteration

While and for loops are used to read each word in the css file to extract the colors and 
analyze each. These loops were also used to prevent duplication of colors in the vector.

### File Input and Output

With the help of fstream library, we were able to read the css file and perform operation on it.
The fstream library offers a cout/cin style of accessing data in the file.

### Arrays/Vectors

I used vectors to store the colors inside the chosen file from the user. The Arrays is used to list the common color names used in css and their corresponding color values in hex.

### Functions

Functions is used to check if a color is existing in the color table and include that color if it is not in the color table

### Classes

Classes was used to store the important information of the colour such as its components: RGB and to define if colours are equal or not.