# !!!Replace with your unique project name!!!
css Palette Analyzer
## Description

so what this program does so far is that it asks you for the file that you want to analyze/open. Then it reads through the file and finds the colour codes in that file and displays them. Later on I will program it to actually analyze those colour codes and tells you if this colour could be problamatic.

### v0.2 Updates

*Coming soon*

### v1.0 Updates

*Coming soon*


## Developer

Dhiab almansoori

## Example

To run the program, give the following commands:
The file name that should be analyzed
```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

Please type the name of the file to open:
css_example

#D9D9D9
#00AAFF
#00AAFF
#00AAFF
#00AAFF
#00AAFF
#00AAFF
#00AAFF
#00AAFF
```
```

## C++ Guide

### Variables and Data Types

Variables and data types in this program is designed to capture the information under a clear name that we can use throughout the program and as an example we have
  string color;
    string filename;
    and   ifstream reader; to use as a reader

### Console Input and Output

The input and output of this program is simplistic and straight forword.
In line 13 after the output asks for the filename, the input after is captured as filename. Moreover, the output displays the colour value in the end so that you can analyze it


### Decisions

Decisions in this program is used to type "#" after identifying a colour code using while loops.
 if (line[position]) {
          cout << '#';

### Iteration

Like I said previously while loops is used in this program to identify colour codes by finding codes that starts with a "#", and "#" is usually used to identify a colourcode


### File Input and Output

Files input is used in this program to open the filename that is listed by the user which I used as an example with the file (css_example)


### Arrays/Vectors

*Coming in version 0.2*

### Functions

*Coming in version 0.2*

### Classes

*Coming in version 1.0*
