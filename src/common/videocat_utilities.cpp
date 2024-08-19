#include <videocat_utilities.h>


KLVKey getKeyFromInt(uint8_t key) {
	switch (key)
	{
	case 0x01: return KLVChecksum; break;
	case 0x02: return KLVUNIXTimeStamp; break;
	case 0x03: return KLVMissionID; break;
	case 0x04: return KLVPlatformTailNumber; break;
	case 0x05: return KLVPlatformHeadingAngle; break;
	case 0x06: return KLVPlatformPitchAngle; break;
	case 0x07: return KLVPlatformRollAngle; break;
	case 0x08: return KLVPlatformTrueAirspeed; break;
	case 0x09: return KLVPlatformIndicatedAirspeed; break;
	case 0x0A: return KLVPlatformDesignation; break;
	case 0x0B: return KLVImageSourceSensor; break;
	case 0x0C: return KLVImageCoordinateSystem; break;
	case 0x0D: return KLVSensorLatitude; break;
	case 0x0E: return KLVSensorLongitude; break;
	case 0x0F: return KLVSensorTrueAltitude; break;
	case 0x10: return KLVSensorHorizontalFieldofView; break;
	case 0x11: return KLVSensorVerticalFieldofView; break;
	case 0x12: return KLVSensorRelativeAzimuthAngle; break;
	case 0x13: return KLVSensorRelativeElevationAngle; break;
	case 0x14: return KLVSensorRelativeRollAngle; break;
	case 0x15: return KLVSlantRange; break;
	case 0x16: return KLVTargetWidth; break;
	case 0x17: return KLVFrameCenterLatitude; break;
	case 0x18: return KLVFrameCenterLongitude; break;
	case 0x19: return KLVFrameCenterElevation; break;
	case 0x1A: return KLVOffsetCornerLatitudePoint1; break;
	case 0x1B: return KLVOffsetCornerLongitudePoint1; break;
	case 0x1C: return KLVOffsetCornerLatitudePoint2; break;
	case 0x1D: return KLVOffsetCornerLongitudePoint2; break;
	case 0x1E: return KLVOffsetCornerLatitudePoint3; break;
	case 0x1F: return KLVOffsetCornerLongitudePoint3; break;
	case 0x20: return KLVOffsetCornerLatitudePoint4; break;
	case 0x21: return KLVOffsetCornerLongitudePoint4; break;
	case 0x22: return KLVIcingDetected; break;
	case 0x23: return KLVWindDirection; break;
	case 0x24: return KLVWindSpeed; break;
	case 0x25: return KLVStaticPressure; break;
	case 0x26: return KLVDensityAltitude; break;
	case 0x27: return KLVOutsideAirTemperature; break;
	case 0x28: return KLVTargetLocationLatitude; break;
	case 0x29: return KLVTargetLocationLongitude; break;
	case 0x2A: return KLVTargetLocationElevation; break;
	case 0x2B: return KLVTargetTrackGateWidth; break;
	case 0x2C: return KLVTargetTrackGateHeight; break;
	case 0x2D: return KLVTargetErrorEstimateCE90; break;
	case 0x2E: return KLVTargetErrorEstimateLE90; break;
	case 0x2F: return KLVGenericFlagData01; break;
	case 0x30: return KLVSecurityLocalMetadataSet; break;
	case 0x31: return KLVDifferentialPressure; break;
	case 0x32: return KLVPlatformAngleofAttack; break;
	case 0x33: return KLVPlatformVerticalSpeed; break;
	case 0x34: return KLVPlatformSideslipAngle; break;
	case 0x35: return KLVAirfieldBarometicPressure; break;
	case 0x36: return KLVAirfieldElevation; break;
	case 0x37: return KLVRelativeHumidity; break;
	case 0x38: return KLVPlatformGroundSpeed; break;
	case 0x39: return KLVGroundRange; break;
	case 0x3A: return KLVPlatformFuelRemaining; break;
	case 0x3B: return KLVPlatformCallSign; break;
	case 0x3C: return KLVWeaponLoad; break;
	case 0x3D: return KLVWeaponFired; break;
	case 0x3E: return KLVLaserPRFCode; break;
	case 0x3F: return KLVSensorFieldofViewName; break;
	case 0x40: return KLVPlatformMagneticHeading; break;
	case 0x41: return KLVUASLDSVersionNumber; break;
	case 0x42: return KLVTargetLocationCovarianceMatrix; break;
	case 0x43: return KLVAlternatePlatformLatitude; break;
	case 0x44: return KLVAlternatePlatformLongitude; break;
	case 0x45: return KLVAlternatePlatformAltitude; break;
	case 0x46: return KLVAlternatePlatformName; break;
	case 0x47: return KLVAlternatePlatformHeading; break;
	case 0x48: return KLVEventStartTimeUTC; break;
	case 0x49: return KLVRVTLocalDataSet; break;
	case 0x4A: return KLVVMTILocalDataSet; break;
	case 0x4B: return KLVSensorEllipsoidHeight; break;
	case 0x4C: return KLVAlternatePlatformEllipsoidHeight; break;
	case 0x4D: return KLVOperationalMode; break;
	case 0x4E: return KLVFrameCenterHeightAboveEllipsoid; break;
	case 0x4F: return KLVSensorNorthVelocity; break;
	case 0x50: return KLVSensorEastVelocity; break;
	case 0x51: return KLVImageHorizonPixelPack; break;
	case 0x52: return KLVCornerLatitudePoint1Full; break;
	case 0x53: return KLVCornerLongitudePoint1Full; break;
	case 0x54: return KLVCornerLatitudePoint2Full; break;
	case 0x55: return KLVCornerLongitudePoint2Full; break;
	case 0x56: return KLVCornerLatitudePoint3Full; break;
	case 0x57: return KLVCornerLongitudePoint3Full; break;
	case 0x58: return KLVCornerLatitudePoint4Full; break;
	case 0x59: return KLVCornerLongitudePoint4Full; break;
	case 0x5A: return KLVPlatformPitchAngleFull; break;
	case 0x5B: return KLVPlatformRollAngleFull; break;
	case 0x5C: return KLVPlatformAngleofAttackFull; break;
	case 0x5D: return KLVPlatformSideslipAngleFull; break;
	case 0x5E: return KLVMIISCoreIdentifier; break;
	case 0x5F: return KLVSARMotionImageryMetadata; break;
	case 0x60: return KLVTargetWidthExtended; break;
	case 0x61: return KLVRangeImageLocalSet; break;
	case 0x62: return KLVGeoRegistrationLocalSet; break;
	case 0x63: return KLVCompositeImagingLocalSet; break;
	case 0x64: return KLVSegmentLocalSet; break;
	case 0x65: return KLVAmendLocalSet; break;
	case 0x66: return KLVSDCCFLP; break;
	case 0x67: return KLVDensityAltitudeExtended; break;
	case 0x68: return KLVSensorEllipsoidHeightExtended; break;
	case 0x69: return KLVAlternatePlatformEllipsoidHeightExtended; break;
	case 0x6A: return KLVStreamDesignator; break;
	case 0x6B: return KLVOperationalBase; break;
	case 0x6C: return KLVBroadcastSource; break;
	case 0x6D: return KLVRangeToRecoveryLocation; break;
	case 0x6E: return KLVTimeAirborne; break;
	case 0x6F: return KLVPropulsionUnitSpeed; break;
	case 0x70: return KLVPlatformCourseAngle; break;
	case 0x71: return KLVAltitudeAGL; break;
	case 0x72: return KLVRadarAltimeter; break;
	case 0x73: return KLVControlCommand; break;
	case 0x74: return KLVControlCommandVerificationList; break;
	case 0x75: return KLVSensorAzimuthRate; break;
	case 0x76: return KLVSensorElevationRate; break;
	case 0x77: return KLVSensorRollRate; break;
	case 0x78: return KLVOnboardMIStoragePercentFull; break;
	case 0x79: return KLVActiveWavelengthList; break;
	case 0x7A: return KLVCountryCodes; break;
	case 0x7B: return KLVNumberofNAVSATsinView; break;
	case 0x7C: return KLVPositioningMethodSource; break;
	case 0x7D: return KLVPlatformStatus; break;
	case 0x7E: return KLVSensorControlMode; break;
	case 0x7F: return KLVSensorFrameRatePack; break;
	case 0x80: return KLVWavelengthsList; break;
	case 0x81: return KLVTargetID; break;
	case 0x82: return KLVAirbaseLocations; break;
	case 0x83: return KLVTakeoffTime; break;
	case 0x84: return KLVTransmissionFrequency; break;
	case 0x85: return KLVOnboardMIStorageCapacity; break;
	case 0x86: return KLVZoomPercentage; break;
	case 0x87: return KLVCommunicationsMethod; break;
	case 0x88: return KLVLeapSeconds; break;
	case 0x89: return KLVCorrectionOffset; break;
	case 0x8A: return KLVPayloadList; break;
	case 0x8B: return KLVActivePayloads; break;
	case 0x8C: return KLVWeaponsStores; break;
	case 0x8D: return KLVWaypointList; break;
	default:
		return KLVUnknown; break;
	}
}

