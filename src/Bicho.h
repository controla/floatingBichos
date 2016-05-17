#ifndef _BICHO
#define _BICHO

#include "BLayer.h"
#include "ofMain.h"

#define MAXLAYERS 20

class Bicho {
	public:
		void setup(string _bichoPath);
		void update(float _speed, float _posx, float _posy, float _offset, float _scalemin, float _scalemax);
		void draw();
		void remove();

	float bichoX;
	float bichoY;

	bool isFadingOut;
	bool isFadingIn;
	bool isAlive;

	bool bichoHasScale = true;
	float bichoScale;

	int layersTotal;
	int bichoOpacity;
	int bichoNext;

	BLayer myLayer[MAXLAYERS];

	Bicho();

private:

};

#endif
