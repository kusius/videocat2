#include "pch.h"
#include "StreamPage.xaml.h"
#if __has_include("StreamPage.g.cpp")
#include "StreamPage.g.cpp"
#endif


#include <cstring>
#include <ctime>
#include <coroutine>
#include <future>

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
    void StreamPage::InitializeComponent()
    {
        StreamPageT::InitializeComponent();
        // Create the map drawing panel
        this->directXPanelBase = DirectXPanelBase(swapChainPanel());
    }

    int32_t StreamPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void StreamPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    bool StreamPage::startNewFrameProcessor(hstring url) {
        this->frameProcessor = getFrameProcessor(to_string(url).c_str());
        if (!frameProcessor) return false;

        frameProcessor->onMetadataDecoded =
            [strongThis = get_strong(), this](std::unordered_map<KLVKey, KLVData> klvmap) {
                this->onMetadataDecoded(klvmap);
            };

        return true;
    }

    void StreamPage::OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args) {

        auto propertyValue{ args.Parameter().as<Windows::Foundation::IPropertyValue>() };

        if (propertyValue.Type() == Windows::Foundation::PropertyType::String) {
            auto url{ winrt::unbox_value<winrt::hstring>(args.Parameter()) };
            if (!url.empty()) {
                bool ok = startNewFrameProcessor(url);
                if (!ok) {
                    // inform user could not open given URL
                }
            }
            else {
                // inform user of empty url
            }
        }
    }

    void videocat::implementation::StreamPage::OnNavigatingFrom(Microsoft::UI::Xaml::Navigation::NavigatingCancelEventArgs const& e)
    {
    }

    void videocat::implementation::StreamPage::OnNavigatedFrom(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
    {
    }


    hstring getStringValue(std::unordered_map<KLVKey, KLVData> klvmap, KLVKey key) {
        if (auto search = klvmap.find(key); search != klvmap.end()) {
            KLVData klvData = search->second;
            if (!klvData.stringValue.empty()) {
                return to_hstring(klvData.stringValue);
            }
            else if (klvData.doubleValue != 0.0) {
                return to_hstring(klvData.doubleValue);
            }
            else if (klvData.intValue != 0) {
                return to_hstring(klvData.intValue);
            }
            else if (klvData.timeValue != 0) {
                // convert the microseconds given, to seconds because std::time_t is in seconds since epoch
                std::time_t time = klvData.timeValue * 0.000001;
                char stringTime[50] = { '/0' };
                ctime_s(stringTime, sizeof(stringTime), &time);
                return to_hstring(stringTime);
            }
        }

        return L"unknown";
    }


    void StreamPage::appendKLVData(std::unordered_map<KLVKey, KLVData> klvmap) {
        Data().Append(
            KLVDataViewDataType(
                getStringValue(klvmap, KLVPlatformCallSign),
                getStringValue(klvmap, KLVPlatformTailNumber),
                getStringValue(klvmap, KLVPlatformDesignation),
                getStringValue(klvmap, KLVSensorLatitude),
                getStringValue(klvmap, KLVSensorLongitude),
                getStringValue(klvmap, KLVSensorTrueAltitude),
                getStringValue(klvmap, KLVSensorHorizontalFieldofView),
                getStringValue(klvmap, KLVSensorVerticalFieldofView),
                getStringValue(klvmap, KLVTargetLocationLatitude),
                getStringValue(klvmap, KLVTargetLocationLongitude),
                getStringValue(klvmap, KLVTargetLocationElevation),
                getStringValue(klvmap, KLVUNIXTimeStamp)
            )
        );
    }

    void StreamPage::onMetadataDecoded(std::unordered_map<KLVKey, KLVData> klvmap)
    {
         if (this->DispatcherQueue().HasThreadAccess()) {
             appendKLVData(klvmap);
         }
         else {
             DispatcherQueue().TryEnqueue([strongThis = get_strong(), this, klvmap] {
                 appendKLVData(klvmap);
                 }
             );
         }
    }
    void StreamPage::cleanUp()
    {
        if (frameProcessor) {
            // terminate processing
            frameProcessor->isDone = true;
            frameProcessor->onMetadataDecoded = nullptr;
            frameProcessor = nullptr;
        }
    }
}
