// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MatchCircuitNode.generated.h"

UCLASS()
class MATCHCIRCUIT_API AMatchCircuitNode : public AActor
{
	GENERATED_BODY()
	
public:	
	AMatchCircuitNode();

protected:
	virtual void BeginPlay() override;
};
