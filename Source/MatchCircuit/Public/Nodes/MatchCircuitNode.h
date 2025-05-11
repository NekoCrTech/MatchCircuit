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

	// Signal strength of this node (starts at 0)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Circuit")
	float SignalStrength = 0.0f;

	// Has this node been powered?
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Circuit")
	bool bIsPowered = false;

	// Connected output nodes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Circuit")
	TArray<AMatchCircuitNode*> ConnectedNodes;

	// Amount of signal lost per hop
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Circuit")
	float SignalDropOffPerHop = 15.0f;

	// Called when a signal reaches this node
	UFUNCTION(BlueprintCallable, Category = "Circuit")
	virtual void ReceiveSignal(float IncomingStrength);

	// Sends signal to connected nodes
	UFUNCTION(BlueprintCallable, Category = "Circuit")
	virtual void PropagateSignal();

	// Triggered when this node powers up (visual/audio)
	UFUNCTION(BlueprintImplementableEvent, Category = "Visuals")
	void OnPoweredVisualUpdate();

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> MeshComp;
	
};
