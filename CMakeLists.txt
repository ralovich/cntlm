
PROJECT(cntlm C CXX)

cmake_minimum_required(VERSION 2.8.3)

IF(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 OLD)   # set linking behavior
ENDIF(COMMAND cmake_policy)

ADD_DEFINITIONS(-D_CRT_NONSTDC_NO_WARNINGS)
ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
ADD_DEFINITIONS(-DNEED_SNPRINTF_ONLY)
ADD_DEFINITIONS(-D_CRT_RAND_S)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/pthread-2-9-1/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/winfix)

ADD_EXECUTABLE(cntlm
  acl.c
  acl.h
  auth.c
  auth.h
  config.c
  config.h
  direct.c
  direct.h
  forward.c
  forward.h
  globals.h
  http.c
  http.h
  main.c
  ntlm.c
  ntlm.h
  pages.c
  pages.h
  scanner.c
  scanner.h
  socket.c
  socket.h
  swap.h
  utils.c
  utils.h
  xcrypt.c
  xcrypt.h
  config/config.h
  winfix/fnmatch.c
  winfix/fnmatch.h
  winfix/getopt.h
  winfix/getopt_long.c
  winfix/snprintf.c
  winfix/snprintf.h
  winfix/stdbool.h
  winfix/strings.h
  winfix/syslog.h
  winfix/wsyslog.c
  )

TARGET_LINK_LIBRARIES(cntlm
  Ws2_32.lib
  ${PROJECT_SOURCE_DIR}/pthread-2-9-1/lib/x86/pthreadVC2.lib
)