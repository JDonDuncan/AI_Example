// Copyright Jordan Duncan 2016

#include "AI_Example.h"
#include "AIE_BaseFood_Actor.h"

#include "AIE_BotCharacter.h"


// Sets default values
AAIE_BaseFood_Actor::AAIE_BaseFood_Actor(const FObjectInitializer& ObjectInitializer) 
	: Super (ObjectInitializer) {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// create the root component
	SceneComponent = CreateDefaultSubobject<USceneComponent>("Scene Root");
	// make scene component the root component
	RootComponent = SceneComponent;
	// make the static mesh component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh Component");
	// get our default mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoodMeshAsset(*FAIE_Asset_Paths::DefaultFoodMesh);
	// check if getting the mesh was successfull
	if (FoodMeshAsset.Object) {
		// assign it to the static mesh
		Mesh->SetStaticMesh(FoodMeshAsset.Object);
	}
	// attach the mesh to the root
	Mesh->AttachTo(RootComponent);
	// set to block all
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	// create the sphere
	/*
	CollisionSphere = CreateDefaultSubobject<USphereComponent>("Sphere Collision");
	// attach the sphere to the root
	CollisionSphere->AttachTo(RootComponent);
	// set local position of the sphere
	CollisionSphere->AddLocalOffset(FVector(0.0f, 0.0f, 50.0f));
	// set size of the sphere
	CollisionSphere->SetSphereRadius(60.0f);

	CollisionSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	*/
	/* // begin ***REMOVED AFTER VIDEO 1*** \\
	// add overlap events to the sphere
	if (!bOverideNativeOverlapEvents) {
		CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AAIE_BaseFood_Actor::OnFoodOverlapBegin);
	}
	// end ***REMOVED AFTER VIDEO 1*** \\*/
}

// Called when the game starts or when spawned
void AAIE_BaseFood_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIE_BaseFood_Actor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
/* // begin ***REMOVED AFTER VIDEO 1*** \\
// handles overlap events
// won't be bound if bOverideNativeOverlapEvents = true
void AAIE_BaseFood_Actor::OnFoodOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {
	// check if we can auto pick up on touch
	if (bAutoPickup) {
		// try to get the bot that hit the food item
		AAIE_BotCharacter* BotHit = Cast<AAIE_BotCharacter>(OtherActor);
		// check if we managed to get a bot
		if (BotHit) {
#if !UE_BUILD_SHIPPING
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, " Food Hit by " + BotHit->BotName.ToString());
#endif
			// set the bots health based on the health increase value of the food
			BotHit->SetHealth(BotHit->GetHealth() + HealthIncreaseValue);
			// set the bots stamina based on the stamina increase value of the food
			BotHit->SetStamina(BotHit->GetStamina() + StaminaIncreaseValue);
			// Destroy the food item as it has been consumed
			Destroy();
		}
	}
}
// end ***REMOVED AFTER VIDEO 1*** \\*/

// IsUsable interface functions
// use item
void AAIE_BaseFood_Actor::UseItem_Implementation(AAIE_BotCharacter* BotUsing) {
	// check we have a valid bot
	if (BotUsing) {
#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, " Food Hit by " + BotUsing->BotName.ToString());
#endif
		// set the bots health based on the health increase value of the food
		BotUsing->SetHealth(BotUsing->GetHealth() + HealthIncreaseValue);
		// set the bots stamina based on the stamina increase value of the food
		BotUsing->SetStamina(BotUsing->GetStamina() + StaminaIncreaseValue);
		// Destroy the food item as it has been consumed
		Destroy();
	}
}
void AAIE_BaseFood_Actor::AI_UseItem_Implementation(AActor* BotUsing) {
}