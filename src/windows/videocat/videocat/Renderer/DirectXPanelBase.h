#pragma once

#include "pch.h"
#include <concrt.h>

namespace winrt::videocat
{
    // Base class for a SwapChainPanel-based DirectX rendering surface to be used in XAML apps.
    
    struct DirectXPanelBase : public Microsoft::UI::Xaml::Controls::SwapChainPanel
    {
        DirectXPanelBase() {};
        DirectXPanelBase(Microsoft::UI::Xaml::Controls::SwapChainPanel swapChainPanel);
    };
}