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

        void render(const m4::Mat5& MV, const glm::mat4& P, int matUniformID)
        {
            return reinterpret_cast<void(__thiscall*)(CloudManager * self, const m4::Mat5& MV, const glm::mat4& P, int matUniformID)>(FUNC_CLOUDMANAGER_RENDER)(this, MV, P, matUniformID);
        }
        void updateLoadedChunks(const glm::vec4& pos, const glm::vec4& over, unsigned char renderDistance)
        {
            return reinterpret_cast<void(__thiscall*)(CloudManager * self, const glm::vec4& pos, const glm::vec4& over, unsigned char renderDistance)>(FUNC_CLOUDMANAGER_UPDATELOADEDCHUNKS)(this, pos, over, renderDistance);
        }
        void loadChunks()
        {
            return reinterpret_cast<void(__thiscall*)(CloudManager * self)>(FUNC_CLOUDMANAGER_LOADCHUNKS)(this);
        }
        void updateChunk(glm::vec3& coords)
        {
            return reinterpret_cast<void(__thiscall*)(CloudManager * self, glm::vec3& coords)>(FUNC_CLOUDMANAGER_UPDATECHUNK)(this, coords);
        }
        ~CloudManager()
        {
            reinterpret_cast<void(__thiscall*)(CloudManager * self)>(FUNC_CLOUDMANAGER_DCLOUDMANAGER)(this);
        }
	};
}
#endif