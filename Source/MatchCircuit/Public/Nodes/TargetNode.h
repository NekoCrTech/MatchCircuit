// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Nodes/MatchCircuitNode.h"
#include "TargetNode.generated.h"

UENUM(BlueprintType)
enum class ETargetColor : uint8
{
	Red,
	Green,
	Blue,
	Yellow,
	None
};

/**
 * A target node that must be powered to fulfill a level objective.
 */

UCLASS()
class MATCHCIRCUIT_API ATargetNode : public AMatchCircuitNode
{
	GENERATED_BODY()

public:
	ATargetNode();
	
	/** Required signal strength to activate this target */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	float RequiredSignalStrength = 40.f;

	/** Color of the target node */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	ETargetColor TargetColor = ETargetColor::None;

	/** Whether this node is considered part of the objective */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	bool bIsObjective = true;

	/** Called when this node receives signal */
	virtual void ReceiveSignal(float IncomingStrength) override;

	/** Whether the target was activated correctly */
	UFUNCTION(BlueprintCallable, Category = "Target")
	bool IsCorrectlyActivated() const;

	/** Blueprint hook to change visuals when activated */
	UFUNCTION(BlueprintImplementableEvent, Category = "Visuals")
	void OnTargetActivated();

protected:
	virtual void BeginPlay() override;

	
};
