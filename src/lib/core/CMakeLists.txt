add_library(kk STATIC)
target_sources(kk
  PRIVATE
    kk.cc
    PUBLIC
      FILE_SET CXX_MODULES
      FILES kk.cppm)
target_compile_features(kk
  PRIVATE   cxx_std_23
  INTERFACE cxx_std_23)

target_link_libraries(kk PRIVATE utils)