std::string getKeyAsString(uint8_t key) {
	std::string name;

	switch (key)
	{
	case  KLVChecksum: name = "KLVChecksum"; break;
	case  KLVUNIXTimeStamp: name = "KLVUNIXTimeStamp"; break;
	case  KLVMissionID: name = "KLVMissionID"; break;
	case  KLVPlatformTailNumber: name = "KLVPlatformTailNumber"; break;
	case  KLVPlatformHeadingAngle: name = "KLVPlatformHeadingAngle"; break;
	case  KLVPlatformPitchAngle: name = "KLVPlatformPitchAngle"; break;
	case  KLVPlatformRollAngle: name = "KLVPlatformRollAngle"; break;
	case  KLVPlatformTrueAirspeed: name = "KLVPlatformTrueAirspeed"; break;
	case  KLVPlatformIndicatedAirspeed: name = "KLVPlatformIndicatedAirspeed"; break;
	case  KLVPlatformDesignation: name = "KLVPlatformDesignation"; break;
	case  KLVImageSourceSensor: name = "KLVImageSourceSensor"; break;
	case  KLVImageCoordinateSystem: name = "KLVImageCoordinateSystem"; break;
	case  KLVSensorLatitude: name = "KLVSensorLatitude"; break;
	case  KLVSensorLongitude: name = "KLVSensorLongitude"; break;
	case  KLVSensorTrueAltitude: name = "KLVSensorTrueAltitude"; break;
	case  KLVSensorHorizontalFieldofView: name = "KLVSensorHorizontalFieldofView"; break;
	case  KLVSensorVerticalFieldofView: name = "KLVSensorVerticalFieldofView"; break;
	case  KLVSensorRelativeAzimuthAngle: name = "KLVSensorRelativeAzimuthAngle"; break;
	case  KLVSensorRelativeElevationAngle: name = "KLVSensorRelativeElevationAngle"; break;
	case  KLVSensorRelativeRollAngle: name = "KLVSensorRelativeRollAngle"; break;
	case  KLVSlantRange: name = "KLVSlantRange"; break;
	case  KLVTargetWidth: name = "KLVTargetWidth"; break;
	case  KLVFrameCenterLatitude: name = "KLVFrameCenterLatitude"; break;
	case  KLVFrameCenterLongitude: name = "KLVFrameCenterLongitude"; break;
	case  KLVFrameCenterElevation: name = "KLVFrameCenterElevation"; break;
	case  KLVOffsetCornerLatitudePoint1: name = "KLVOffsetCornerLatitudePoint1"; break;
	case  KLVOffsetCornerLongitudePoint1: name = "KLVOffsetCornerLongitudePoint1"; break;
	case  KLVOffsetCornerLatitudePoint2: name = "KLVOffsetCornerLatitudePoint2"; break;
	case  KLVOffsetCornerLongitudePoint2: name = "KLVOffsetCornerLongitudePoint2"; break;
	case  KLVOffsetCornerLatitudePoint3: name = "KLVOffsetCornerLatitudePoint3"; break;
	case  KLVOffsetCornerLongitudePoint3: name = "KLVOffsetCornerLongitudePoint3"; break;
	case  KLVOffsetCornerLatitudePoint4: name = "KLVOffsetCornerLatitudePoint4"; break;
	case  KLVOffsetCornerLongitudePoint4: name = "KLVOffsetCornerLongitudePoint4"; break;
	case  KLVIcingDetected: name = "KLVIcingDetected"; break;
	case  KLVWindDirection: name = "KLVWindDirection"; break;
	case  KLVWindSpeed: name = "KLVWindSpeed"; break;
	case  KLVStaticPressure: name = "KLVStaticPressure"; break;
	case  KLVDensityAltitude: name = "KLVDensityAltitude"; break;
	case  KLVOutsideAirTemperature: name = "KLVOutsideAirTemperature"; break;
	case  KLVTargetLocationLatitude: name = "KLVTargetLocationLatitude"; break;
	case  KLVTargetLocationLongitude: name = "KLVTargetLocationLongitude"; break;
	case  KLVTargetLocationElevation: name = "KLVTargetLocationElevation"; break;
	case  KLVTargetTrackGateWidth: name = "KLVTargetTrackGateWidth"; break;
	case  KLVTargetTrackGateHeight: name = "KLVTargetTrackGateHeight"; break;
	case  KLVTargetErrorEstimateCE90: name = "KLVTargetErrorEstimateCE90"; break;
	case  KLVTargetErrorEstimateLE90: name = "KLVTargetErrorEstimateLE90"; break;
	case  KLVGenericFlagData01: name = "KLVGenericFlagData01"; break;
	case  KLVSecurityLocalMetadataSet: name = "KLVSecurityLocalMetadataSet"; break;
	case  KLVDifferentialPressure: name = "KLVDifferentialPressure"; break;
	case  KLVPlatformAngleofAttack: name = "KLVPlatformAngleofAttack"; break;
	case  KLVPlatformVerticalSpeed: name = "KLVPlatformVerticalSpeed"; break;
	case  KLVPlatformSideslipAngle: name = "KLVPlatformSideslipAngle"; break;
	case  KLVAirfieldBarometicPressure: name = "KLVAirfieldBarometicPressure"; break;
	case  KLVAirfieldElevation: name = "KLVAirfieldElevation"; break;
	case  KLVRelativeHumidity: name = "KLVRelativeHumidity"; break;
	case  KLVPlatformGroundSpeed: name = "KLVPlatformGroundSpeed"; break;
	case  KLVGroundRange: name = "KLVGroundRange"; break;
	case  KLVPlatformFuelRemaining: name = "KLVPlatformFuelRemaining"; break;
	case  KLVPlatformCallSign: name = "KLVPlatformCallSign"; break;
	case  KLVWeaponLoad: name = "KLVWeaponLoad"; break;
	case  KLVWeaponFired: name = "KLVWeaponFired"; break;
	case  KLVLaserPRFCode: name = "KLVLaserPRFCode"; break;
	case  KLVSensorFieldofViewName: name = "KLVSensorFieldofViewName"; break;
	case  KLVPlatformMagneticHeading: name = "KLVPlatformMagneticHeading"; break;
	case  KLVUASLDSVersionNumber: name = "KLVUASLDSVersionNumber"; break;
	case  KLVTargetLocationCovarianceMatrix: name = "KLVTargetLocationCovarianceMatrix"; break;
	case  KLVAlternatePlatformLatitude: name = "KLVAlternatePlatformLatitude"; break;
	case  KLVAlternatePlatformLongitude: name = "KLVAlternatePlatformLongitude"; break;
	case  KLVAlternatePlatformAltitude: name = "KLVAlternatePlatformAltitude"; break;
	case  KLVAlternatePlatformName: name = "KLVAlternatePlatformName"; break;
	case  KLVAlternatePlatformHeading: name = "KLVAlternatePlatformHeading"; break;
	case  KLVEventStartTimeUTC: name = "KLVEventStartTimeUTC"; break;
	case  KLVRVTLocalDataSet: name = "KLVRVTLocalDataSet"; break;
	case  KLVVMTILocalDataSet: name = "KLVVMTILocalDataSet"; break;
	case  KLVSensorEllipsoidHeight: name = "KLVSensorEllipsoidHeight"; break;
	case  KLVAlternatePlatformEllipsoidHeight: name = "KLVAlternatePlatformEllipsoidHeight"; break;
	case  KLVOperationalMode: name = "KLVOperationalMode"; break;
	case  KLVFrameCenterHeightAboveEllipsoid: name = "KLVFrameCenterHeightAboveEllipsoid"; break;
	case  KLVSensorNorthVelocity: name = "KLVSensorNorthVelocity"; break;
	case  KLVSensorEastVelocity: name = "KLVSensorEastVelocity"; break;
	case  KLVImageHorizonPixelPack: name = "KLVImageHorizonPixelPack"; break;
	case  KLVCornerLatitudePoint1Full: name = "KLVCornerLatitudePoint1Full"; break;
	case  KLVCornerLongitudePoint1Full: name = "KLVCornerLongitudePoint1Full"; break;
	case  KLVCornerLatitudePoint2Full: name = "KLVCornerLatitudePoint2Full"; break;
	case  KLVCornerLongitudePoint2Full: name = "KLVCornerLongitudePoint2Full"; break;
	case  KLVCornerLatitudePoint3Full: name = "KLVCornerLatitudePoint3Full"; break;
	case  KLVCornerLongitudePoint3Full: name = "KLVCornerLongitudePoint3Full"; break;
	case  KLVCornerLatitudePoint4Full: name = "KLVCornerLatitudePoint4Full"; break;
	case  KLVCornerLongitudePoint4Full: name = "KLVCornerLongitudePoint4Full"; break;
	case  KLVPlatformPitchAngleFull: name = "KLVPlatformPitchAngleFull"; break;
	case  KLVPlatformRollAngleFull: name = "KLVPlatformRollAngleFull"; break;
	case  KLVPlatformAngleofAttackFull: name = "KLVPlatformAngleofAttackFull"; break;
	case  KLVPlatformSideslipAngleFull: name = "KLVPlatformSideslipAngleFull"; break;
	case  KLVMIISCoreIdentifier: name = "KLVMIISCoreIdentifier"; break;
	case  KLVSARMotionImageryMetadata: name = "KLVSARMotionImageryMetadata"; break;
	case  KLVTargetWidthExtended: name = "KLVTargetWidthExtended"; break;
	case  KLVRangeImageLocalSet: name = "KLVRangeImageLocalSet"; break;
	case  KLVGeoRegistrationLocalSet: name = "KLVGeoRegistrationLocalSet"; break;
	case  KLVCompositeImagingLocalSet: name = "KLVCompositeImagingLocalSet"; break;
	case  KLVSegmentLocalSet: name = "KLVSegmentLocalSet"; break;
	case  KLVAmendLocalSet: name = "KLVAmendLocalSet"; break;
	case  KLVSDCCFLP: name = "KLVSDCCFLP"; break;
	case  KLVDensityAltitudeExtended: name = "KLVDensityAltitudeExtended"; break;
	case  KLVSensorEllipsoidHeightExtended: name = "KLVSensorEllipsoidHeightExtended"; break;
	case  KLVAlternatePlatformEllipsoidHeightExtended: name = "KLVAlternatePlatformEllipsoidHeightExtended"; break;
	case  KLVStreamDesignator: name = "KLVStreamDesignator"; break;
	case  KLVOperationalBase: name = "KLVOperationalBase"; break;
	case  KLVBroadcastSource: name = "KLVBroadcastSource"; break;
	case  KLVRangeToRecoveryLocation: name = "KLVRangeToRecoveryLocation"; break;
	case  KLVTimeAirborne: name = "KLVTimeAirborne"; break;
	case  KLVPropulsionUnitSpeed: name = "KLVPropulsionUnitSpeed"; break;
	case  KLVPlatformCourseAngle: name = "KLVPlatformCourseAngle"; break;
	case  KLVAltitudeAGL: name = "KLVAltitudeAGL"; break;
	case  KLVRadarAltimeter: name = "KLVRadarAltimeter"; break;
	case  KLVControlCommand: name = "KLVControlCommand"; break;
	case  KLVControlCommandVerificationList: name = "KLVControlCommandVerificationList"; break;
	case  KLVSensorAzimuthRate: name = "KLVSensorAzimuthRate"; break;
	case  KLVSensorElevationRate: name = "KLVSensorElevationRate"; break;
	case  KLVSensorRollRate: name = "KLVSensorRollRate"; break;
	case  KLVOnboardMIStoragePercentFull: name = "KLVOnboardMIStoragePercentFull"; break;
	case  KLVActiveWavelengthList: name = "KLVActiveWavelengthList"; break;
	case  KLVCountryCodes: name = "KLVCountryCodes"; break;
	case  KLVNumberofNAVSATsinView: name = "KLVNumberofNAVSATsinView"; break;
	case  KLVPositioningMethodSource: name = "KLVPositioningMethodSource"; break;
	case  KLVPlatformStatus: name = "KLVPlatformStatus"; break;
	case  KLVSensorControlMode: name = "KLVSensorControlMode"; break;
	case  KLVSensorFrameRatePack: name = "KLVSensorFrameRatePack"; break;
	case  KLVWavelengthsList: name = "KLVWavelengthsList"; break;
	case  KLVTargetID: name = "KLVTargetID"; break;
	case  KLVAirbaseLocations: name = "KLVAirbaseLocations"; break;
	case  KLVTakeoffTime: name = "KLVTakeoffTime"; break;
	case  KLVTransmissionFrequency: name = "KLVTransmissionFrequency"; break;
	case  KLVOnboardMIStorageCapacity: name = "KLVOnboardMIStorageCapacity"; break;
	case  KLVZoomPercentage: name = "KLVZoomPercentage"; break;
	case  KLVCommunicationsMethod: name = "KLVCommunicationsMethod"; break;
	case  KLVLeapSeconds: name = "KLVLeapSeconds"; break;
	case  KLVCorrectionOffset: name = "KLVCorrectionOffset"; break;
	case  KLVPayloadList: name = "KLVPayloadList"; break;
	case  KLVActivePayloads: name = "KLVActivePayloads"; break;
	case  KLVWeaponsStores: name = "KLVWeaponsStores"; break;
	case  KLVWaypointList: name = "KLVWaypointList"; break;
	default:
		name = "KLVUnknown";
	}

	return name;
}


// Terminal control handling 
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	BOOL WINAPI ctrlHandler(DWORD controlType) {
		switch(controlType) {
			case CTRL_C_EVENT:
				return TRUE;
			case CTRL_CLOSE_EVENT: 
				return TRUE;
			case CTRL_BREAK_EVENT:
				return TRUE;
			default: 
				return FALSE;
		}
	}	

	void initPlatform() {
		SetConsoleCtrlHandler(ctrlHandler, TRUE);
	}

#else
	void initPlatform() {}
	bool ctrlHandler(unsigned long) {}
#endif