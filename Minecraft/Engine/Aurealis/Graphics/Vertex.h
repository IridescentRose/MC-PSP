#pragma once

#include <Aurealis/Math/Vector3.h>

namespace Aurealis
{
	namespace Graphics
	{
		class Color
		{
		public:

			Color()
			{
				R = G = B = 0.0f;
			}

			Color(float r,float g,float b)
			{
				R = r;
				G = g;
				B = b;
			}

			float R,G,B;
		};

		class Face
		{
		public:

			Face(Color fColor,int v1,int v2, int v3)
			{
				color = fColor;
				V1 = v1;
				V2 = v2;
				V3 = v3;
			}

			Color color;
			int V1,V2,V3;
		};

		typedef struct
		{
			unsigned int color;
			float x,y,z;
		}__attribute__((packed)) ColoredVertex;

        typedef struct
		{
			float x,y,z;
		}__attribute__((packed)) ColoredVertex2;

		typedef struct
		{
			float u,v;
			unsigned int color;
			float x,y,z;
		}__attribute__((packed)) Vertex;

		typedef struct
		{
			float u,v;
			unsigned int color;
			unsigned char x,y,z;
		}__attribute__((packed)) Vertex2;

		typedef struct
		{
			float u,v;
			float x,y,z;
		}__attribute__((packed)) TexturedVertex;

		typedef struct
		{
			unsigned short u, v;
			short x, y, z;
		}__attribute__((packed)) TexturedVertex16;

		typedef struct
		{
			unsigned char u, v;
			char x, y, z;
		}__attribute__((packed)) TexturedVertex8;

		struct MorphVertex
		{
			TexturedVertex v0;
			TexturedVertex v1;
		};
	}
}
