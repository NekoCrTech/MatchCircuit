// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Nodes/MatchCircuitNode.h"
#include "PowerNode.generated.h"

/**
 * Node that serves as a power source. Always starts fully charged.
 */

UCLASS()
class MATCHCIRCUIT_API APowerNode : public AMatchCircuitNode
{
	GENERATED_BODY()

public:
	APowerNode();

	/** Power nodes always have full signal strength and immediately propagate it. */
	virtual void ReceiveSignal(float IncomingStrength) override;

protected:
	virtual void BeginPlay() override;
	
};
