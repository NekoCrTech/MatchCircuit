// Developed by Neko


#include "Player/CameraPawn.h"


ACameraPawn::ACameraPawn()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}

void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

