// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"

#include "TableTest.generated.h"

UCLASS()
class UFURNITURERESIZE_API ATableTest : public AActor
{
	GENERATED_BODY()
	
public:	

    // Sets default values for this actor's properties
    ATableTest();

    UPROPERTY(VisibleAnywhere)
    UProceduralMeshComponent* ProceduralMesh;

    UPROPERTY(Category = Vertices, EditAnywhere, BlueprintReadOnly)
    TArray<FVector> Vertices;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    //void PostEditChangeProperty(FPropertyChangedEvent & e);

    void PostEditChangeChainProperty(FPropertyChangedChainEvent & e);

    void PostActorCreated();

    void PostLoad();

private:

    void CreateTriangle();
    void CreateSquare();
    void UpdateSquare();

    TArray<int32> Triangles;
    TArray<FVector> Normals;
    TArray<FVector2D> UV0;
    TArray<FColor> VertexColors;

	
	
};
