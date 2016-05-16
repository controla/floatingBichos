#ifndef _BLAYER
#define _BLAYER

#include "ofMain.h"

class BLayer {
	public:
		void setup(string _path);
		void update(float _speed);
		void draw();

	float x;
	float y;

	int layersTotal;
	int layerOpacity;


	bool layerHasOpacity;
	bool layerHasScale;
	bool layerHasRotate;

	float layerScale;
	float layerScaleMin;
	float layerScaleMax;

	float layerAngle;
	int layerAngleMin;
	int layerAngleMax;

	float layerX;
	float layerY;

	ofImage Layer;

	BLayer();

private:

};

#endif
