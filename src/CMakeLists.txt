# === lib code directories ===
add_subdirectory(lib/core)
add_subdirectory(lib/utils)

# === main app ===
add_executable(main)
target_sources(main
  PRIVATE
    main.cc)
target_link_libraries(main PRIVATE kk)
