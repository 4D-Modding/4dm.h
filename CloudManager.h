#pragma once
#ifndef CLOUDMANAGER_H
#define CLOUDMANAGER_H
#include "4dm.h"
namespace fdm
{
    class CloudChunk;
	class CloudManager
	{
	public:
        glm::vec3 offset;
        glm::vec3 velocity;
        unsigned int seed;
        PAD(4);
        std::map<std::tuple<__int64, __int64, __int64>, CloudChunk*> clouds;
        double lastUpdateTime;
        std::mutex cloudsMutex;
        std::atomic_bool chunksReady;
        PAD(3);
        std::atomic_int loadedChunks;
        std::vector<CloudChunk*, std::allocator<CloudChunk*> > newChunks;
        std::vector<std::tuple<__int64, __int64, __int64>> newChunkPositions;
	};
}
#endif