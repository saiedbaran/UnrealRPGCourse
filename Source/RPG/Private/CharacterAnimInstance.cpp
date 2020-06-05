// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "RPG/RPGCharacter.h"

void UCharacterAnimInstance::DirectionAndSpeed()
{
    auto PawnOwner = TryGetPawnOwner();
    if(!PawnOwner) {return;}
    
    Direction = CalculateDirection(PawnOwner->GetVelocity(), PawnOwner->GetActorRotation());
    Speed = PawnOwner->GetVelocity().SizeSquared();
}

bool UCharacterAnimInstance::IsCasting1H()
{
    auto Player = Cast<ARPGCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
    if(Player)
    {
        UE_LOG(LogTemp, Warning, TEXT("RPG character is found"));

        return Player->bCastingH1;
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("RPG character is not found"));

        return false;
    }
}
