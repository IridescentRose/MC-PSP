#include "Sky.h"
#include <stdlib.h>
#include <malloc.h>

namespace Minecraft::Rendering {
	Sky::Sky() {
		skyBoxVertices = (ColorVertex*)memalign(16, 36 * sizeof(ColorVertex));
		Update(0);
	}

	Sky::~Sky() {
		free(skyBoxVertices);
	}
	glm::vec3 zenithColorDay = glm::vec3(0.5, 0.7, 1.0);
	glm::vec3 horizonColorDay = glm::vec3(0.85, 0.91, 1.0);
	
	glm::vec3 zenithColorNight = glm::vec3(0.06, 0.05, 0.09);
	glm::vec3 horizonColorNight = glm::vec3(0.07, 0.06, 0.1);
	
	glm::vec3 zenithColorSunRise = glm::vec3(0.45, 0.5, 0.7);
	glm::vec3 horizonColorSunRise = glm::vec3(0.9, 0.45, 0.15);
	glm::vec3 zenithColorMoonRise = glm::vec3(0.45, 0.5, 0.7);
	glm::vec3 horizonColorMoonRise = glm::vec3(0.5, 0.45, 0.6);

	glm::vec3 getColor(float dayTime, float vertex) {
		if (vertex == 0) {
			if (dayTime < 2000) { //6am - 9am sun gets brighter
				return glm::mix(zenithColorMoonRise, zenithColorDay, dayTime / 2000);
			}
			if (dayTime >= 2000 && dayTime < 10000) { //9am - 3pm sun is brightest
				return zenithColorDay;
			}
			if (dayTime >= 10000 && dayTime < 12000) { //3pm - 6pm sun gets dimmer
				return glm::mix(zenithColorDay, zenithColorSunRise, (dayTime - 10000) / 2000);
			}
			if (dayTime >= 12000 && dayTime < 14000) { //6pm - 9pm sun light fades
				return glm::mix(zenithColorSunRise, zenithColorNight, (dayTime - 12000) / 2000);
			}
			if (dayTime >= 14000 && dayTime < 22000) {//9pm - 3am is night
				return zenithColorNight;
			}
			if (dayTime >= 22000 && dayTime < 24000) {
				return glm::mix(zenithColorNight, zenithColorMoonRise, (dayTime - 22000) / 2000);
			}
		}
		else if (vertex == 1) {
			if (dayTime < 2000) { //6am - 9am sun gets brighter
				return glm::mix(horizonColorMoonRise, horizonColorDay, dayTime / 2000);
			}
			if (dayTime >= 2000 && dayTime < 10000) { //9am - 3pm sun is brightest
				return horizonColorDay;
			}
			if (dayTime >= 10000 && dayTime < 12000) { //3pm - 6pm sun gets dimmer
				return glm::mix(horizonColorDay, horizonColorSunRise, (dayTime - 10000) / 2000);
			}
			if (dayTime >= 12000 && dayTime < 14000) { //6pm - 9pm sun light fades
				return glm::mix(horizonColorSunRise, horizonColorNight, (dayTime - 12000) / 2000);
			}
			if (dayTime >= 14000 && dayTime < 22000) {//9pm - 3am is night
				return horizonColorNight;
			}
			if (dayTime >= 22000 && dayTime < 24000) {
				return glm::mix(horizonColorNight, horizonColorMoonRise, (dayTime - 22000) / 2000);
			}
		}
		else if (vertex == 2) {
			if (dayTime < 2000) { //6am - 9am sun gets brighter
				return glm::mix(zenithColorSunRise, zenithColorDay, dayTime / 2000);
			}
			if (dayTime >= 2000 && dayTime < 10000) { //9am - 3pm sun is brightest
				return zenithColorDay;
			}
			if (dayTime >= 10000 && dayTime < 12000) { //3pm - 6pm sun gets dimmer
				return glm::mix(zenithColorDay, zenithColorMoonRise, (dayTime - 10000) / 2000);
			}
			if (dayTime >= 12000 && dayTime < 14000) { //6pm - 9pm sun light fades
				return glm::mix(zenithColorMoonRise, zenithColorNight, (dayTime - 12000) / 2000);
			}
			if (dayTime >= 14000 && dayTime < 22000) {//9pm - 3am is night
				return zenithColorNight;
			}
			if (dayTime >= 22000 && dayTime < 24000) {
				return glm::mix(zenithColorNight, zenithColorSunRise, (dayTime - 22000) / 2000);
			}
		}
		else if (vertex == 3) {
			if (dayTime < 2000) { //6am - 9am sun gets brighter
				return glm::mix(horizonColorSunRise, horizonColorDay, dayTime / 2000);
			}
			if (dayTime >= 2000 && dayTime < 10000) { //9am - 3pm sun is brightest
				return horizonColorDay;
			}
			if (dayTime >= 10000 && dayTime < 12000) { //3pm - 6pm sun gets dimmer
				return glm::mix(horizonColorDay, horizonColorMoonRise, (dayTime - 10000) / 2000);
			}
			if (dayTime >= 12000 && dayTime < 14000) { //6pm - 9pm sun light fades
				return glm::mix(horizonColorMoonRise, horizonColorNight, (dayTime - 12000) / 2000);
			}
			if (dayTime >= 14000 && dayTime < 22000) {//9pm - 3am is night
				return horizonColorNight;
			}
			if (dayTime >= 22000 && dayTime < 24000) {
				return glm::mix(horizonColorNight, horizonColorSunRise, (dayTime - 22000) / 2000);
			}
		}
		return glm::vec3(0, 0, 0);
	}

