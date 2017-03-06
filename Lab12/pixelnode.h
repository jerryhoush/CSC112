#ifndef PIXELNODE_H
#define PIXELNODE_H
#include "pixel.h"
#include <iostream>
using namespace std;

struct PixelNode
{
   PixelNode(Pixel value=0, PixelNode* next=0): value_(value), next_(next){}
   Pixel value_;
   PixelNode* next_;
};

#endif
