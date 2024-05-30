cmake_minimum_required(VERSION 3.10)
project(HamburgerBuilder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main hamburger.cpp)

add_subdirectory(external/gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Отключаем обработку предупреждений как ошибок для Google Test
target_compile_options(gtest PRIVATE -Wno-error=maybe-uninitialized)

# Отключаем обработку предупреждений о неинициализированных переменных как ошибок
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=maybe-uninitialized")

# Добавляем исполняемые файлы для тестов
add_executable(tests tests.cpp)
target_link_libraries(tests gtest_main)
add_test(NAME tests COMMAND tests)
