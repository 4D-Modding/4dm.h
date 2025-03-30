#pragma once

#include "4dm.h"
#include "Dodecaplex.h"
#include "HypercubeHollow.h"
#include "Hypersphere.h"
#include "KleinBottle.h"
#include "PentachoronHollow.h"
#include "Sphere.h"
#include <array>

namespace fdm 
{
	class GlobalShapes 
	{
	public:
		inline static const MeshBuilder& pentachoron = *reinterpret_cast<const MeshBuilder*>(getDataAddr((int)Data::GlobalShapes::pentachoron));
		inline static const PentachoronHollow& pentachoronHollow = *reinterpret_cast<const PentachoronHollow*>(getDataAddr((int)Data::GlobalShapes::pentachoronHollow));
		inline static std::array<const glm::vec4, 5>& five_cell_normals = *reinterpret_cast<std::array<const glm::vec4, 5>*>(getDataAddr((int)Data::GlobalShapes::five_cell_normals));
		inline static const MeshBuilder& pentachoronOriginBase = *reinterpret_cast<const MeshBuilder*>(getDataAddr((int)Data::GlobalShapes::pentachoronOriginBase));
		inline static const MeshBuilder& spiderLeg = *reinterpret_cast<const MeshBuilder*>(getDataAddr((int)Data::GlobalShapes::spiderLeg));
		inline static std::array<const glm::vec4, 20>& five_cell_tet_origin_base = *reinterpret_cast<std::array<const glm::vec4, 20>*>(getDataAddr((int)Data::GlobalShapes::five_cell_tet_origin_base));
		inline static const MeshBuilder& hypercube = *reinterpret_cast<const MeshBuilder*>(getDataAddr((int)Data::GlobalShapes::hypercube));
		inline static const HypercubeHollow& hypercubeHollow = *reinterpret_cast<const HypercubeHollow*>(getDataAddr((int)Data::GlobalShapes::hypercubeHollow));
		//inline static std::array<const glm::vec4, 16>& hypercube_vert = *reinterpret_cast<std::array<const glm::vec4, 16>*>(getDataAddr((int)Data::GlobalShapes::hypercube_vert));
		//inline static std::array<const glm::vec3, 16>& hypercube_vert_colors_deadly = *reinterpret_cast<std::array<const glm::vec3, 16>*>(getDataAddr((int)Data::GlobalShapes::hypercube_vert_colors_deadly));
		inline static std::array<const glm::vec4, 64>& hypercube_cubes = *reinterpret_cast<std::array<const glm::vec4, 64>*>(getDataAddr((int)Data::GlobalShapes::hypercube_cubes));
		inline static std::array<const glm::vec4, 8>& hypercube_cubes_normals = *reinterpret_cast<std::array<const glm::vec4, 8>*>(getDataAddr((int)Data::GlobalShapes::hypercube_cubes_normals));
		inline static std::array<const glm::vec3, 64>& hypercube_cubes_colors_deadly = *reinterpret_cast<std::array<const glm::vec3, 64>*>(getDataAddr((int)Data::GlobalShapes::hypercube_cubes_colors_deadly));
		inline static std::array<const glm::vec4, 160>& hypercube_tet = *reinterpret_cast<std::array<const glm::vec4, 160>*>(getDataAddr((int)Data::GlobalShapes::hypercube_tet));
		inline static std::array<const glm::vec3, 160>& hypercube_tet_colors = *reinterpret_cast<std::array<const glm::vec3, 160>*>(getDataAddr((int)Data::GlobalShapes::hypercube_tet_colors));
		inline static std::array<const glm::vec4, 64>& hypercube_wireframe = *reinterpret_cast<std::array<const glm::vec4, 64>*>(getDataAddr((int)Data::GlobalShapes::hypercube_wireframe));
		//inline static std::array<const glm::vec4, 640>& hypercube_block_tet = *reinterpret_cast<std::array<const glm::vec4, 640>*>(getDataAddr((int)Data::GlobalShapes::hypercube_block_tet));
		inline static const Dodecaplex& dodecaplexHollow = *reinterpret_cast<const Dodecaplex*>(getDataAddr((int)Data::GlobalShapes::dodecaplexHollow));
		inline static const Dodecaplex& dodecaplex = *reinterpret_cast<const Dodecaplex*>(getDataAddr((int)Data::GlobalShapes::dodecaplex));
		inline static const Dodecaplex& rock = *reinterpret_cast<const Dodecaplex*>(getDataAddr((int)Data::GlobalShapes::rock));
		inline static const DodecaplexWireframe& dodecaplexWireframe = *reinterpret_cast<const DodecaplexWireframe*>(getDataAddr((int)Data::GlobalShapes::dodecaplexWireframe));
		inline static const Sphere& sphere = *reinterpret_cast<const Sphere*>(getDataAddr((int)Data::GlobalShapes::sphere));
		inline static const Hypersphere& hypersphere = *reinterpret_cast<const Hypersphere*>(getDataAddr((int)Data::GlobalShapes::hypersphere));
		inline static const Hypersphere& hypersphereHollow = *reinterpret_cast<const Hypersphere*>(getDataAddr((int)Data::GlobalShapes::hypersphereHollow));
		inline static const KleinBottle& kleinBottle = *reinterpret_cast<const KleinBottle*>(getDataAddr((int)Data::GlobalShapes::kleinBottle));
		inline static std::array<glm::vec3, 20>& five_cell_colors = *reinterpret_cast<std::array<glm::vec3, 20>*>(getDataAddr((int)Data::GlobalShapes::five_cell_colors));
		inline static std::array<glm::vec4, 20>& five_cell_tet = *reinterpret_cast<std::array<glm::vec4, 20>*>(getDataAddr((int)Data::GlobalShapes::five_cell_tet));
	};
}
