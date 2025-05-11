// Developed by Neko


#include "Nodes/MatchCircuitNode.h"

AMatchCircuitNode::AMatchCircuitNode()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComp;
}

void AMatchCircuitNode::ReceiveSignal(float IncomingStrength)
{
	if (bIsPowered)
	{
		return; // Ignore if already powered
	}

	bIsPowered = true;
	SignalStrength = IncomingStrength;

	OnPoweredVisualUpdate();

	PropagateSignal();
}

void AMatchCircuitNode::PropagateSignal()
{
	float OutgoingStrength = SignalStrength - SignalDropOffPerHop;

	if (OutgoingStrength <= 0.0f)
	{
		return; // Signal too weak to continue
	}

	for (AMatchCircuitNode* ConnectedNode : ConnectedNodes)
	{
		if (ConnectedNode && !ConnectedNode->bIsPowered)
		{
			ConnectedNode->ReceiveSignal(OutgoingStrength);
		}
	}
}

void AMatchCircuitNode::BeginPlay()
{
	Super::BeginPlay();
	
}


