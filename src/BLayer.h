#ifndef _BLAYER
#define _BLAYER

#include "ofMain.h"

class BLayer {
	public:
		void setup(string _path);
		void update();
		void draw();

	float x;
	float y;

	int layersTotal;
	int layerOpacity;

	bool layerHasOpacity;
	bool layerHasScale;
	bool layerHasRotate;

	float layerScale;
	float layerAngle;
	float layerX;
	float layerY;

	ofImage Layer;

	BLayer();

private:

};

#endif
