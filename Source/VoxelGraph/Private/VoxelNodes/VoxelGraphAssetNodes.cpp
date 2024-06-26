// Copyright Voxel Plugin SAS. All Rights Reserved.

#include "VoxelNodes/VoxelGraphAssetNodes.h"
#include "VoxelNodes/VoxelGeneratorSamplerNodes.h"
#include "CppTranslation/VoxelVariables.h"
#include "VoxelGenerators/VoxelGeneratorInit.h"
#include "VoxelGenerators/VoxelGeneratorInstance.h"
#include "NodeFunctions/VoxelNodeFunctions.h"
#include "VoxelTools/VoxelHardnessHandler.h"
#include "VoxelGraphGenerator.h"

int32 UVoxelGraphAssetNode::GetMaxInputPins() const
{
	return GetMinInputPins();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

UVoxelNode_EditGetValue::UVoxelNode_EditGetValue()
{
	SetInputs(
		{ "X", EC::Float, "X in global space. Use Global X" },
		{ "Y", EC::Float, "Y in global space. Use Global Y" },
		{ "Z", EC::Float, "Z in global space. Use Global Z" }
	);
	SetOutputs(
		EC::Float
	);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

UVoxelNode_EditGetMaterial::UVoxelNode_EditGetMaterial()
{
	SetInputs(
		{ "X", EC::Float, "X in global space. Use Global X" },
		{ "Y", EC::Float, "Y in global space. Use Global Y" },
		{ "Z", EC::Float, "Z in global space. Use Global Z" }
	);
	SetOutputs(
		EC::Material
	);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

UVoxelNode_EditGetCustomOutput::UVoxelNode_EditGetCustomOutput()
{
	SetInputs(
		{ "X", EC::Float, "X in global space. Use Global X" },
		{ "Y", EC::Float, "Y in global space. Use Global Y" },
		{ "Z", EC::Float, "Z in global space. Use Global Z" }
	);
	SetOutputs(
		EC::Float
	);
}

FText UVoxelNode_EditGetCustomOutput::GetTitle() const
{
	return FText::FromString("Get Previous Generator Custom Output: " + OutputName.ToString());
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

UVoxelNode_EditGetHardness::UVoxelNode_EditGetHardness()
{
	SetInputs(
		EC::Material
	);
	SetOutputs(
		EC::Float
	);
}

