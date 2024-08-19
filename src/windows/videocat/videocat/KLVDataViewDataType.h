#pragma once

#include "KLVDataViewDataType.g.h"

namespace winrt::videocat::implementation
{
	struct KLVDataViewDataType : KLVDataViewDataTypeT<KLVDataViewDataType> 
	{
		KLVDataViewDataType(
			hstring callsign, 
			hstring tail,
			hstring design,
			hstring lat,
			hstring lon,
			hstring trueAlt,
			hstring hFov,
			hstring vFov,
			hstring targetLat,
			hstring targetLon,
			hstring targetEvelation,
			hstring timeStamp
		) : 
			m_callsign(callsign),
			m_tail(tail), 
			m_design(design),
			m_lat(lat),
			m_lon(lon),
			m_trueAlt(trueAlt),
			m_hFov(hFov),
			m_vFov(vFov),
			m_targetLat(targetLat), 
			m_targetLon(targetLon),
			m_targetEvelation(targetEvelation),
			m_timeStamp(timeStamp)
		{
		}

		// Property changed notifications.
		event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& value)
		{
			return m_propertyChanged.add(value);
		}

		void PropertyChanged(event_token const& token)
		{
			m_propertyChanged.remove(token);
		}

		hstring Callsign() { return m_callsign; }
		hstring TailNumber() { return m_tail; }
		hstring Designation() { return m_design; }
		hstring SensorLat() { return m_lat; }
		hstring SensorLon() { return m_lon; }
		hstring SensorTrueAlt() { return m_trueAlt; }
		hstring SensorHorzFov() { return m_hFov; }
		hstring SensorVertFov() { return m_vFov; }
		hstring TargetLat() { return m_targetLat; }
		hstring TargetLon() { return m_targetLon; }
		hstring TargetElevation() { return m_targetEvelation; }
		hstring TimeStamp() { return m_timeStamp; }
	private: 
		// Property changed notification.
		event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
		hstring m_callsign;
		hstring m_tail;
		hstring m_design;
		hstring m_lat;
		hstring m_lon;
		hstring m_trueAlt;
		hstring m_hFov;
		hstring m_vFov;
		hstring m_targetLat;
		hstring m_targetLon;
		hstring m_targetEvelation;
		hstring m_timeStamp;
	};


}

namespace winrt::videocat::factory_implementation
{
	struct KLVDataViewDataType : KLVDataViewDataTypeT<KLVDataViewDataType, implementation::KLVDataViewDataType>
	{

	};
}