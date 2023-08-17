project(eviction_test)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")

add_executable(evict evict.cpp)

if(STATIC_UMAP_LINK)
    set(umap-lib "umap-static")
else()
    set(umap-lib "umap")
endif()

add_dependencies(evict ${umap-lib})

target_link_libraries(evict ${umap-lib})
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ${UMAPINCLUDEDIRS} )
