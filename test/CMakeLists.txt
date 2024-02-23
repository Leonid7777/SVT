add_executable(test
  main.cpp
  test.cpp
  test.h
)

target_link_libraries(test
${CMAKE_PROJECT_NAME}
)