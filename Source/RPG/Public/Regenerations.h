// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Regenerations.generated.h"


class ARPGCharacter;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_API URegenerations : public USceneComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    URegenerations();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                               FActorComponentTickFunction* ThisTickFunction) override;

private:
    UPROPERTY()
    ARPGCharacter* Character;

public:
    void HealthRegen(float RegenRatePerSecond);
    void ManaRegen(float RegenRatePerSecond);
};
