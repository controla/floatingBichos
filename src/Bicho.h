#ifndef _BICHO
#define _BICHO

#include "BLayer.h"
#include "ofMain.h"

#define MAXLAYERS 20

class Bicho {
	public:
		void setup(string _bichoPath);
		void update(float _speed, float _posx, float _posy, float _offset);
		void draw();
		void remove();

	float bichoX;
	float bichoY;

	bool isFading;
	bool isAlive;
	int layersTotal;
	int bichoOpacity;
	int bichoNext;

	BLayer myLayer[MAXLAYERS];

	Bicho();

private:

};

#endif
