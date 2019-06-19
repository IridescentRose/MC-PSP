#pragma once

#include <Aurealis/Math/Vector3.h>
#include <Aurealis/Math/Frustum.h>
#include <Aurealis/Utils/Timer.h>
#include <pspmath.h>

using namespace Aurealis::Math;
using namespace Aurealis::Utils;

namespace Aurealis
{
	namespace Graphics
	{
		class Camera
		{
		public:
			Camera();
			virtual ~Camera();

			void PositionCamera(float positionX, float positionY, float positionZ,
						 		    float viewX,     float viewY,     float viewZ,
									float upVectorX, float upVectorY, float upVectorZ);

			void Move(float speed);
			void MoveTo(Vector3 newPos);
			void MovePhysic(float speed);
			Vector3 MoveFoCollision(float speed);
			void MoveAfterCollision(Vector3 newPos);

			void Strafe(float speed);
			void StrafePhysic(float speed);

			void MovePhysicNoY(float speed);
			//Vector3 StrafeFoCollision(float speed);
			//void StrafeAfterCollision(Vector3 newPos);

			void RotateView(float angle, float x, float y, float z);
			void PitchView(float speed);

			float atan_(float y, float x);


			Frustum mFrustum;
			bool needUpdate;

			Timer bobTimer;
			Timer passiveTimer;

			float tiltAngle;
			float bobY;
			float bobElapsed;
			void update(bool isWalking);

			float passiveElapsed;
			float offAngleX, offAngleY;

		//private:

			// The camera's position
			Vector3 m_vPosition;

			// The camera's offset
			Vector3 m_vOffset;

			// The camera's view
			Vector3 m_vView;

			// The camera's up vector
			Vector3 m_vUpVector;

			// The camera's strafe vector
			Vector3 m_vStrafe;

			//TODO wtf is this for??
			Vector3 m_vVelocity;

			Vector3 vVector;

			float horAngle;

			float upDownAngle;
			float upDownAngle2;
		};
	}
}