	void Sky::Update(s64 timeOfDay) {
		int i = 0;
	
		glm::vec3 v0[4];

		float skyColorBoost = 0.15f;
		for (int i = 0; i < 4; i++) {
			v0[i] = getColor(timeOfDay % 24000, i);
			v0[i].r = v0[i].r * (1.0f + skyColorBoost ) - (v0[i].g * skyColorBoost  / 2.0f) - (v0[i].b * skyColorBoost  / 2.0f);
			if (v0[i].r > 1.0) {
				v0[i].r = 1.0;
			}
			v0[i].g = v0[i].g * (1.0f + skyColorBoost ) - (v0[i].r * skyColorBoost  / 2.0f) - (v0[i].b * skyColorBoost  / 2.0f);
			if (v0[i].g > 1.0) {
				v0[i].g = 1.0;
			}
			v0[i].b = v0[i].b * (1.0f + skyColorBoost ) - (v0[i].r * skyColorBoost  / 2.0f) - (v0[i].g * skyColorBoost  / 2.0f);
			if (v0[i].b > 1.0) {
				v0[i].b = 1.0;
			}
		}

		//NORTH SIDE
		skyBoxVertices[i++] = { GU_COLOR(v0[1].x, v0[1].y, v0[1].z, 1.0f),-0.5f,-0.5f,-0.5f }; // 3
		skyBoxVertices[i++] = { GU_COLOR(v0[3].x, v0[3].y, v0[3].z, 1.0f), 0.5f,-0.5f,-0.5f}; // 2
		skyBoxVertices[i++] = { GU_COLOR(v0[2].x, v0[2].y, v0[2].z, 1.0f), 0.5f, 0.5f,-0.5f}; // 6

		skyBoxVertices[i++] = { GU_COLOR(v0[1].x, v0[1].y, v0[1].z, 1.0f),-0.5f,-0.5f,-0.5f}; // 3
		skyBoxVertices[i++] = { GU_COLOR(v0[2].x, v0[2].y, v0[2].z, 1.0f), 0.5f, 0.5f,-0.5f}; // 6
		skyBoxVertices[i++] = { GU_COLOR(v0[0].x, v0[0].y, v0[0].z, 1.0f),-0.5f, 0.5f,-0.5f}; // 7

		//EAST SIDE
		skyBoxVertices[i++] = { GU_COLOR(v0[3].x, v0[3].y, v0[3].z, 1.0f), 0.5f,-0.5f,-0.5f}; // 0
		skyBoxVertices[i++] = { GU_COLOR(v0[3].x, v0[3].y, v0[3].z, 1.0f), 0.5f,-0.5f, 0.5f}; // 3
		skyBoxVertices[i++] = { GU_COLOR(v0[2].x, v0[2].y, v0[2].z, 1.0f), 0.5f, 0.5f, 0.5f}; // 7

		skyBoxVertices[i++] = { GU_COLOR(v0[3].x, v0[3].y, v0[3].z, 1.0f), 0.5f,-0.5f,-0.5f}; // 0
		skyBoxVertices[i++] = { GU_COLOR(v0[2].x, v0[2].y, v0[2].z, 1.0f), 0.5f, 0.5f, 0.5f}; // 7
		skyBoxVertices[i++] = { GU_COLOR(v0[2].x, v0[2].y, v0[2].z, 1.0f), 0.5f, 0.5f,-0.5f}; // 4

		//SOUTH SIDE
		skyBoxVertices[i++] = { GU_COLOR(v0[1].x, v0[1].y, v0[1].z, 1.0f),-0.5f,-0.5f, 0.5f}; // 0
		skyBoxVertices[i++] = { GU_COLOR(v0[0].x, v0[0].y, v0[0].z, 1.0f),-0.5f, 0.5f, 0.5f}; // 4
		skyBoxVertices[i++] = { GU_COLOR(v0[2].x, v0[2].y, v0[2].z, 1.0f), 0.5f, 0.5f, 0.5f}; // 5

		skyBoxVertices[i++] = { GU_COLOR(v0[1].x, v0[1].y, v0[1].z, 1.0f), -0.5f,-0.5f, 0.5f}; // 0
		skyBoxVertices[i++] = { GU_COLOR(v0[2].x, v0[2].y, v0[2].z, 1.0f), 0.5f, 0.5f, 0.5f}; // 5
		skyBoxVertices[i++] = { GU_COLOR(v0[3].x, v0[3].y, v0[3].z, 1.0f), 0.5f,-0.5f, 0.5f}; // 1

		//WEST SIDE
		skyBoxVertices[i++] = { GU_COLOR(v0[1].x, v0[1].y, v0[1].z, 1.0f), -0.5f,-0.5f,-0.5f}; // 0
		skyBoxVertices[i++] = { GU_COLOR(v0[0].x, v0[0].y, v0[0].z, 1.0f),-0.5f, 0.5f,-0.5f}; // 3
		skyBoxVertices[i++] = { GU_COLOR(v0[0].x, v0[0].y, v0[0].z, 1.0f),-0.5f, 0.5f, 0.5f}; // 7

		skyBoxVertices[i++] = { GU_COLOR(v0[1].x, v0[1].y, v0[1].z, 1.0f), -0.5f,-0.5f,-0.5f}; // 0
		skyBoxVertices[i++] = { GU_COLOR(v0[0].x, v0[0].y, v0[0].z, 1.0f),-0.5f, 0.5f, 0.5f}; // 7
		skyBoxVertices[i++] = { GU_COLOR(v0[1].x, v0[1].y, v0[1].z, 1.0f),-0.5f,-0.5f, 0.5f}; // 4

		//TOP SIDE
		skyBoxVertices[i++] = { GU_COLOR(v0[0].x, v0[0].y, v0[0].z, 1.0f), -0.5f, 0.5f,-0.5f}; // 0
		skyBoxVertices[i++] = { GU_COLOR(v0[2].x, v0[2].y, v0[2].z, 1.0f), 0.5f, 0.5f,-0.5f}; // 1
		skyBoxVertices[i++] = { GU_COLOR(v0[2].x, v0[2].y, v0[2].z, 1.0f), 0.5f, 0.5f, 0.5f}; // 2

		skyBoxVertices[i++] = { GU_COLOR(v0[0].x, v0[0].y, v0[0].z, 1.0f), -0.5f, 0.5f,-0.5f}; // 0
		skyBoxVertices[i++] = { GU_COLOR(v0[2].x, v0[2].y, v0[2].z, 1.0f), 0.5f, 0.5f, 0.5f}; // 2
		skyBoxVertices[i++] = { GU_COLOR(v0[0].x, v0[0].y, v0[0].z, 1.0f),-0.5f, 0.5f, 0.5f}; // 3

		//BOTTOM SIDE
		skyBoxVertices[i++] = { GU_COLOR(v0[1].x, v0[1].y, v0[1].z, 1.0f),-0.5f,-0.5f,-0.5f}; // 4
		skyBoxVertices[i++] = { GU_COLOR(v0[1].x, v0[1].y, v0[1].z, 1.0f),-0.5f,-0.5f, 0.5f}; // 7
		skyBoxVertices[i++] = { GU_COLOR(v0[3].x, v0[3].y, v0[3].z, 1.0f), 0.5f,-0.5f, 0.5f}; // 6

		skyBoxVertices[i++] = { GU_COLOR(v0[1].x, v0[1].y, v0[1].z, 1.0f),-0.5f,-0.5f,-0.5f}; // 4
		skyBoxVertices[i++] = { GU_COLOR(v0[3].x, v0[3].y, v0[3].z, 1.0f), 0.5f,-0.5f, 0.5f}; // 6
		skyBoxVertices[i++] = { GU_COLOR(v0[3].x, v0[3].y, v0[3].z, 1.0f), 0.5f,-0.5f,-0.5f}; // 5

		sceKernelDcacheWritebackInvalidateRange(skyBoxVertices, 36 * sizeof(ColorVertex));
	}

	void Sky::Draw()
	{
		sceGuEnable(GU_BLEND);
		sceGuShadeModel(GU_SMOOTH);
		sceGuDisable(GU_DEPTH_TEST);
		sceGuFrontFace(GU_CCW);

		sceGumDrawArray(GU_TRIANGLES, GU_VERTEX_32BITF | GU_COLOR_8888 | GU_TRANSFORM_3D, 36, 0, skyBoxVertices);
		
		sceGuFrontFace(GU_CCW);
		sceGuEnable(GU_DEPTH_TEST);
		sceGuDisable(GU_BLEND);
		
	}

}