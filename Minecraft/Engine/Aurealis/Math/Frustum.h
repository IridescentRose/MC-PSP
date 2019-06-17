#ifndef Aurealis_FRUSTUM_H
#define Aurealis_FRUSTUM_H

#include "psptypes.h"

#include <Aurealis/Math/Vector3.h>
#include <Aurealis/Math/Plane.h>
#include <Aurealis/Math/BoundingBox.h>
#include <Aurealis/Math/BoundingSphere.h>
#include <Aurealis/Graphics/Vertex.h>
#include <pspmath.h>

using namespace Aurealis::Graphics;

namespace Aurealis
{
	namespace Math
	{

		class Frustum
		{
		public:
			Frustum();
			virtual ~Frustum();

			enum
			{
				FRUSTUM_PLANE_LEFT   = 0,
				FRUSTUM_PLANE_RIGHT  = 1,
				FRUSTUM_PLANE_BOTTOM = 2,
				FRUSTUM_PLANE_TOP    = 3,
				FRUSTUM_PLANE_NEAR   = 4,
				FRUSTUM_PLANE_FAR    = 5
			};

			enum PlaneIntersectionType { Outside = 0, Inside = 1, Intersects = 2 };

			Plane planes[6];

			void ExtractPlanes(ScePspFMatrix4 &clip);

			bool BBoxInFrustum(const BoundingBox &box) const;
			bool PointInFrustum(const Vector3 &point) const;
			bool PointInFrustum(int plane,const Vector3 &point,float &distance) const;
			bool SphereInFrustum(const BoundingSphere &sphere) const;

			//testing
			PlaneIntersectionType BoxInFrustum(BoundingBox &box);
			PlaneIntersectionType BoxInFrustum(float minx,float miny,float minz,float maxx,float maxy,float maxz);

			//clipping
			TexturesPSPVertex buffer[2][10];
			TexturesPSPVertex vertexIntersection(TexturesPSPVertex& a,float da,TexturesPSPVertex& b,float db);
			void Clip(int plane,int vertexCount,TexturesPSPVertex * in,int i,TexturesPSPVertex * out,int &outCount);
		};

	}
}

#endif
