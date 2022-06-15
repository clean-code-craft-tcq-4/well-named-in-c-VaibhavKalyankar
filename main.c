#include <stdio.h>
#include <assert.h>
#include "PrintManual.h"


void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    
  //  printf("%s %s\n",MajorColorNames[colorPair->majorColor],MinorColorNames[colorPair->minorColor]);
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Color Pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

int main() {
    int MajorColorValue,MinorColorValue,PairNumber;
    for(MajorColorValue=WHITE;MajorColorValue<=VIOLET;MajorColorValue++)
    {
        for(MinorColorValue=BLUE;MinorColorValue<=SLATE;MinorColorValue++)
        {
            PairNumber++;
            testNumberToPair(PairNumber, MajorColorValue, MinorColorValue);
            testPairToNumber(MajorColorValue, MinorColorValue, PairNumber);
        }
    }
  /*  testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
*/
    return 0;
}
