//
//  ofxIldaPolyProcessor.h
//  ofxILDA demo
//
//  Created by Memo Akten on 21/05/2013.
//
//

#pragma once

#include "ofMain.h"
#include "ofxIldaPoly.h"

namespace ofxIlda {
class PolyProcessor {
   public:
    struct {
        int smoothAmount;         // how much to smooth the path (zero to ignore)
        float optimizeTolerance;  // howmuch to optimize the path, based on curvature (zero to ignore)
        bool collapse;            // (not implemented yet)
        int targetPointCount;     // how many points in total should ALL paths in this frame be resampled to (zero to ignore)
        float spacing;            // desired spacing between points. Set automatically by targetPointCount, or set manually. (zero to ignore)
    } params;

    PolyProcessor();

    string getString();

    void update(const vector<Poly> &origPolys, vector<Poly> &processedPolys);
};
}