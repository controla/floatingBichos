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

	ofImage Layer;

	BLayer();

private:

};

#endif
