#ifndef _BLAYER
#define _BLAYER

#include "ofMain.h"

class BLayer {

public: 

	void setup(string _path);
	void update(float _x, float _y);
	void draw();

	float x;
	float y;

	float speedX;
	float speedY;

	int layersTotal;

	ofImage Layer;

	BLayer();

private:

};

#endif