#ifndef _BLAYER
#define _BLAYER

#include "ofMain.h"

class BLayer {
	public:
		void setup(int layerId, string _layerpath, int lOpacity, int lScale, int lRotate, int lShy);
		void update(float _speed, float _scale, int _bichoOpacity);
		void draw();

	float x;
	float y;

	int layerSeed;

	int HasOpacity;
	int HasScale;
	int HasRotate;
	int isShy;

	int diff;
	int layerOpacity;
	float layerScale;
	float layerAngle;

	float layerX;
	float layerY;

	ofImage Layer;

	BLayer();

private:

};

#endif
