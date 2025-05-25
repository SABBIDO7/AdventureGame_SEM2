#include "AIC_EnemyGuard.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AAIC_EnemyGuard::AAIC_EnemyGuard()
{
	// Initialize BehaviorTreeComponent and BlackboardComponent
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
}

void AAIC_EnemyGuard::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(BehaviorTree.Get()))
	{
		
			// Start the behavior tree
			RunBehaviorTree(BehaviorTree.Get());
			BehaviorTreeComponent->StartTree(*BehaviorTree.Get());
		
	}
}

void AAIC_EnemyGuard::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (IsValid(BehaviorTree.Get())  && IsValid( BlackboardComponent.Get()))
	{
		// Initialize the blackboard with the BehaviorTree's blackboard asset
		BlackboardComponent->InitializeBlackboard(*BehaviorTree.Get()->BlackboardAsset.Get());
		
	}
}
