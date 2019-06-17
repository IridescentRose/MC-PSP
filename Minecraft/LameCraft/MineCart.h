#ifndef LAMEMOB_H_
#define LAMEMOB_H_

#include <math.h>
#include <psptypes.h>

#include <Aurealis/Graphics/RenderManager.h>
#include <Aurealis/Utils/Logger.h>
#include <Aurealis/Utils/Timer.h>
#include <Aurealis/System/SystemManager.h>

#include "SoundManager.h"


class LameMob
{
public:
	LameMob(float x, float y , float z);
	 ~LameMob();

	void Go(int block, float x, float y , float z);

    Vector3 pos;
    Vector3 angle;
    Vector3 collideBox;

    int hp;
    bool on_rails;
    bool fall;
    bool go_;

    int way;
    /*
    0 - x+
    1 - x-
    2 - z+
    3 - z-
    */
    int bent;


private:

    int triangles;
    int speed;

};

#endif

