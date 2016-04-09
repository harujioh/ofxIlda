#include "ofxIldaPoly.h"

void ofxIlda::Poly::setFromPolyline(const ofPolyline& polyline) {
    ofFloatColor tmpColor = color;
    *this = polyline;
    color = tmpColor;
}