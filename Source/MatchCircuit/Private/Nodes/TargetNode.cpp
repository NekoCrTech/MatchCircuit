// Developed by Neko


#include "Nodes/TargetNode.h"

ATargetNode::ATargetNode()
{
}


void ATargetNode::BeginPlay()
{
	Super::BeginPlay();
}

void ATargetNode::ReceiveSignal(float IncomingStrength)
{
	if (bIsPowered)
	{
		return; // Already powered
	}

	if (IncomingStrength >= RequiredSignalStrength)
	{
		bIsPowered = true;
		SignalStrength = IncomingStrength;
		OnTargetActivated();
	}
}

bool ATargetNode::IsCorrectlyActivated() const
{
	return bIsObjective && bIsPowered;
}

