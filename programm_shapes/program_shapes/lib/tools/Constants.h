#pragma once
#include <string>


const double PI = 3.1415;
const double FIRST = 1.0;
const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;
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
