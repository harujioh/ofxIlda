//
//  ofxIldaPoint.h
//  ofxIlda
//
//  Created by Memo Akten on 09/05/2013.
//
//

#pragma once

#include "ofMain.h"

namespace ofxIlda {

#define kIldaMinPoint -32768
#define kIldaMaxPoint 32767
#define kIldaDimension (kIldaMaxPoint - kIldaMinPoint)
#define kIldaMaxIntensity 65535

class Point {
   public:
    Point() : x(0), y(0), r(0), g(0), b(0), a(0) {}
    Point(int16_t x, int16_t y, int16_t r = 0, int16_t g = 0, int16_t b = 0, int16_t a = 0) : x(x), y(y), r(r), g(g), b(b), a(a) {}
    Point(ofPoint p, ofFloatColor c, ofPoint pmin = ofPoint::zero(), ofPoint pmax = ofPoint::one()) { set(p, c, pmin, pmax); }
    Point(ofPoint p, ofPoint pmin = ofPoint::zero(), ofPoint pmax = ofPoint::one()) { setPosition(p, pmin, pmax); }

    int16_t x;
    int16_t y;
    uint16_t r;
    uint16_t g;
    uint16_t b;
    uint16_t a;
    uint16_t u1;  // what are these for? standard ILDA or just etherdream?
    uint16_t u2;

    void set(int16_t x, int16_t y);
    void set(int16_t x, int16_t y, int16_t r, int16_t g, int16_t b, int16_t a);
    void set(ofPoint p, ofFloatColor c, ofPoint pmin = ofPoint::zero(), ofPoint pmax = ofPoint::one());

    void setPosition(ofPoint p, ofPoint pmin = ofPoint::zero(), ofPoint pmax = ofPoint::one());

    ofPoint getPosition(ofPoint pmin = ofPoint::zero(), ofPoint pmax = ofPoint::one());
};
}