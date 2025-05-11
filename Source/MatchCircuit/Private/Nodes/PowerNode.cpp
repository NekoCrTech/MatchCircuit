// Developed by Neko


#include "Nodes/PowerNode.h"

APowerNode::APowerNode()
{
}

void APowerNode::BeginPlay()
{
	Super::BeginPlay();

	// Auto-start the circuit by powering this node
	bIsPowered = true;
	OnPoweredVisualUpdate(); // Optional: trigger blueprint effect
	PropagateSignal();
}

void APowerNode::ReceiveSignal(float IncomingStrength)
{
	// Power nodes do not receive signal — they originate it.
	// Still allow re-propagation if needed
	if (!bIsPowered)
	{
		bIsPowered = true;
		OnPoweredVisualUpdate();
	}

	PropagateSignal();
}


