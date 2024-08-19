#pragma once
#include "MainViewModel.g.h"

namespace winrt::videocat::implementation
{
	struct MainViewModel : MainViewModelT<MainViewModel, BindableBase>
	{
		MainViewModel();
	};
}

namespace winrt::videocat::factory_implementation
{
	struct MainViewModel : MainViewModelT<MainViewModel, implementation::MainViewModel>
	{

	};
}
