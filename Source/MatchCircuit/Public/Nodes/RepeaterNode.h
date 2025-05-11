// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Nodes/MatchCircuitNode.h"
#include "RepeaterNode.generated.h"

/**
 * A repeater node restores signal strength to full when propagating.
 */

UCLASS()
class MATCHCIRCUIT_API ARepeaterNode : public AMatchCircuitNode
{
	GENERATED_BODY()

	
public:
	ARepeaterNode();

	/** When receiving a signal, reset strength and propagate forward. */
	virtual void ReceiveSignal(float IncomingStrength) override;
	
};
