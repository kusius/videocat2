#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif

using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Microsoft::UI::Xaml::Controls;
using namespace winrt::Microsoft::UI::Xaml::Navigation;
using namespace winrt::Microsoft::UI::Xaml::Interop;

using namespace winrt::videocat;
using namespace winrt::videocat::implementation;


// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::videocat::implementation
{
    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
    }

    winrt::Windows::Foundation::IAsyncAction MainPage::StreamTabs_AddTabButtonClick(winrt::Microsoft::UI::Xaml::Controls::TabView const& sender, winrt::Windows::Foundation::IInspectable const& args)
    {
        ContentDialog dialog = LinkDialog();
        //capture sender object. argument becomes null when returning from ShowAsync
        const TabView senderRef = sender;

        ContentDialogResult result = co_await dialog.ShowAsync();
        

        if (result == ContentDialogResult::Primary) {
            auto textBox = LinkTextBox();
            hstring text = textBox.Text();
            TabViewItem tab;
            tab.XamlRoot(this->XamlRoot());
            tab.Header(box_value(text));
            Microsoft::UI::Xaml::Controls::Frame frame{ nullptr };
            frame = Microsoft::UI::Xaml::Controls::Frame::Frame();
            frame.CacheSize(0);
            tab.Content(frame);
            // navigate to new stream page, passing the frameprocessor as argument
            frame.Navigate(xaml_typename<videocat::StreamPage>(), box_value(text));
            senderRef.TabItems().Append(tab);

            // select the new tab 
            senderRef.SelectedItem(tab);
        }
    }

}



void winrt::videocat::implementation::MainPage::StreamTabs_TabCloseRequested(winrt::Microsoft::UI::Xaml::Controls::TabView const& sender, winrt::Microsoft::UI::Xaml::Controls::TabViewTabCloseRequestedEventArgs const& args)
{
    auto frame = args.Tab().Content().as<Microsoft::UI::Xaml::Controls::Frame>();
    auto streamPage = frame.Content().as<winrt::videocat::implementation::StreamPage>();
    streamPage->cleanUp();

    // clear frame content and navigation back entries 
    frame.Content(nullptr);
    frame.BackStack().Clear();

    uint32_t index = 0;
    bool found = sender.TabItems().IndexOf(args.Tab(), index);
    if (found) {
        sender.TabItems().RemoveAt(index);
    }
}
