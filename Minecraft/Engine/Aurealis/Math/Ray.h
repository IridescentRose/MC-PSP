#pragma once

#include <Aurealis/Math/Vector3.h>
#include <Aurealis/Math/BoundingBox.h>
#include <Aurealis/Math/BoundingSphere.h>
#include <Aurealis/Math/Plane.h>
#include <pspmath.h>

namespace Aurealis
{
	namespace Math
	{

		class Ray
		{
		public:
			Vector3 origin;
			Vector3 direction;

			Ray();
			Ray(const Vector3 &origin_, const Vector3 &direction_);
			~Ray();

			bool hasIntersected(const BoundingSphere &sphere) const;
			bool hasIntersected(const BoundingBox &box) const;
			void hasIntersected(BoundingBox box,float &distance);
			bool hasIntersected(const Plane &plane) const;
			bool hasIntersected(const Plane &plane, float &t, Vector3 &intersection) const;
		};

	}
}