#include<stdio.h>
#include "main.h"
void ColorPairToString(const ColorPair*, char*);
void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",MajorColorNames[colorPair->majorColor],MinorColorNames[colorPair->minorColor]);
}
