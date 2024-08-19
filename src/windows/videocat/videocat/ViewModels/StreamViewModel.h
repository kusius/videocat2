#pragma once

#include "StreamViewModel.g.h"

namespace winrt::videocat::implementation
{
	struct StreamViewModel : StreamViewModelT<StreamViewModel, BindableBase>
	{
		StreamViewModel();
	};
}

namespace winrt::videocat::factory_implementation
{
	struct StreamViewModel : StreamViewModelT<StreamViewModel, implementation::StreamViewModel>
	{

	};
}