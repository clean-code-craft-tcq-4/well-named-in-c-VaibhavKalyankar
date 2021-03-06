#include <stdio.h>
#include <assert.h>
#include "main.h"
int main() {
    int MajorColorValue,MinorColorValue,PairNumber;
    for(MajorColorValue=WHITE;MajorColorValue<=VIOLET;MajorColorValue++)
    {
        for(MinorColorValue=BLUE;MinorColorValue<=SLATE;MinorColorValue++)
        {
            PairNumber++;
            TestNumberToPair(PairNumber, MajorColorValue, MinorColorValue);
            TestPairToNumber(MajorColorValue, MinorColorValue, PairNumber);
        }
    }
    return 0;
}
void ColorPairToString(const ColorPair* colorpair,char * buffer)
{
    sprintf(buffer,"%s %s",MajorColorNames[colorpair->majorColor],MinorColorNames[colorpair->minorColor]);    
}
ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}
int GetPairNumberFromColor(const ColorPair * colorPair)
{
    return colorPair->majorColor * numberOfMinorColors  + colorPair->minorColor + 1;
}
void TestNumberToPair(int pairNumber,enum MajorColor expectedMajor,enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Color Pair: %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}
void TestPairToNumber(enum MajorColor major,enum MinorColor minor,int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}
