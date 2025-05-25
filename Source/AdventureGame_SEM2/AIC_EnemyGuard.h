#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIC_EnemyGuard.generated.h"

class UBehaviorTreeComponent;
UCLASS()
class ADVENTUREGAME_SEM2_API AAIC_EnemyGuard : public AAIController
{
	GENERATED_BODY()
	
public:
	AAIC_EnemyGuard(); // Constructor

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:
	/** Behavior Tree Asset */
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "AI",meta=(AllowPrivateAccess=true))
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "AI",meta=(AllowPrivateAccess=true))
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "AI",meta=(AllowPrivateAccess=true))
	TObjectPtr<UBlackboardComponent> BlackboardComponent;
};
