#pragma once

#include <Aurealis/Graphics/Vertex.h>
#include <Aurealis/Graphics/RenderManager.h>
#include <pspmath.h>
#include <Aurealis/Math/Frustum.h>
#include <LameCraft/World/CraftWorld2.h>
#include <Aurealis/Math/BoundingBox.h>

class CraftWorld;

class TNT
{
public:
    TNT(CraftWorld* world, Vector3 position2, Vector3 velocity2);
    ~TNT();

    void Update(float dt);
    void Render();
    void SetVelociy(Vector3 velocity2);
    void SetPosition(Vector3 position2);
    void ActivateOtherTNTs();
    void HurtNearbyMobs(float dt);

    float timeToExplode;
    float explodeRadius;
    Vector3 position;
    Vector3 velocity;
    bool toDestroy;
    int num;
    bool ignitedByPlayer;

private:

    float animationTime;
    int TNTid;

    float blockScale;
    bool onGround;

    CraftWorld* myWorld;
};
