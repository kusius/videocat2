#ifndef KEYS_H
#define KEYS_H

#include <stdint.h>


static const uint8_t LDS_UNIVERSAL_KEY[16] = {0x06, 0x0e, 0x2b, 0x34, 0x02, 0x0b, 0x01, 0x01, 0x0e, 0x01, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00};

enum Format {
  UINT8_F,
  UINT16_F,
  UINT32_F,
  UINT64_F,
  INT8_F,
  INT16_F,
  INT32_F,
  INT64_F,
  FLOAT_F,
  DOUBLE_F,
  CHAR_P_F,
};

struct GenericValue {
  enum Format type;
  union {
    uint8_t uint8_value;
    uint16_t uint16_value;
    uint32_t uint32_value;
    uint64_t uint64_value;
    int8_t int8_value;
    int16_t int16_value;
    int32_t int32_value;
    int64_t int64_value;
    float float_value;
    double double_value;
    char *charp_value;
  };
};


struct Range {
  struct GenericValue min;
  struct GenericValue max;
};


struct Field {
  uint8_t key;
  enum Format encoded_format;
  enum Format value_format;
  uint8_t len;
  struct Range range;
};


// All KLVs tags from the MISB0601
enum Tags {
  CHECKSUM = 1,
  UNIX_TIME_STAMP = 2,
  MISSION_ID = 3,
  PLATFORM_TAIL_NUMBER = 4,
  PLATFORM_HEADING_ANGLE = 5,
  PLATFORM_PITCH_ANGLE = 6,
  PLATFORM_ROLL_ANGLE = 7,
  PLATFORM_TRUE_AIRSPEED = 8,
  PLATFORM_INDICATED_AIRSPEED = 9,
  PLATFORM_DESIGNATION = 10,
  IMAGE_SOURCE_SENSOR = 11,
  IMAGE_COORDINATE_SYSTEM = 12,
  SENSOR_LATITUDE = 13,
  SENSOR_LONGITUDE = 14,
  SENSOR_TRUE_ALTITUDE = 15,
  SENSOR_HORIZONTAL_FOV = 16,
  SENSOR_VERTICAL_FOV = 17,
  SENSOR_RELATIVE_AZIMUTH_ANGLE = 18,
  SENSOR_RELATIVE_ELEVATION_ANGLE = 19,
  SENSOR_RELATIVE_ROLL_ANGLE = 20,
  SLANT_RANGE = 21,
  TARGET_WIDTH = 22,
  FRAME_CENTER_LATITUDE = 23,
  FRAME_CENTER_LONGITUDE = 24,
  FRAME_CENTER_ELEVATION = 25,
  OFFSET_CORNER_LATITUDE_POINT_1 = 26,
  OFFSET_CORNER_LONGITUDE_POINT_1 = 27,
  OFFSET_CORNER_LATITUDE_POINT_2 = 28,
  OFFSET_CORNER_LONGITUDE_POINT_2 = 29,
  OFFSET_CORNER_LATITUDE_POINT_3 = 30,
  OFFSET_CORNER_LONGITUDE_POINT_3 = 31,
  OFFSET_CORNER_LATITUDE_POINT_4 = 32,
  OFFSET_CORNER_LONGITUDE_POINT_4 = 33,
  ICING_DETECTED = 34,
  WIND_DIRECTION = 35,
  WIND_SPEED = 36,
  STATIC_PRESSURE = 37,
  DENSITY_ALTITUDE = 38,
  OUTSIDE_AIR_TEMPERATURE = 39,
  TARGET_LOCATION_LATITUDE = 40,
  TARGET_LOCATION_LONGITUDE = 41,
  TARGET_LOCATION_ELEVATION = 42,
  TARGET_TRACK_GATE_WIDTH = 43,
  TARGET_TRACK_GATE_HEIGHT = 44,
  TARGET_ERROR_ESTIMATE_CE90 = 45,
  TARGET_ERROR_ESTIMATE_LE90 = 46,
  GENERIC_FLAG_DATA1 = 47,
  SECURITY_LOCAL_METADATA_SET = 48,
  DIFFERENTIAL_PRESSURE = 49,
  PLATFORM_ANGLE_OF_ATTACK = 50,
  PLATFORM_VERTICAL_SPEED = 51,
  PLATFORM_SIDESLIP_ANGLE = 52,
  AIRFIELD_BAROMETRIC_PRESSURE = 53,
  AIRFIELD_ELEVATION = 54,
  RELATIVE_HUMIDITY = 55,
  PLATFORM_GROUND_SPEED = 56,
  GROUND_RANGE = 57,
  PLATFORM_FUEL_REMAINING = 58,
  PLATFORM_CALL_SIGN = 59,
  WEAPON_LOAD = 60,
  WEAPON_FIRED = 61,
  LASER_PRF_CODE = 62,
  SENSOR_FOV_NAME = 63,
  PLATFORM_MAGNETIC_HEADING = 64,
  UAS_LDS_VERSION_NUMBER = 65,
  TARGET_LOCATION_COVARIANCE_MATRIX = 66,
  ALTERNATE_PLATFORM_LATITUDE = 67,
  ALTERNATE_PLATFORM_LONGITUDE = 68,
  ALTERNATE_PLATFORM_ALTITUDE = 69,
  ALTERNATE_PLATFORM_NAME = 70,
  ALTERNATE_PLATFORM_HEADING = 71,
  EVENT_START_TIME_UTC = 72,
  RVT_LOCAL_DATA_SET = 73,
  VMTI_LOCAL_DATA_SET = 74,
  SENSOR_ELLIPSOID_HEIGHT = 75,
  ALTERNATE_PLATFORM_ELLIPSOID_HEIGHT = 76,
  OPERATIONAL_MODE = 77,
  FRAME_CENTER_HEIGHT_ABOVE_ELLIPSOID = 78,
  SENSOR_NORTH_VELOCITY = 79,
  SENSOR_EAST_VELOCITY = 80,
  IMAGE_HORIZON_PIXEL_PACK = 81,
  CORNER_LATITUDE_POINT_1 = 82,
  CORNER_LONGITUDE_POINT_1 = 83,
  CORNER_LATITUDE_POINT_2 = 84,
  CORNER_LONGITUDE_POINT_2 = 85,
  CORNER_LATITUDE_POINT_3 = 86,
  CORNER_LONGITUDE_POINT_3 = 87,
  CORNER_LATITUDE_POINT_4 = 88,
  CORNER_LONGITUDE_POINT_4 = 89,
  PLATFORM_PITCH_ANGLE_F = 90,
  PLATFORM_ROLL_ANGLE_F = 91,
  PLATFORM_ANGLE_OF_ATTACK_F = 92,
  PLATFORM_SIDESLIP_ANGLE_F = 93,
  KEYS_COUNT
};


