#pragma once
#include <string>


const double PI = 3.1415;
const double FIRST = 1.0;
const unsigned int WINDOW_WIDTH = 1900;
const unsigned int WINDOW_HEIGHT = 1000;
const int NUM_POINTS_PER_TRIANGLE = 3;
const int NUM_COORDS_PER_POINT = 2;
const int TOTAL_COORDS = NUM_POINTS_PER_TRIANGLE * NUM_COORDS_PER_POINT;

const int FIRST_X_INDEX = 0;
const int FIRST_Y_INDEX = 1;
const int SECOND_X_INDEX = 2;
const int SECOND = 2;
const int SECOND_NUM = 2;
const int SECOND_Y_INDEX = 3;
const int THIRD_X_INDEX = 4;
const int THIRD_Y_INDEX = 5;

const int FIRST_COORD_COUNT = 0;
const int SECOND_COORD_COUNT = 1;

const int ZERO = 0;

const float SIDE_OF_THE_SQUARE = 5.0f;
const float OUTLINE_THINCENSS = 6.0f;
const float DEFOLD_OUTLINE_THINCENSS = 4.0f;

const std::string CIRCLE_TYPE = "CIRCLE:";
const std::string RECTANGLE_TYPE = "RECTANGLE:";
const std::string TRIANGLE_TYPE = "TRIANGLE:";
const std::string GROUP_TYPE = "GROUP:";

const std::string INPUT_FILE = "input.txt";
const std::string WINDOW_TITLE = "Shapes Visualization";
const std::string ERROR_OPENING_FILE = "Не удалось открыть ";
const std::string OUTPUT_FILE = "output.txt";
const std::string OUTPUT_FILE_ERROR = "Ошибка открытия output.txt";
const std::string RESULTS_WRITTEN = "Результаты записаны в output.txt";
const std::string PERIMETER_LABEL = "P=";
const std::string AREA_LABEL = "; S=";
const std::string NEWLINE = "\n";
const char C_PREFIX = 'C';
const char RADIUS_PREFIX = 'R';
const char EQUAL_SIGN = '=';
const char COMMA_CHAR = ',';
const char LOCALE_RU[3] = "ru";
const char SPACE_CHAR = ' ';


constexpr float PANEL_X = 0.f;
constexpr float PANEL_Y = 0.f;
constexpr float PANEL_WIDTH = 1450.f;
constexpr float PANEL_HEIGHT = 60.f;

constexpr float BTN_WIDTH = 100.f;
constexpr float BTN_HEIGHT = 34.f;
constexpr float BTN_MARGIN = 8.f;
constexpr float BTN_START_X = 10.f;
constexpr float BTN_START_Y = 10.f;

constexpr int DEFAULT_RECT_X = 950;
constexpr int DEFAULT_RECT_Y = 500;

constexpr int DEFAULT_TRIANGLE_P1X = 900;
constexpr int DEFAULT_TRIANGLE_P1Y = 450;
constexpr int DEFAULT_TRIANGLE_P2X = 950;
constexpr int DEFAULT_TRIANGLE_P2Y = 500;
constexpr int DEFAULT_TRIANGLE_P3X = 825;
constexpr int DEFAULT_TRIANGLE_P3Y = 550;

constexpr int DEFAULT_CIRCLE_X = 950;
constexpr int DEFAULT_CIRCLE_Y = 500;
constexpr int DEFAULT_CIRCLE_RADIUS = 25;

constexpr float THICKNESS_1 = 1.f;
constexpr float THICKNESS_3 = 3.f;
constexpr float THICKNESS_5 = 5.f;

constexpr const char* SELECT_ = "Select";
constexpr const char* FILL_ = "Fill";

constexpr float   DEL_ONE = 2.0f;
constexpr float   OUTLINE_THICKNESS = 1.0f;

constexpr int   TEXT_CHARACTER_SIZE = 14;
constexpr float   TEXT_LEFT_PADDING = 8.0f;
constexpr uint8_t BUTTON_FILL_R = 200;
constexpr uint8_t BUTTON_FILL_G = 200;
constexpr uint8_t BUTTON_FILL_B = 200;
constexpr const char* FONT_PATH = "Arial.ttf";