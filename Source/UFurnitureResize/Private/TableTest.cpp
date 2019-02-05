// Fill out your copyright notice in the Description page of Project Settings.

#include "TableTest.h"


// Sets default values
ATableTest::ATableTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
    RootComponent = ProceduralMesh;
    //mesh->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);

    CreateSquare();
}

// Called when the game starts or when spawned
void ATableTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATableTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ATableTest::PostEditChangeProperty(struct FPropertyChangedEvent& e)
//{
//    FName PropertyName = (e.Property != NULL) ? e.Property->GetFName() : NAME_None;
//    if (PropertyName == GET_MEMBER_NAME_CHECKED(ATableTest, Vertices))
//    {
//        //various uproperty tricks, see link
//        UpdateSquare();
//    }
//    Super::PostEditChangeProperty(e);
//}

void ATableTest::PostEditChangeChainProperty(struct FPropertyChangedChainEvent& e)
{
    //int32 index = e.GetArrayIndex(TEXT("Vertices")); //checks skipped
    //UStaticMesh *mesh = Meshes[index]; //changed mesh
    UpdateSquare();
    UE_LOG(LogClass, Log, TEXT("PropertyChain index any"));
    Super::PostEditChangeChainProperty(e);
}

// This is called when actor is spawned (at runtime or when you drop it into the world in editor)
void ATableTest::PostActorCreated()
{
    Super::PostActorCreated();
    CreateSquare();
}

// This is called when actor is already in level and map is opened
void ATableTest::PostLoad()
{
    Super::PostLoad();
    CreateSquare();
}

void ATableTest::CreateTriangle()
{
    Vertices.Reset();
    Vertices.Add(FVector(0, 0, 0));
    Vertices.Add(FVector(0, 100, 0));
    Vertices.Add(FVector(0, 0, 100));

    TArray<int32> Triangles;
    Triangles.Add(0);
    Triangles.Add(1);
    Triangles.Add(2);

    TArray<FVector> normals;
    normals.Add(FVector(1, 0, 0));
    normals.Add(FVector(1, 0, 0));
    normals.Add(FVector(1, 0, 0));

    TArray<FVector2D> UV0;
    UV0.Add(FVector2D(0, 0));
    UV0.Add(FVector2D(10, 0));
    UV0.Add(FVector2D(0, 10));

    TArray<FProcMeshTangent> tangents;
    tangents.Add(FProcMeshTangent(0, 1, 0));
    tangents.Add(FProcMeshTangent(0, 1, 0));
    tangents.Add(FProcMeshTangent(0, 1, 0));

    TArray<FLinearColor> vertexColors;
    vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
    vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
    vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

    ProceduralMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, normals, UV0, vertexColors, tangents, true);

    // Enable collision data
    ProceduralMesh->ContainsPhysicsTriMeshData(true);
}

void ATableTest::UpdateSquare()
{
    ProceduralMesh->CreateMeshSection(0, Vertices, Triangles, Normals, UV0, VertexColors, TArray<FProcMeshTangent>(), false);
}

void ATableTest::CreateSquare()
{
    Vertices.Reset();
    Vertices.Add(FVector(0, 0, 0));
    Vertices.Add(FVector(0, 100, 0));
    Vertices.Add(FVector(100, 0, 0));
    Vertices.Add(FVector(100, 100, 0));

    Triangles.Reset();
    Triangles.Add(0);
    Triangles.Add(1);
    Triangles.Add(2);
    Triangles.Add(3);
    Triangles.Add(2);
    Triangles.Add(1);

    //TArray<FVector> normals;
    //normals.Add(FVector(1, 0, 0));
    //normals.Add(FVector(1, 0, 0));
    //normals.Add(FVector(1, 0, 0));

    UV0.Reset();
    UV0.Add(FVector2D(0, 0));
    UV0.Add(FVector2D(0, 1));
    UV0.Add(FVector2D(1, 0));
    UV0.Add(FVector2D(1, 1));

    UpdateSquare();
}



