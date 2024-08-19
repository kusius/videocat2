#pragma once

#include "StreamPage.g.h"
#include "Renderer/DirectXPanelBase.h"
#include <frame_process.h>
#include <videocat_utilities.h>
#include <vector>

namespace winrt::videocat::implementation
{
    struct StreamPage : StreamPageT<StreamPage>
    {

        StreamPage() 
            //: m_data(winrt::single_threaded_observable_vector<IInspectable>())
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        ~StreamPage() {
            cleanUp();
        }

        void InitializeComponent();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        videocat::KLVDataViewDataType klvDataViewData() const {
            return m_klvDataViewData;
        }

        void klvDataViewData(videocat::KLVDataViewDataType const& value) {
            m_klvDataViewData = value;
        }

        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> Data() const
        {
            return m_data;
        }

        void OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args);
        void OnNavigatingFrom(Microsoft::UI::Xaml::Navigation::NavigatingCancelEventArgs const& e);
        void OnNavigatedFrom(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);
        bool startNewFrameProcessor(hstring url);

        

    private: 
        DirectXPanelBase directXPanelBase;
        FrameProcessor* frameProcessor = nullptr;
        void appendKLVData(std::unordered_map<KLVKey, KLVData> klvmap);
        // presentation model
        videocat::KLVDataViewDataType m_klvDataViewData{ nullptr };
        // Backing field for KLV Data collection.
        winrt::Windows::Foundation::Collections::IVector<IInspectable> m_data{ winrt::single_threaded_observable_vector<IInspectable>() };

    public:
        void onMetadataDecoded(std::unordered_map<KLVKey, KLVData> klvmap);
        void cleanUp();
    };
}

namespace winrt::videocat::factory_implementation
{
    struct StreamPage : StreamPageT<StreamPage, implementation::StreamPage>
    {
    };
}