static const struct Field FieldMap[94] = {
  // First one is dummy to align index with tag number
  {
    .key = CHECKSUM,
    .encoded_format = UINT16_F,
    .value_format = UINT16_F,
    .len = 2,
    .range = {
      {.type = UINT16_F, .uint16_value = 0},
      {.type = UINT16_F, .uint16_value = 65535}
    },
  },
  {
    .key = CHECKSUM,
    .encoded_format = UINT16_F,
    .value_format = UINT16_F,
    .len = 2,
    .range = {
      {.type = UINT16_F, .uint16_value = 0},
      {.type = UINT16_F, .uint16_value = 65535}
    },
  },
  {
    .key = UNIX_TIME_STAMP,
    .encoded_format = UINT64_F,
    .value_format = UINT64_F,
    .len = 8,
    .range = {
      {.type = UINT64_F, .uint64_value = 0},
      {.type = UINT64_F, .uint64_value = 18446744073709551615U}
    },
  },
  {
    .key = MISSION_ID,
    .encoded_format = CHAR_P_F,
    .value_format = CHAR_P_F,
    .len = 127,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 127}
    },
  },
  {
    .key = PLATFORM_TAIL_NUMBER,
    .encoded_format = CHAR_P_F,
    .value_format = CHAR_P_F,
    .len = 127,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 127}
    },
  },
  {
    .key = PLATFORM_HEADING_ANGLE,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 360}
    },
  },
  {
    .key = PLATFORM_PITCH_ANGLE,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -20},
      {.type = FLOAT_F, .float_value = 20}
    },
  },
  {
    .key = PLATFORM_ROLL_ANGLE,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -50},
      {.type = FLOAT_F, .float_value = 50}
    },
  },
  {
    .key = PLATFORM_TRUE_AIRSPEED,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 255}
    },
  },
  {
    .key = PLATFORM_INDICATED_AIRSPEED,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 255}
    },
  },
  {
    .key = PLATFORM_DESIGNATION,
    .encoded_format = CHAR_P_F,
    .value_format = CHAR_P_F,
    .len = 127,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 127}
    },
  },
  {
    .key = IMAGE_SOURCE_SENSOR,
    .encoded_format = CHAR_P_F,
    .value_format = CHAR_P_F,
    .len = 127,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 127}
    },
  },
  {
    .key = IMAGE_COORDINATE_SYSTEM,
    .encoded_format = CHAR_P_F,
    .value_format = CHAR_P_F,
    .len = 127,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 127}
    },
  },
  {
    .key = SENSOR_LATITUDE,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -90},
      {.type = DOUBLE_F, .double_value = 90}
    },
  },
  {
    .key = SENSOR_LONGITUDE,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -180},
      {.type = DOUBLE_F, .double_value = 180}
    },
  },
  {
    .key = SENSOR_TRUE_ALTITUDE,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = DOUBLE_F, .double_value = -900},
      {.type = DOUBLE_F, .double_value = 19000}
    },
  },
  {
    .key = SENSOR_HORIZONTAL_FOV,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = DOUBLE_F, .double_value = 0},
      {.type = DOUBLE_F, .double_value = 180}
    },
  },
  {
    .key = SENSOR_VERTICAL_FOV,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = DOUBLE_F, .double_value = 0},
      {.type = DOUBLE_F, .double_value = 180}
    },
  },
  {
    .key = SENSOR_RELATIVE_AZIMUTH_ANGLE,
    .encoded_format = UINT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = 0},
      {.type = DOUBLE_F, .double_value = 360}
    },
  },
  {
    .key = SENSOR_RELATIVE_ELEVATION_ANGLE,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -180},
      {.type = DOUBLE_F, .double_value = 180}
    },
  },
  {
    .key = SENSOR_RELATIVE_ROLL_ANGLE,
    .encoded_format = UINT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = 0},
      {.type = DOUBLE_F, .double_value = 360}
    },
  },
  {
    .key = SLANT_RANGE,
    .encoded_format = UINT32_F,
    .value_format = FLOAT_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = 0},
      {.type = DOUBLE_F, .double_value = 5000000}
    },
  },
  {
    .key = TARGET_WIDTH,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 10000}
    },
  },
  {
    .key = FRAME_CENTER_LATITUDE,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -90},
      {.type = DOUBLE_F, .double_value = 90}
    },
  },
  {
    .key = FRAME_CENTER_LONGITUDE,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -180},
      {.type = DOUBLE_F, .double_value = 180}
    },
  },
  {
    .key = FRAME_CENTER_ELEVATION,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -900},
      {.type = FLOAT_F, .float_value = 19000}
    },
  },
  {
    .key = OFFSET_CORNER_LATITUDE_POINT_1,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -0.075},
      {.type = FLOAT_F, .float_value = 0.075}
    },
  },
  {
    .key = OFFSET_CORNER_LONGITUDE_POINT_1,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -0.075},
      {.type = FLOAT_F, .float_value = 0.075}
    },
  },
  {
    .key = OFFSET_CORNER_LATITUDE_POINT_2,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -0.075},
      {.type = FLOAT_F, .float_value = 0.075}
    },
  },
  {
    .key = OFFSET_CORNER_LONGITUDE_POINT_2,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -0.075},
      {.type = FLOAT_F, .float_value = 0.075}
    },
  },
  {
    .key = OFFSET_CORNER_LATITUDE_POINT_3,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -0.075},
      {.type = FLOAT_F, .float_value = 0.075}
    },
  },
  {
    .key = OFFSET_CORNER_LONGITUDE_POINT_3,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -0.075},
      {.type = FLOAT_F, .float_value = 0.075}
    },
  },
  {
    .key = OFFSET_CORNER_LATITUDE_POINT_4,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -0.075},
      {.type = FLOAT_F, .float_value = 0.075}
    },
  },
  {
    .key = OFFSET_CORNER_LONGITUDE_POINT_4,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -0.075},
      {.type = FLOAT_F, .float_value = 0.075}
    },
  },
  {
    .key = ICING_DETECTED,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 255}
    },
  },
  {
    .key = WIND_DIRECTION,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 360}
    },
  },
  {
    .key = WIND_SPEED,
    .encoded_format = UINT8_F,
    .value_format = FLOAT_F,
    .len = 1,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 100}
    },
  },
  {
    .key = STATIC_PRESSURE,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 5000}
    },
  },
  {
    .key = DENSITY_ALTITUDE,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -900},
      {.type = FLOAT_F, .float_value = 19000}
    },
  },
  {
    .key = OUTSIDE_AIR_TEMPERATURE,
    .encoded_format = INT8_F,
    .value_format = INT8_F,
    .len = 1,
    .range = {
      {.type = INT8_F, .int8_value = -128},
      {.type = INT8_F, .int8_value = 127}
    },
  },
  {
    .key = TARGET_LOCATION_LATITUDE,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -90},
      {.type = DOUBLE_F, .double_value = 90}
    },
  },
  {
    .key = TARGET_LOCATION_LONGITUDE,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -180},
      {.type = DOUBLE_F, .double_value = 180}
    },
  },
  {
    .key = TARGET_LOCATION_ELEVATION,
    .encoded_format = INT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -900},
      {.type = FLOAT_F, .float_value = 19000}
    },
  },
  {
    .key = TARGET_TRACK_GATE_WIDTH,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT16_F, .uint16_value = 0},
      {.type = UINT16_F, .uint16_value = 512}
    },
  },
  {
    .key = TARGET_TRACK_GATE_HEIGHT,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT16_F, .uint16_value = 0},
      {.type = UINT16_F, .uint16_value = 512}
    },
  },
  {
    .key = TARGET_ERROR_ESTIMATE_CE90,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 4095}
    },
  },
  {
    .key = TARGET_ERROR_ESTIMATE_LE90,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 4095}
    },
  },
  {
    .key = GENERIC_FLAG_DATA1,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 255}
    },
  },
  // TODO really not ready to be used, information are dummies
  {
    .key = SECURITY_LOCAL_METADATA_SET,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 255}
    },
  },
  {
    .key = DIFFERENTIAL_PRESSURE,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 5000}
    },
  },
  {
    .key = PLATFORM_ANGLE_OF_ATTACK,
    .encoded_format = INT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -20},
      {.type = FLOAT_F, .float_value = 20}
    },
  },
  {
    .key = PLATFORM_VERTICAL_SPEED,
    .encoded_format = INT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -180},
      {.type = FLOAT_F, .float_value = 180}
    },
  },
  {
    .key = PLATFORM_SIDESLIP_ANGLE,
    .encoded_format = INT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -20},
      {.type = FLOAT_F, .float_value = 20}
    },
  },
  {
    .key = AIRFIELD_BAROMETRIC_PRESSURE,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 5000}
    },
  },
  {
    .key = AIRFIELD_ELEVATION,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -900},
      {.type = FLOAT_F, .float_value = 19000}
    },
  },
  {
    .key = RELATIVE_HUMIDITY,
    .encoded_format = UINT8_F,
    .value_format = FLOAT_F,
    .len = 1,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 100}
    },
  },
  {
    .key = PLATFORM_GROUND_SPEED,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 255}
    },
  },
  {
    .key = GROUND_RANGE,
    .encoded_format = UINT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = 0},
      {.type = DOUBLE_F, .double_value = 5000000}
    },
  },
  {
    .key = PLATFORM_FUEL_REMAINING,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = DOUBLE_F, .double_value = 0},
      {.type = DOUBLE_F, .double_value = 10000}
    },
  },
  {
    .key = PLATFORM_CALL_SIGN,
    .encoded_format = CHAR_P_F,
    .value_format = CHAR_P_F,
    .len = 127,
    .range = {
      {.type = UINT8_F, .uint8_value = 1},
      {.type = UINT8_F, .uint8_value = 127}
    },
  },
  {
    .key = WEAPON_LOAD,
    .encoded_format = UINT16_F,
    .value_format = UINT16_F,
    .len = 2,
    .range = {
      {.type = UINT16_F, .uint16_value = 0},
      {.type = UINT16_F, .uint16_value = 65535}
    },
  },
  {
    .key = WEAPON_FIRED,
    .encoded_format = UINT16_F,
    .value_format = UINT16_F,
    .len = 2,
    .range = {
      {.type = UINT16_F, .uint16_value = 0},
      {.type = UINT16_F, .uint16_value = 65535}
    },
  },
  {
    .key = LASER_PRF_CODE,
    .encoded_format = UINT16_F,
    .value_format = UINT16_F,
    .len = 2,
    .range = {
      {.type = UINT16_F, .uint16_value = 0},
      {.type = UINT16_F, .uint16_value = 65535}
    },
  },
  {
    .key = SENSOR_FOV_NAME,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 255}
    },
  },
  {
    .key = PLATFORM_MAGNETIC_HEADING,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = UINT16_F, .uint16_value = 0},
      {.type = UINT16_F, .uint16_value = 360}
    },
  },
  {
    .key = UAS_LDS_VERSION_NUMBER,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 255}
    },
  },
  // Parameters unused in the MISB0601.6
  {
    .key = TARGET_LOCATION_COVARIANCE_MATRIX,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 255}
    },
  },
  {
    .key = ALTERNATE_PLATFORM_LATITUDE,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -90},
      {.type = DOUBLE_F, .double_value = 90}
    },
  },
  {
    .key = ALTERNATE_PLATFORM_LONGITUDE,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -180},
      {.type = DOUBLE_F, .double_value = 180}
    },
  },
  {
    .key = ALTERNATE_PLATFORM_ALTITUDE,
    .encoded_format = INT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -900},
      {.type = FLOAT_F, .float_value = 19000}
    },
  },
  {
    .key = ALTERNATE_PLATFORM_NAME,
    .encoded_format = CHAR_P_F,
    .value_format = CHAR_P_F,
    .len = 127,
    .range = {
      {.type = UINT8_F, .uint8_value = 1},
      {.type = UINT8_F, .uint8_value = 127}
    },
  },
  {
    .key = ALTERNATE_PLATFORM_HEADING,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = 0},
      {.type = FLOAT_F, .float_value = 360}
    },
  },
  {
    .key = EVENT_START_TIME_UTC,
    .encoded_format = UINT64_F,
    .value_format = UINT64_F,
    .len = 4,
    .range = {
      {.type = UINT64_F, .uint64_value = 0},
      {.type = UINT64_F, .uint64_value = 18446744073709551615U}
    },
  },
  // TODO this parameter is not handled
  {
    .key = RVT_LOCAL_DATA_SET,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 255}
    },
  },
  // TODO this parameter is not handled
  {
    .key = VMTI_LOCAL_DATA_SET,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 255}
    },
  },
  {
    .key = SENSOR_ELLIPSOID_HEIGHT,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -900},
      {.type = FLOAT_F, .float_value = 19000}
    },
  },
  {
    .key = ALTERNATE_PLATFORM_ELLIPSOID_HEIGHT,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -900},
      {.type = FLOAT_F, .float_value = 19000}
    },
  },
  {
    .key = OPERATIONAL_MODE,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 255}
    },
  },
  {
    .key = FRAME_CENTER_HEIGHT_ABOVE_ELLIPSOID,
    .encoded_format = UINT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -900},
      {.type = FLOAT_F, .float_value = 19000}
    },
  },
  {
    .key = SENSOR_NORTH_VELOCITY,
    .encoded_format = INT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -357},
      {.type = FLOAT_F, .float_value = 357}
    },
  },
  {
    .key = SENSOR_EAST_VELOCITY,
    .encoded_format = INT16_F,
    .value_format = FLOAT_F,
    .len = 2,
    .range = {
      {.type = FLOAT_F, .float_value = -357},
      {.type = FLOAT_F, .float_value = 357}
    },
  },
  {
    .key = IMAGE_HORIZON_PIXEL_PACK,
    .encoded_format = UINT8_F,
    .value_format = UINT8_F,
    .len = 1,
    .range = {
      {.type = UINT8_F, .uint8_value = 0},
      {.type = UINT8_F, .uint8_value = 255}
    },
  },
  {
    .key = CORNER_LATITUDE_POINT_1,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -90},
      {.type = DOUBLE_F, .double_value = 90}
    },
  },
  {
    .key = CORNER_LONGITUDE_POINT_1,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -180},
      {.type = DOUBLE_F, .double_value = 180}
    },
  },
  {
    .key = CORNER_LATITUDE_POINT_2,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -90},
      {.type = DOUBLE_F, .double_value = 90}
    },
  },
  {
    .key = CORNER_LONGITUDE_POINT_3,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -180},
      {.type = DOUBLE_F, .double_value = 180}
    },
  },
  {
    .key = CORNER_LATITUDE_POINT_4,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -90},
      {.type = DOUBLE_F, .double_value = 90}
    },
  },
  {
    .key = CORNER_LONGITUDE_POINT_4,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -180},
      {.type = DOUBLE_F, .double_value = 180}
    },
  },
  {
    .key = CORNER_LATITUDE_POINT_1,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -90},
      {.type = DOUBLE_F, .double_value = 90}
    },
  },
  {
    .key = CORNER_LONGITUDE_POINT_1,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -180},
      {.type = DOUBLE_F, .double_value = 180}
    },
  },
  {
    .key = PLATFORM_PITCH_ANGLE_F,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -90},
      {.type = DOUBLE_F, .double_value = 90}
    },
  },
  {
    .key = PLATFORM_ROLL_ANGLE_F,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -90},
      {.type = DOUBLE_F, .double_value = 90}
    },
  },
  {
    .key = PLATFORM_ANGLE_OF_ATTACK,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -90},
      {.type = DOUBLE_F, .double_value = 90}
    },
  },
  {
    .key = PLATFORM_SIDESLIP_ANGLE_F,
    .encoded_format = INT32_F,
    .value_format = DOUBLE_F,
    .len = 4,
    .range = {
      {.type = DOUBLE_F, .double_value = -180},
      {.type = DOUBLE_F, .double_value = 180}
    },
  }
};


#endif /* !KEYS_H */
