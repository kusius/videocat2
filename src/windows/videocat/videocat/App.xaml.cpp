#include "pch.h"
#include "App.xaml.h"
#include "MainWindow.xaml.h"

namespace winrt {
    using namespace Microsoft::UI::Xaml;
    using namespace Microsoft::UI::Xaml::Controls;
    using namespace Microsoft::UI::Xaml::Navigation;
    using namespace videocat;
    using namespace videocat::implementation;
}

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::videocat::implementation
{
    winrt::Microsoft::UI::Xaml::Window winrt::App::window{ nullptr };


    /// <summary>
    /// Initializes the singleton application object.  This is the first line of authored code
    /// executed, and as such is the logical equivalent of main() or WinMain().
    /// </summary>
    App::App()
    {
        // Xaml objects should not call InitializeComponent during construction.
        // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

#if defined _DEBUG
        #if !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION

        UnhandledException([](IInspectable const&, UnhandledExceptionEventArgs const& e)
        {
            if (IsDebuggerPresent())
            {
                auto errorMessage = e.Message();
                __debugbreak();
            }
        });
        #endif
#endif
    }

    /// <summary>
    /// Invoked when the application is launched.
    /// </summary>
    /// <param name="e">Details about the launch request and process.</param>
    void App::OnLaunched([[maybe_unused]] LaunchActivatedEventArgs const& e)
    {
        window = make<MainWindow>();
        window.ExtendsContentIntoTitleBar(true);

        Frame rootFrame = CreateRootFrame();
        if (!rootFrame.Content())
        {
            rootFrame.Navigate(xaml_typename<videocat::MainPage>());
        }

        window.Activate();
    }

    /// <summary>
    /// Invoked when Navigation to a certain page fails
    /// </summary>
    /// <param name="sender">The Frame that failed navigation</param>
    /// <param name="e">Details about the navigation failure</param>
    void winrt::App::OnNavigationFailed(IInspectable const&, NavigationFailedEventArgs const& e) {
        throw hresult_error(E_FAIL, hstring(L"Failed to load Page ") + e.SourcePageType().Name);
    }

    winrt::Frame winrt::App::CreateRootFrame()
    {
        Frame rootFrame{ nullptr };
        auto content = window.Content();
        if (content)
        {
            rootFrame = content.try_as<Frame>();
        }

        // Don't repeat app initialization when the Window already has content,
        // just ensure that the window is active
        if (!rootFrame)
        {
            // Create a Frame to act as the navigation context
            rootFrame = Frame();

            rootFrame.NavigationFailed({ this, &App::OnNavigationFailed });

            // Place the frame in the current Window
            window.Content(rootFrame);
        }

        return rootFrame;
    }
}