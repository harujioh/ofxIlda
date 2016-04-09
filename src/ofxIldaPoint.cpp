#include "ofxIldaPoint.h"

//--------------------------------------------------------------
void ofxIlda::Point::set(int16_t x, int16_t y) {
    this->x = x;
    this->y = y;
}

//--------------------------------------------------------------
void ofxIlda::Point::set(int16_t x, int16_t y, int16_t r, int16_t g, int16_t b, int16_t a) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

//--------------------------------------------------------------
// set color and position mapped from custom range (defaults to normalized)
void ofxIlda::Point::set(ofPoint p, ofFloatColor c, ofPoint pmin, ofPoint pmax) {
    set(ofMap(p.x, pmin.x, pmax.x, kIldaMinPoint, kIldaMaxPoint), ofMap(p.y, pmin.y, pmax.y, kIldaMinPoint, kIldaMaxPoint), c.r * kIldaMaxIntensity, c.g * kIldaMaxIntensity, c.b * kIldaMaxIntensity,
        c.a * kIldaMaxIntensity);
}

//--------------------------------------------------------------
// set position mapped from custom range (defaults to normalized)
void ofxIlda::Point::setPosition(ofPoint p, ofPoint pmin, ofPoint pmax) { set(ofMap(p.x, pmin.x, pmax.x, kIldaMinPoint, kIldaMaxPoint), ofMap(p.y, pmin.y, pmax.y, kIldaMinPoint, kIldaMaxPoint)); }

//--------------------------------------------------------------
// gets position of point mapped to desired range (defaults to normalized)
ofPoint ofxIlda::Point::getPosition(ofPoint pmin, ofPoint pmax) { return ofPoint(ofMap(x, kIldaMinPoint, kIldaMaxPoint, pmin.x, pmax.x), ofMap(y, kIldaMinPoint, kIldaMaxPoint, pmin.y, pmax.y)); }