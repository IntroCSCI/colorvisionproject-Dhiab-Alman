# C++ Palette Analyzer

## Description

This is a simple console application, it asks the user to write the name of the  file that in which the information of the colours will the be analyzed, first it promopts the user to provide any file name for the name in which he wants to analyze colour information. Then a loop will start and it takes information for all those colours one by one and they finally it will write that data to a .css file


## Developer

Dhiab almansoori

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

Enter Name of the file you want to open 
Color_1

**** File Found ****

*** Colours found in the file are ***
    #6D6968
    #726E6D
    #736F6E
    #837E7C
    #848482
    #B6B6B4
    #D1D0CE
    #E5E4E2
    #BCC6CC
    #98AFC7
    #6D7B8D
    #657383
    #616D7E
    #646D7E
    #566D7E
    #737CA1
    #4863A0
    #2B547E
    #2B3856
    #151B54
    #000080
    #342D7E
    #15317E
    #151B8D
    #0000A0
    #0020C2


*** Exiting File ***

## C++ Guide

### Variables and Data Types

Followind data types were used while making the program :
- Strings
- int
- char
- bool



### Decisions

a do while loop is used to create the file if condition inside the while loop returns zero the loop stops and an if statement check for the user input if he/she presses 'Y'. it will keep looping to create a file, a if conditionalso checks wheather the file is created or not

### Iteration

A do while loop checks for the condition(i.e., the desired file is created or not) if not true keeps iterating the loop

### File Input and Output

The output of file is written to a file which has a name of user's choice.

### Arrays/Vectors

A string array of colours keep record of all the colour values entered.

### Functions

A combination of if and else statements has been used to go through if the file is found or not and if it is found what should it display.

### Classes

*Coming in