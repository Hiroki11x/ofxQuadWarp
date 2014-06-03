//
//  ofxQuadWarp.h
//  Created by lukasz karluk on 19/06/11.
//
//  nay added hack to invert on 2011/06/21
//
#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofxQuadWarp : public ofBaseApp
{
public: 
    
     ofxQuadWarp();
    ~ofxQuadWarp();
    
    void setup();
    
    void setPosition(float x, float y);
    void setAnchorSize(float value);
    
    void setSourceRect(ofRectangle rect);
    void setSourcePoints(vector<ofPoint> points);
    ofPoint* getSourcePoints();
    void setTargetRect(ofRectangle rect);
    void setTargetPoints(vector<ofPoint> points);
    ofPoint* getTargetPoints();
    void setMatrix(ofMatrix4x4 matrix);
    
    void enable();
    void disable();
    
    void update();
    void reset();
    
    ofMatrix4x4 getMatrix();
    ofMatrix4x4 getMatrixInverse();
    ofMatrix4x4 getMatrix(ofPoint * srcPoints, ofPoint * dstPoints);
    
    void setCorners(vector<ofPoint> corners);
    void setCorner(ofPoint p, int cornerIndex);
    void setTopLeftCornerPosition(ofPoint p);
    void setTopRightCornerPosition(ofPoint p);
    void setBottomRightCornerPosition(ofPoint p);
    void setBottomLeftCornerPosition(ofPoint p);
    bool isCornerSelected(int cornerIndex) { return selectedCornerIndex == cornerIndex; }
    void setAnchorSize(int grabSize);

    void show();
    void hide();
    void toggleShow();
    
    void save(string path="quadwarp.xml");
    void load(string path="quadwarp.xml");
    void draw();
    void drawCorners();
    void drawQuadOutline();
    
    ofPoint srcPoints[4];
    ofPoint dstPoints[4];
    bool bShow;
    
protected:
    
    ofMatrix4x4 computedMatrix;
    bool firstStart;
    
    void onMousePressed(ofMouseEventArgs& mouseArgs);
    void onMouseDragged(ofMouseEventArgs &mouseArgs);
    void onMouseMoved(ofMouseEventArgs &mouseArgs);
    void onMouseReleased(ofMouseEventArgs& mouseArgs);
    void keyPressed(ofKeyEventArgs& keyArgs);
    
    ofPoint currentMouseLoc;
    
    ofPoint position;
    
	float anchorSize;
    float anchorSizeHalf;
    int selectedCornerIndex;
        int nearCornerIndex;
    
    bool bEnabled;

};
