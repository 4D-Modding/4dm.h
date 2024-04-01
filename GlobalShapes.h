#pragma once

#include "4dm.h"
#include "Dodecaplex.h"
#include "HypercubeHollow.h"
#include "Hypersphere.h"
#include "KleinBottle.h"
#include "PentachoronHollow.h"
#include "Sphere.h"

namespace fdm 
{
	class GlobalShapes 
	{
	public:
		inline static const MeshBuilder* pentachoron = reinterpret_cast<const MeshBuilder*>((base + 0x2C0B08));
		inline static const PentachoronHollow* pentachoronHollow = reinterpret_cast<const PentachoronHollow*>((base + 0x2C0970));
		inline static glm::vec4* five_cell_normals = reinterpret_cast<glm::vec4*>((base + 0x2C0920));
		inline static const MeshBuilder* pentachoronOriginBase = reinterpret_cast<const MeshBuilder*>((base + 0x2BFAA8));
		inline static const MeshBuilder* spiderLeg = reinterpret_cast<const MeshBuilder*>((base + 0x2C0AD0));
		inline static glm::vec4* five_cell_tet_origin_base = reinterpret_cast<glm::vec4*>((base + 0x2C0770));
		inline static const MeshBuilder* hypercube = reinterpret_cast<const MeshBuilder*>((base + 0x2C0B48));
		inline static const HypercubeHollow* hypercubeHollow = reinterpret_cast<const HypercubeHollow*>((base + 0x2C0B80));
		inline static glm::vec4* hypercube_vert = NULL; 
		inline static glm::vec3* hypercube_vert_colors_deadly = NULL; 
		inline static glm::vec4* hypercube_cubes = reinterpret_cast<glm::vec4*>((base + 0x2AEA90)); 
		inline static glm::vec4* hypercube_cubes_normals = reinterpret_cast<glm::vec4*>((base + 0x2AEA10)); 
		inline static glm::vec3* hypercube_cubes_colors_deadly = reinterpret_cast<glm::vec3*>((base + 0x2ADD10)); 
		inline static glm::vec4* hypercube_tet = reinterpret_cast<glm::vec4*>((base + 0x2AE010)); 
		inline static glm::vec3* hypercube_tet_colors = reinterpret_cast<glm::vec3*>((base + 0x2AD590)); 
		inline static glm::vec4* hypercube_wireframe = reinterpret_cast<glm::vec4*>((base + 0x2AEE90)); 
		inline static glm::vec4* hypercube_block_tet = NULL; 
		inline static const Dodecaplex* dodecaplexHollow = reinterpret_cast<const Dodecaplex*>((base + 0x279950));
		inline static const Dodecaplex* dodecaplex = reinterpret_cast<const Dodecaplex*>((base + 0x2798F0));
		inline static const Dodecaplex* rock = reinterpret_cast<const Dodecaplex*>((base + 0x2799D0));
		inline static const DodecaplexWireframe* dodecaplexWireframe = reinterpret_cast<const DodecaplexWireframe*>((base + 0x2799A8));
		inline static const Sphere* sphere = reinterpret_cast<const Sphere*>((base + 0x2C08B0));
		inline static const Hypersphere* hypersphere = reinterpret_cast<const Hypersphere*>((base + 0x2C0738));
		inline static const Hypersphere* hypersphereHollow = reinterpret_cast<const Hypersphere*>((base + 0x2C0BA0));
		inline static const KleinBottle* kleinBottle = reinterpret_cast<const KleinBottle*>((base + 0x2C08E8));

	};
}
