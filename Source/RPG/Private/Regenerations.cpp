// Fill out your copyright notice in the Description page of Project Settings.


#include "Regenerations.h"
#include "RPG/RPGCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
URegenerations::URegenerations()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URegenerations::BeginPlay()
{
	Super::BeginPlay();

	// ...

	Character = Cast<ARPGCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
}


// Called every frame
void URegenerations::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	HealthRegen(Character->HealthRegenRatePerSecond);
	ManaRegen(Character->ManaRegenRatePerSecond);
}

void URegenerations::HealthRegen(float RegenRatePerSecond)
{
	if(!Character)
	{
		if(GEngine) { GEngine->AddOnScreenDebugMessage(-1,2.0f,FColor::Red, "No player character found");}
		return;
	}

	if(Character->Health >= 1) {return;}
	Character->Health += RegenRatePerSecond * GetWorld()->DeltaTimeSeconds;
	if(Character->Health > 1) {Character->Health = 1.0f;}
}

void URegenerations::ManaRegen(float RegenRatePerSecond)
{
	if(!Character)
	{
		if(GEngine) { GEngine->AddOnScreenDebugMessage(-1,2.0f,FColor::Red, "No player character found");}
		return;
	}

	if(Character->Mana >= 1) {return;}
	Character->Mana += RegenRatePerSecond * GetWorld()->DeltaTimeSeconds;
	if(Character->Mana > 1) {Character->Mana = 1.0f;}
}

