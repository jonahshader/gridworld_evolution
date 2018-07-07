#pragma once
#include "ofMain.h"

class PanningCamera : public ofCamera {
public:
	PanningCamera();
	virtual ~PanningCamera();

private:
	bool pMousePressed;
	int pMouseX, pMouseY;
	int scrollCenterX, scrollCenterY;
};