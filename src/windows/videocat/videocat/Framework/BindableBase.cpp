#include "pch.h"
#include "BindableBase.h"
#include "BindableBase.g.cpp"

using namespace winrt;
using namespace Microsoft::UI::Xaml::Data;

namespace winrt::videocat::implementation
{
	void BindableBase::RaisePropertyChanged(winrt::hstring const& propertyName)
	{
		propertyChanged(*this, PropertyChangedEventArgs(propertyName));
	}
	winrt::event_token BindableBase::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return propertyChanged.add(handler);
	}
	void BindableBase::PropertyChanged(winrt::event_token const& token) noexcept
	{
		propertyChanged.remove(token);
	}
}