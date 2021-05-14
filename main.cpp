// Palette Analyzer 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define PALETTE_SIZE  8
#define TESTBC(a,b) if (paletteTest(common, a)) printf("%-13s : %-13s\n", b, "Passed"); else printf("%-13s : %-13s\n", b, "Failed")

// Filter matrices for different types of colorblindedness
const double Normal[3][3] = { { 1.00, 0, 0 }, { 0, 1.00, 0 }, { 0, 1.00, 0 } };
const double Protanopia[3][3] = { { 0.56667, 0.43333, 0 }, { 0.55833, 0.44167, 0 }, { 0, 0.24167, 0.75833 } };
const double Protanomaly[3][3] = { { 0.81667, 0.18333, 0}, { 0.33333, 0.66667, 0 }, { 0, 0.125, 0.875 } };
const double Deuteranopia[3][3] = { { 0.625, 0.375, 0 }, { 0.70, 0.30, 0 }, { 0, 0.30, 0.70 } };
const double Deuteranomaly[3][3] = { { 0.80, 0.20, 0 }, { 0.25833, 0.74167, 0 }, { 0, 0.14167, 0.85833 } };
const double Tritanopia[3][3]  = { { 0.95, 5, 0 }, { 0, 0.43333, 0.56667 }, { 0, 0.475, 0.525 } };
const double Tritanomaly[3][3] = { { 0.96667, 0.03333, 0 }, { 0, 0.73333, 0.26667 }, { 0, 0.18333, 0.81667 } };
const double Achromatopsia[3][3] = { { 0.299, 0.587, 0.114 }, { 0.299, 0.587, 0.114 }, { 0.299, 0.587, 0.114 } };
const double Achromatomaly[3][3] { { 0.618, 0.32, 0.062 }, { 0.163, 0.775, 0.062 }, { 0.163, 0.320, 0.516 } };

// Color class to contain the rgb data
class Color {
    public:
        int r, g, b;
        Color();
        Color(string colorStr);
        Color(const Color& obj);
        ~Color();
        bool operator == (const Color& color) const;
        bool operator < (const Color& color) const;
        string str() const;  
        int hex() const;  
        Color filter(const double filt[3][3]) const;
};

// Type definitions
typedef vector<Color> CTABLE;
typedef vector<int>   CCOUNT;

// Method definition of colors
Color::Color(string colorStr) {
    string str = colorStr;

    if (str.length() < 6) { // check if the string has only three digits
        str = str[0];
        str += str[0];
        str += str[1];
        str += str[1];
        str += str[2];
        str += str[2];
    }

    r = stoi(str.substr(0, 2), nullptr, 16);
    g = stoi(str.substr(2, 2), nullptr, 16);
    b = stoi(str.substr(4, 2), nullptr, 16);
}

Color::Color() : r(0), g(0), b(0) {}    // Default constructor

Color::Color(const Color& obj) : r(obj.r), g(obj.g), b(obj.b) {}    // Copy constructor

Color::~Color() {}

int Color::hex() const {    // Get the hex equivalent of the color
    return (r << 16) | (g << 8) | (b);
}

bool Color::operator == (const Color& color) const {    // Check if two colors are equal
    return hex() == color.hex();
}

bool Color::operator < (const Color& color) const {     // Check if color is less than the color. Compared based on hex value.
    return hex() < color.hex();
}

string Color::str() const {
    char buff[256];
    sprintf(buff, "%02X%02X%02X", r, g, b);   
    return string(buff);
}

Color Color::filter(const double filt[3][3]) const {
    double rf, gf, bf;
    rf = filt[0][0] * r + filt[0][1] * g + filt[0][2] * b;
    gf = filt[1][0] * r + filt[1][1] * g + filt[1][2] * b;
    bf = filt[2][0] * r + filt[2][1] * g + filt[2][2] * b;
    
    Color filtered;
    filtered.r = rf;
    filtered.g = gf;
    filtered.b = bf;

    return filtered;
}

// Helper functions

bool appendColor(CTABLE& table, CCOUNT& cnt, Color& c) {
    for (size_t i = 0; i < table.size(); i++) {
        if (table[i] == c) {
            cnt[i]++;
            return true;
        }
    }

    table.push_back(c);
    cnt.push_back(1);
    return false;
}

