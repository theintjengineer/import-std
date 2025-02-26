add_library(utils STATIC)
target_sources(utils
  PRIVATE
    utils-random.cc
    utils.cc
    PUBLIC
      FILE_SET CXX_MODULES
      FILES
        utils.cppm
        utils-random.cppm)
target_compile_features(utils
  PRIVATE   cxx_std_23
  INTERFACE cxx_std_23)
