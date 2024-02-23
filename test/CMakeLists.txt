add_executable(test
  tridiag_mat_alg.cpp
  test.cpp
  test.h
)

target_link_libraries(test
${CMAKE_PROJECT_NAME}
)