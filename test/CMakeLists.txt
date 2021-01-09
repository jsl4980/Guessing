cmake_minimum_required(VERSION 3.5)

include(GoogleTest)

project(guessing_tests LANGUAGES CXX)

add_definitions(-DGTEST_LANGUAGE_CXX11)

find_package(Threads REQUIRED)

if ($ENV{GOOGLETEST_DIR})
    set(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    if (NOT "" STREQUAL "")
        message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    endif ()
    set(GOOGLETEST_DIR "")
endif ()
if (EXISTS ${GOOGLETEST_DIR})
    set(GTestSrc ${GOOGLETEST_DIR}/googletest)
    set(GMockSrc ${GOOGLETEST_DIR}/googlemock)
elseif (UNIX AND EXISTS /usr/src/googletest)
    set(GTestSrc /usr/src/googletest/googletest)
    message(WARNING "Using gtest from system")
    if (EXISTS /usr/src/googlemock)
        set(GMockSrc /usr/src/googletest/googlemock)
    endif ()
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()

set(GTestFiles ${GTestSrc}/src/gtest-all.cc ${GTestSrc}/src/gtest_main.cc)
set(GTestIncludes ${GTestSrc} ${GTestSrc}/include ${GMockSrc}/include)
if (NOT ${GMockSrc} STREQUAL "")
    list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
    list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
endif ()

include_directories(${GTestIncludes})

set(PROJECT_SOURCES
    tst_roundtests.cpp
    tst_animals.cpp
    tst_animalgenerator.cpp
    ../round.cpp
    ../animal.cpp
    ../animalgenerator.cpp)

add_executable(guessing_tests ${PROJECT_SOURCES}
               ${GTestFiles})
#add_test(NAME guessing_tests COMMAND guessing_tests)
gtest_add_tests(TARGET guessing_tests
    SOURCES ${PROJECT_SOURCES})
target_link_libraries(guessing_tests PRIVATE Threads::Threads)

