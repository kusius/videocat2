#pragma once
#include "BindableBase.g.h"


namespace winrt::videocat::implementation
{
	struct BindableBase : BindableBaseT<BindableBase>
	{
		void RaisePropertyChanged(winrt::hstring const& propertyName);
		winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
		void PropertyChanged(winrt::event_token const& token) noexcept;

	private:
		event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> propertyChanged;
	};
}

namespace winrt::videocat::factory_implementation
{
	struct BindableBase : BindableBaseT<BindableBase, implementation::BindableBase>
	{

	};
}