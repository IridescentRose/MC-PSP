#pragma once

#include <Aurealis/Math/Vector3.h>
#include <Aurealis/Math/BoundingBox.h>
#include <pspmath.h>

namespace Aurealis
{
	namespace Math
	{
		class BoundingSphere
		{
		public:
			Vector3 center;
			float radius;

			BoundingSphere();
			BoundingSphere(const Vector3 &center_, float radius_);
			~BoundingSphere();

			bool hasCollided(const BoundingSphere &other) const;
			bool intersect(BoundingBox &box);
			bool inside(BoundingBox &box,Vector3 &axis, float &distance);
			bool PointCollided(Vector3 &point);
		};
	}
}
