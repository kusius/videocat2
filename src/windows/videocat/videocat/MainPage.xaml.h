#pragma once

#include "MainPage.g.h"
#include <frame_process.h>
// IMPORTANT: included because we navigate to it 
#include "StreamPage.xaml.h" 

namespace winrt::videocat::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage() {
            

            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
        winrt::Windows::Foundation::IAsyncAction StreamTabs_AddTabButtonClick(winrt::Microsoft::UI::Xaml::Controls::TabView const& sender, winrt::Windows::Foundation::IInspectable const& args);

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    
        std::vector<FrameProcessor*> frameProcessors;
        void StreamTabs_TabCloseRequested(winrt::Microsoft::UI::Xaml::Controls::TabView const& sender, winrt::Microsoft::UI::Xaml::Controls::TabViewTabCloseRequestedEventArgs const& args);
    };
}

namespace winrt::videocat::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
