// Developed by Neko


#include "Nodes/RepeaterNode.h"

ARepeaterNode::ARepeaterNode()
{
}

void ARepeaterNode::ReceiveSignal(float IncomingStrength)
{
	if (bIsPowered)
	{
		return; // Already powered
	}

	bIsPowered = true;
	SignalStrength = 100.0f; // Reset signal to full
	OnPoweredVisualUpdate(); // Optional visual

	PropagateSignal();
}
