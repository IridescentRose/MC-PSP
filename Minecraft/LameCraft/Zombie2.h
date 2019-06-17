#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <Aurealis/Graphics/Vertex.h>
#include <Aurealis/Graphics/RenderManager.h>
#include <pspmath.h>
#include <psptypes.h>
#include <Aurealis/Math/Frustum.h>

#include <Aurealis/Math/BoundingBox.h>
#include <Aurealis/Math/Frustum.h>
#include "LameMob.h"

class CraftWorld;

class Zombie : public LameMob
{
public:

    Zombie(Vector3 position1, int number1);
    ~Zombie();

    void BoxCollision();
    void Update(CraftWorld *myWorld, Vector3 playerPos, float dt);
    void Render(Frustum &camFrustum, float dt);
    void TakeDamage(float damage, float power, float dt);
    void TakeDamageFromPointExplosion(float damage, float power, float dt, Vector3 point);

    int helmetId, chestplateId, leggingsId, bootsId;

private:

    float rHandAngle;
    float lHandAngle;
    float rLegAngle;
    float lLegAngle;

    float headAngleZ;
    float headAngleY;

    float animHandAngle;
    float animHandAngleT;

    float animLegAngle;
    float animLegAngleT;

    float sunTimer;
};

#endif

