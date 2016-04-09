//
//  ofxIldaFrame.h
//  ofxIlda
//
//  Created by Memo Akten on 09/05/2013.
//  Updated by Mitsuru Takeuchi on 02/06/2013.
//

// a single ILDA frame, contains multiple polys
// coordinates are NORMALIZED (0...1, 0...1)

#pragma once

#include "ofMain.h"
#include "ofxIldaPoly.h"
#include "ofxIldaPoint.h"
#include "ofxIldaPolyProcessor.h"

namespace ofxIlda {

class Frame {
   public:
    struct {
        struct {
            bool lines;         // draw lines
            bool points;        // draw points
            bool pointNumbers;  // draw point numbers (not implemented yet)
        } draw;

        struct {
            ofFloatColor color;  // color
            int blankCount;      // how many blank points to send at path ends
            int endCount;        // how many end repeats to send
            bool doCapX;         // cap out of range on x (otherwise wraps around)
            bool doCapY;         // cap out of range on y (otherwise wraps around)
            struct {
                bool doFlipX;
                bool doFlipY;
                ofVec2f offset;
                ofVec2f scale;
            } transform;
        } output;
    } params;

    PolyProcessor polyProcessor;  // params and functionality for processing the polys

    struct {
        int pointCountOrig;       // READONLY current total number of points across all paths (excluding blanks and end repititons)
        int pointCountProcessed;  // same as above, except AFTER being processed
    } stats;

    Frame();

    void setDefaultParams();

    string getString();

    void update();
    void draw(float x = 0, float y = 0, float w = 0, float h = 0);
    void clear();

    int size();

    Poly &addPoly(const Poly &poly);
    Poly &addPoly();
    Poly &addPoly(const ofPolyline &polyline);
    Poly &addPoly(const ofPolyline &polyline, ofFloatColor color);
    Poly &addPoly(const vector<ofPoint> points);
    Poly &addPoly(const vector<ofPoint> points, ofFloatColor color);
    void addPolys(const vector<ofPolyline> &polylines);
    void addPolys(const vector<ofPolyline> &polylines, ofFloatColor color);
    void addPolys(const vector<Poly> &polys);

    Poly &getPoly(int i);
    Poly &getPolyProcessed(int i);
    vector<Poly> &getPolys();
    vector<Poly> &getProcessedPolys();
    Poly &getLastPoly();
    const vector<Point> &getPoints() const;

    void drawCalibration();

    ofPoint transformPoint(ofPoint p) const;

    void updateFinalPoints();

   protected:
    vector<Poly> origPolys;       // stores the original polys
    vector<Poly> processedPolys;  // stores the processed (smoothed, collapsed, optimized, resampled etc).
    vector<Point> points;         // final points to send
};
}