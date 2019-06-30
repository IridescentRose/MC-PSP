#pragma once

#include <Aurealis/Graphics/Vertex.h>
#include <Aurealis/Graphics/RenderManager.h>
#include <pspmath.h>
#include <Aurealis/Math/Frustum.h>
#include <LameCraft/World/CraftWorld2.h>
#include <Aurealis/Utils/LameFunctions.h>
#include <Aurealis/Math/BoundingBox.h>
#include <Aurealis/Graphics/TextureUtil.h>
#include <LameCraft/World/Data/SharedTextureData.h>

class CraftWorld;

class WeatherSystem
{
public:
    WeatherSystem();
    ~WeatherSystem();

    void SetWeatherDuration(float duration);
    void SetWeatherType(int type);

    float GetWeatherDuration();
    int GetWeatherType();

    void Update(CraftWorld* mWorld, float dt);
    void Render(CraftWorld* mWorld, Frustum &camFrustum, float camera_angle, Vector3 playerPosition, float dt);
    void BuildPlanesVertex();

    int raindropsCount;
    bool itIsRaining;
    bool itIsSnowing;

private:


    Vector3 playerTempPosition;

    int weatherType;
    float weatherDuration;

    TexturedVertex *plane;

    int planeY[28];

    float rainTextureOffset;
    float snowTextureOffset;
    float textureAlpha;
    float size;

    Vector3 GetPlaneCoord(int planeID);

    void RenderPlane(int shiftX, int shiftY, int shiftZ);
    void RenderRightPlane();
    void RenderLeftPlane();
    void RenderBackPlane();
    void RenderFrontPlane();
    void RenderDiagonalePlane(int type);
};

