// Copyright 2017 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include <list>

class AVoxelWorld;
class ChunkOctree;
class AVoxelChunk;

/**
 *
 */
class VoxelRender
{
public:
	AVoxelWorld* const World;

	FQueuedThreadPool* const MeshThreadPool;
	FQueuedThreadPool* const FoliageThreadPool;


	VoxelRender(AVoxelWorld* World, uint32 MeshThreadCount, uint32 FoliageThreadCount);


	void Tick(float DeltaTime);

	void AddInvoker(TWeakObjectPtr<UVoxelInvokerComponent> Invoker);

	AVoxelChunk* GetInactiveChunk();
	void SetChunkAsInactive(AVoxelChunk* Chunk);

	void UpdateChunk(TWeakPtr<ChunkOctree> Chunk, bool bAsync);
	void UpdateChunksAtPosition(FIntVector Position, bool bAsync);
	void ApplyUpdates();

	void UpdateAll(bool bAsync);

	void UpdateLOD();

	void AddFoliageUpdate(AVoxelChunk* Chunk);

	void AddTransitionCheck(AVoxelChunk* Chunk);

	TWeakPtr<ChunkOctree> GetChunkOctreeAt(FIntVector Position) const;

	int GetDepthAt(FIntVector Position) const;
private:

	// Chunks waiting for update
	TSet<TWeakPtr<ChunkOctree>> ChunksToUpdate;
	// Ids of the chunks that need to be updated synchronously
	TSet<uint64> IdsOfChunksToUpdateSynchronously;

	// TODO: hash
	TSet<AVoxelChunk*> ChunksToCheckForTransitionChange;

	// Shared ptr because each ChunkOctree need a reference to itself, and the Main one isn't the child of anyone
	TSharedPtr<ChunkOctree> MainOctree;

	std::forward_list<AVoxelChunk*> InactiveChunks;
	TSet<AVoxelChunk*> ActiveChunks;

	TSet<AVoxelChunk*> FoliageUpdateNeeded;

	// Invokers
	std::forward_list<TWeakObjectPtr<UVoxelInvokerComponent>> VoxelInvokerComponents;


	float TimeSinceMeshUpdate;
	float TimeSinceFoliageUpdate;

	void ApplyFoliageUpdates();
	void ApplyTransitionChecks();
};
