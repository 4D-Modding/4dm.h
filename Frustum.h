#pragma once
#ifndef FRUSTUM_H
#define FRUSTUM_H
#include "4dm.h"
namespace fdm
{
	struct Frustum
	{
	public:
		struct 
		{
		public:
			glm::vec3 normal;
			float distanceToOrigin;
		} planes[6];
	};
}
#endif