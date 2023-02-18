project(ntTests)

add_executable(ntTests
        main.cpp
        )

target_link_libraries(ntTests
        nntLib
        gtest
        )
