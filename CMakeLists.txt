cmake_minimum_required(VERSION 3.0)
project(ctactless)
find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

add_library(tactless tactless.c tactless.h)
target_include_directories(
  tactless
  PRIVATE
    ${CURL_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIRS}
)
target_link_libraries(
  tactless
  ${CURL_LIBRARIES}
  ${OPENSSL_LIBRARIES}
  ${ZLIB_LIBRARIES}
)

add_executable(main main.c)
target_link_libraries(main tactless)
