#ifndef VIDEOCAT_UTILS_H
#define VIDEOCAT_UTILS_H

extern "C" {
#include <stdio.h>
}


#include <string>

// _DEBUG compile flag is defined automatically by visual studio;
// on other platforms we define it ourselves in the compile invocation command.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <windows.h>

#if defined _DEBUG
#define DEBUG_PRINT(...) {char cad[512]; snprintf(cad, 512, __VA_ARGS__);  OutputDebugStringA(cad);}
#else
#define DEBUG_PRINT(...)
#endif

#else // other platforms

#if defined _DEBUG
#define DEBUG_PRINT(...) {fprintf(stderr, __VA_ARGS__);}
#else
#define DEBUG_PRINT(...)
#endif

#endif

enum KLVKey {
	KLVChecksum = 0x01,
	KLVUNIXTimeStamp = 0x02,
	KLVMissionID = 0x03,
	KLVPlatformTailNumber = 0x04,
	KLVPlatformHeadingAngle = 0x05,
	KLVPlatformPitchAngle = 0x06,
	KLVPlatformRollAngle = 0x07,
	KLVPlatformTrueAirspeed = 0x08,
	KLVPlatformIndicatedAirspeed = 0x09,
	KLVPlatformDesignation = 0x0A,
	KLVImageSourceSensor = 0x0B,
	KLVImageCoordinateSystem = 0x0C,
	KLVSensorLatitude = 0x0D,
	KLVSensorLongitude = 0x0E,
	KLVSensorTrueAltitude = 0x0F,
	KLVSensorHorizontalFieldofView = 0x10,
	KLVSensorVerticalFieldofView = 0x11,
	KLVSensorRelativeAzimuthAngle = 0x12,
	KLVSensorRelativeElevationAngle = 0x13,
	KLVSensorRelativeRollAngle = 0x14,
	KLVSlantRange = 0x15,
	KLVTargetWidth = 0x16,
	KLVFrameCenterLatitude = 0x17,
	KLVFrameCenterLongitude = 0x18,
	KLVFrameCenterElevation = 0x19,
	KLVOffsetCornerLatitudePoint1 = 0x1A,
	KLVOffsetCornerLongitudePoint1 = 0x1B,
	KLVOffsetCornerLatitudePoint2 = 0x1C,
	KLVOffsetCornerLongitudePoint2 = 0x1D,
	KLVOffsetCornerLatitudePoint3 = 0x1E,
	KLVOffsetCornerLongitudePoint3 = 0x1F,
	KLVOffsetCornerLatitudePoint4 = 0x20,
	KLVOffsetCornerLongitudePoint4 = 0x21,
	KLVIcingDetected = 0x22,
	KLVWindDirection = 0x23,
	KLVWindSpeed = 0x24,
	KLVStaticPressure = 0x25,
	KLVDensityAltitude = 0x26,
	KLVOutsideAirTemperature = 0x27,
	KLVTargetLocationLatitude = 0x28,
	KLVTargetLocationLongitude = 0x29,
	KLVTargetLocationElevation = 0x2A,
	KLVTargetTrackGateWidth = 0x2B,
	KLVTargetTrackGateHeight = 0x2C,
	KLVTargetErrorEstimateCE90 = 0x2D,
	KLVTargetErrorEstimateLE90 = 0x2E,
	KLVGenericFlagData01 = 0x2F,
	KLVSecurityLocalMetadataSet = 0x30,
	KLVDifferentialPressure = 0x31,
	KLVPlatformAngleofAttack = 0x32,
	KLVPlatformVerticalSpeed = 0x33,
	KLVPlatformSideslipAngle = 0x34,
	KLVAirfieldBarometicPressure = 0x35,
	KLVAirfieldElevation = 0x36,
	KLVRelativeHumidity = 0x37,
	KLVPlatformGroundSpeed = 0x38,
	KLVGroundRange = 0x39,
	KLVPlatformFuelRemaining = 0x3A,
	KLVPlatformCallSign = 0x3B,
	KLVWeaponLoad = 0x3C,
	KLVWeaponFired = 0x3D,
	KLVLaserPRFCode = 0x3E,
	KLVSensorFieldofViewName = 0x3F,
	KLVPlatformMagneticHeading = 0x40,
	KLVUASLDSVersionNumber = 0x41,
	KLVTargetLocationCovarianceMatrix = 0x42,
	KLVAlternatePlatformLatitude = 0x43,
	KLVAlternatePlatformLongitude = 0x44,
	KLVAlternatePlatformAltitude = 0x45,
	KLVAlternatePlatformName = 0x46,
	KLVAlternatePlatformHeading = 0x47,
	KLVEventStartTimeUTC = 0x48,
	KLVRVTLocalDataSet = 0x49,
	KLVVMTILocalDataSet = 0x4A,
	KLVSensorEllipsoidHeight = 0x4B,
	KLVAlternatePlatformEllipsoidHeight = 0x4C,
	KLVOperationalMode = 0x4D,
	KLVFrameCenterHeightAboveEllipsoid = 0x4E,
	KLVSensorNorthVelocity = 0x4F,
	KLVSensorEastVelocity = 0x50,
	KLVImageHorizonPixelPack = 0x51,
	KLVCornerLatitudePoint1Full = 0x52,
	KLVCornerLongitudePoint1Full = 0x53,
	KLVCornerLatitudePoint2Full = 0x54,
	KLVCornerLongitudePoint2Full = 0x55,
	KLVCornerLatitudePoint3Full = 0x56,
	KLVCornerLongitudePoint3Full = 0x57,
	KLVCornerLatitudePoint4Full = 0x58,
	KLVCornerLongitudePoint4Full = 0x59,
	KLVPlatformPitchAngleFull = 0x5A,
	KLVPlatformRollAngleFull = 0x5B,
	KLVPlatformAngleofAttackFull = 0x5C,
	KLVPlatformSideslipAngleFull = 0x5D,
	KLVMIISCoreIdentifier = 0x5E,
	KLVSARMotionImageryMetadata = 0x5F,
	KLVTargetWidthExtended = 0x60,
	KLVRangeImageLocalSet = 0x61,
	KLVGeoRegistrationLocalSet = 0x62,
	KLVCompositeImagingLocalSet = 0x63,
	KLVSegmentLocalSet = 0x64,
	KLVAmendLocalSet = 0x65,
	KLVSDCCFLP = 0x66,
	KLVDensityAltitudeExtended = 0x67,
	KLVSensorEllipsoidHeightExtended = 0x68,
	KLVAlternatePlatformEllipsoidHeightExtended = 0x69,
	KLVStreamDesignator = 0x6A,
	KLVOperationalBase = 0x6B,
	KLVBroadcastSource = 0x6C,
	KLVRangeToRecoveryLocation = 0x6D,
	KLVTimeAirborne = 0x6E,
	KLVPropulsionUnitSpeed = 0x6F,
	KLVPlatformCourseAngle = 0x70,
	KLVAltitudeAGL = 0x71,
	KLVRadarAltimeter = 0x72,
	KLVControlCommand = 0x73,
	KLVControlCommandVerificationList = 0x74,
	KLVSensorAzimuthRate = 0x75,
	KLVSensorElevationRate = 0x76,
	KLVSensorRollRate = 0x77,
	KLVOnboardMIStoragePercentFull = 0x78,
	KLVActiveWavelengthList = 0x79,
	KLVCountryCodes = 0x7A,
	KLVNumberofNAVSATsinView = 0x7B,
	KLVPositioningMethodSource = 0x7C,
	KLVPlatformStatus = 0x7D,
	KLVSensorControlMode = 0x7E,
	KLVSensorFrameRatePack = 0x7F,
	KLVWavelengthsList = 0x80,
	KLVTargetID = 0x81,
	KLVAirbaseLocations = 0x82,
	KLVTakeoffTime = 0x83,
	KLVTransmissionFrequency = 0x84,
	KLVOnboardMIStorageCapacity = 0x85,
	KLVZoomPercentage = 0x86,
	KLVCommunicationsMethod = 0x87,
	KLVLeapSeconds = 0x88,
	KLVCorrectionOffset = 0x89,
	KLVPayloadList = 0x8A,
	KLVActivePayloads = 0x8B,
	KLVWeaponsStores = 0x8C,
	KLVWaypointList = 0x8D,


	KLVUnknown = 0xFF
};

struct KLVData {
	KLVKey key;
	std::string keyString;
	int intValue;
	double doubleValue;
	std::string stringValue;
#ifdef WIN32
	__time64_t	timeValue;
#else
	int64_t     timeValue;
#endif
};


KLVKey getKeyFromInt(uint8_t key);
std::string getKeyAsString(uint8_t key);
void initPlatform();
bool ctrlHandler(uint32_t type);


#endif // !VIDEOCAT_UTILS_H