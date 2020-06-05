// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UCharacterAnimInstance : public UAnimInstance
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blend Space Contorl")
    float Direction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blend Space Contorl")
    float Speed;
public:
    UFUNCTION(BlueprintCallable, Category = "Blend Space Control")
    void DirectionAndSpeed();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta= (BlueprintThreadSafe), Category = "Animation Pose")
    bool IsCasting1H();
};
