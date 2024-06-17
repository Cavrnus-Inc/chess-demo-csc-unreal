// Copyright(c) Cavrnus. All rights reserved.
#include "UI/Pagination/Pagination.h"
#include "Blueprint/WidgetTree.h"

void UPagination::Setup(TSubclassOf<UUserWidget>* InItemWidget)
{
	ItemWidget = InItemWidget;

	NoResultsContainer->SetVisibility(ESlateVisibility::Hidden);
	FooterContainer->SetVisibility(ESlateVisibility::Hidden);

	if (ButtonNext)
	{
		ButtonNext->SetIsEnabled(false);
		ButtonNext->OnClicked.AddDynamic(this, &UPagination::Next);
	}

	if (ButtonPrevious)
	{
		ButtonPrevious->SetIsEnabled(false);
		ButtonPrevious->OnClicked.AddDynamic(this, &UPagination::Previous);
	}
}

void UPagination::NewPagination(TSubclassOf<UUserWidget>* InItemWidget, const TArray<IListElementInterface*>& InDisplayContent)
{
	ItemWidget = InItemWidget;
	Content = InDisplayContent;

	if (Content.Num() == 0)
	{
		NoResultsContainer->SetVisibility(ESlateVisibility::Visible);
		FooterContainer->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		NoResultsContainer->SetVisibility(ESlateVisibility::Hidden);
		FooterContainer->SetVisibility(ESlateVisibility::Visible);
	}

	ButtonNext->SetIsEnabled(true);
	ButtonPrevious->SetIsEnabled(false);

	CurrentPage = 1; // 1-indexed page
	TotalPages = Content.Num() / ItemsPerPage;

	if (Content.Num() % ItemsPerPage != 0)
		TotalPages++;

	LoadPage(CurrentPage);
}

void UPagination::ResetPagination()
{
	if (CurrentItems.Num() > 0)
	{
		for (const auto Item : CurrentItems)
		{
			Item.Key->RemoveFromParent();
		}

		CurrentItems.Empty(); // Also, same here...Clear()?
	}
}

void UPagination::LoadPage(const int Page)
{
	if (Page == 1)
		ButtonPrevious->SetIsEnabled(false);

	// Arrive at last page
	if (Page == TotalPages)
		ButtonNext->SetIsEnabled(false);

	if (CurrentItems.Num() > 0)
	{
		for (const auto Item : CurrentItems)
			Item.Key->RemoveFromParent(); // Also here...

		CurrentItems.Reset(); // Reset? I need a clear...
	}

	int start = (Page - 1) * ItemsPerPage;
	int end = std::min(start + ItemsPerPage, Content.Num());

	UVerticalBox* VerticalBox = Cast<UVerticalBox>(ItemContainer);
	if (VerticalBox)
	{
		for (int i = start; i < end; i++)
		{
			UUserWidget* NewItem = CreateWidget<UUserWidget>(VerticalBox, *ItemWidget);
			
			CurrentItems.Add(NewItem, Content[i]);
			Content[i]->EntryBuilt(NewItem);
			VerticalBox->AddChildToVerticalBox(NewItem);
			NewItem->SetVisibility(ESlateVisibility::Visible);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ItemContainer is not a VerticalBox!."));
	}
	
	const FString CurrentPageText = FString::Printf(TEXT("%d of %d"), Page, TotalPages);
	TextBlockCurrentPage->SetText(FText::FromString(CurrentPageText));
	CurrentPage = Page;
}

void UPagination::Next()
{
	ButtonPrevious->SetIsEnabled(true);
	LoadPage(CurrentPage + 1);
}

void UPagination::Previous()
{
	ButtonNext->SetIsEnabled(true);
	LoadPage(CurrentPage - 1);
}