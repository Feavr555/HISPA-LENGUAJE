cmake_minimum_required(VERSION 3.10)

project(Hispa)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED true)

file(GLOB SOURCES "src/*.c")
add_executable(hispa ${SOURCES})

target_include_directories(hispa PUBLIC "${PROJECT_SOURCE_DIR}/inc")
#file(COPY "${PROJECT_SOURCE_DIR}/res" DESTINATION "${CMAKE_BINARY_DIR}")

if(M_WIN32)
	set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
	#set(CMAKE_BUILD_TYPE Debug)
	#target_compile_options(game PRIVATE -Wall -Wextra -Wpedantic -Werror -O3)
	target_include_directories(hispa PUBLIC "${PROJECT_SOURCE_DIR}/inc/win32")
	# Directorio con las dependencias .a
	target_link_directories(hispa PUBLIC "${PROJECT_SOURCE_DIR}/libs/win32")
	file(GLOB LIBS "${PROJECT_SOURCE_DIR}/libs/win32/*.a")
	target_link_libraries(hispa PUBLIC ${LIBS}
						-lole32 -lgdi32 -lwinmm -lsetupapi -limm32
						-loleaut32 -lversion -luuid -lrpcrt4 -lws2_32
						-liphlpapi -lmingw32 -lSDL2main)
	target_link_options(hispa PUBLIC -static-libgcc -static)
	message(STATUS "Compilando para windows")
elseif(UNIX)
	set(CMAKE_C_COMPILER gcc)
	#set(CMAKE_BUILD_TYPE Debug)
	# Directorio con las dependencias .a
	#target_link_directories(game PUBLIC "${PROJECT_SOURCE_DIR}/libs/linux")
	#file(GLOB LIBS "${PROJECT_SOURCE_DIR}/libs/linux/*.a")
	#target_link_libraries(game ${LIBS})
	target_link_libraries(hispa "")
#	target_link_options(hipa PUBLIC -static-libgcc)
	message(STATUS "Compilando para linux")
elseif(WIN32)
	set(CMAKE_C_COMPILER gcc)
	target_include_directories(hispa PUBLIC "${PROJECT_SOURCE_DIR}/inc/win32")
	target_link_directories(hispa PUBLIC "${PROJECT_SOURCE_DIR}/libs/win32")
	file(GLOB LIBS "${PROJECT_SOURCE_DIR}/libs/win32/*.a")
	target_link_libraries(hispa PUBLIC ${LIBS}
						-lole32 -lgdi32 -lwinmm -lsetupapi -limm32
						-loleaut32 -lversion -luuid -lrpcrt4 -lws2_32
						-liphlpapi -lmingw32 -lSDL2main)
	target_link_options(game PUBLIC -static-libgcc -static)
	message(STATUS "Compilando para windows")
else(FATAL_ERROR "No soporta la plataforma")
endif()
