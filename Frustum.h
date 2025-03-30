#pragma once

#include "4dm.h"
#undef NEAR
#undef FAR

namespace fdm
{
	struct Frustum
	{
	public:
		Frustum() {}
		enum Plane : int
		{
			NEAR = 0,
			FAR,
			LEFT,
			RIGHT,
			TOP,
			BOTTOM,
			NUM_PLANES
		};
		struct
		{
			glm::vec3 normal;
			float distanceToOrigin;
		} planes[NUM_PLANES];
	};
}