#pragma once

#include "4dm.h"

namespace fdm
{
	struct Frustum
	{
	public:
		Frustum() {}
		struct
		{
			glm::vec3 normal;
			float distanceToOrigin;
		} planes[6];
	};
}