bool paletteTest(Color palette[PALETTE_SIZE], const double filter[3][3]) {
    for (int i = 0; i < PALETTE_SIZE; i++) {
        for (int j = i + 1; j < PALETTE_SIZE; j++) {
            if (palette[i].filter(filter) == palette[j].filter(filter)) {
                return false;
            }
        }
    }
    return true;
}

// CSS color name values
const char* colorNames[] = {
    "black",
    "silver",
    "gray",
    "white",
    "maroon",
    "red",
    "purple",
    "fuchsia",
    "green",
    "lime",
    "olive",
    "yellow",
    "navy",
    "blue",
    "teal",
    "aqua"
};

// The equivalent hex value of the CSS color names
const char* colorValues[] = {
    "000000",
    "C0C0C0",
    "808080",
    "FFFFFF",
    "800000",
    "FF0000",
    "800080",
    "FF00FF",
    "008000",
    "00FF00",
    "808000",
    "FFFF00",
    "000080",
    "0000FF",
    "008080",
    "00FFFF"
};

int main() {

    string fname;
    ifstream file;

    cout << "Palette Analyzer" << endl;

    // Repeatedly ask the user for a file until it opens sucessfully
    do {
        cout << "Please enter file name: ";
        getline(cin, fname);
        file.open(fname);
    } while (!file.is_open());


    // Read the colors in the file
    string color;
    CTABLE colorTable; // this color table keeps track of the number of times the color is used in the file
    CCOUNT cCount;

    cout << endl << "The colors in the palette are" << endl;
    cout << "  HEX   COUNT" << endl;

    char ch;
    string keyword;
    Color c;

    while ((ch = file.get()) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') { // end of word
            if (keyword.length() > 0) {
                if (keyword[0] == '#') { // This is a color hex  
                    try {
                        c = Color(keyword.substr(1));
                        appendColor(colorTable, cCount, c);
                    } catch(const invalid_argument& ia) {}
                } else { // check color names
                    for (int i = 0; i < 16; i++) {
                        if (keyword == colorNames[i]) {
                            try {
                                c = Color(colorValues[i]);
                                appendColor(colorTable, cCount, c);
                            } catch(const invalid_argument& ia) {}
                            break; // stop the loop once found
                        }
                    }
                }

                keyword = "";
            }
        } else {
            keyword += ch;
        }
    }

    // Get Top 5 Most Used Colors in the file
    Color common[PALETTE_SIZE];
    int usage[PALETTE_SIZE] = {0};

    // Print out color table
    for (size_t i = 0; i < colorTable.size(); i++) {
        cout << colorTable[i].str() << " " << cCount[i] << endl;

        if (colorTable[i].hex() == 0x000000 || colorTable[i].hex() == 0xFFFFFF) // remove black and white from common colors
            continue;

        for (auto i = 0; i < PALETTE_SIZE; i++) {
            if (cCount[i] > usage[i]) { // replace
                usage[i] = cCount[i];
                common[i] = colorTable[i];
                break;
            }
        }
    }    

    // Test the palettes
    cout << endl << "Analysis:" << endl;
    cout << "There are " << colorTable.size() << " unique colors." << endl;

    // Get commonly used colors
    cout << endl << "Commonly Used Colors:" << endl;
    cout << "  HEX   COUNT" << endl;
    for (auto i = 0; i < PALETTE_SIZE; i++) {
        cout << common[i].str() << "   " << usage[i] << endl;
    }

    // Color blindness test
    cout << endl << "Color Blindness Test" << endl;
    cout << "   CONDITION    RESULT" << endl;
    TESTBC(Protanopia, "Protanopia");
    TESTBC(Protanomaly, "Protanomaly");
    TESTBC(Deuteranopia, "Deuteranopia");
    TESTBC(Deuteranomaly, "Deuteranomaly");
    TESTBC(Tritanopia, "Tritanopia");
    TESTBC(Tritanomaly, "Tritanomaly");
    TESTBC(Achromatopsia, "Achromatopsia");
    TESTBC(Achromatomaly, "Achromatomaly");

    return 0;
}