# set
set(TMP_SOURCE)
set(TMP_OBJECT)
set(TMP_BINARY)
set(TMP_DIRECTORY nndeploy)
set(TMP_DEPEND_LIBRARY)
set(TMP_SYSTEM_LIBRARY)
set(TMP_THIRD_PARTY_LIBRARY)

include_directories(${ROOT_PATH})

# TMP_SOURCE
file(GLOB TMP_SOURCE
  "${ROOT_PATH}/nndeploy/source/task/detect/*.h"
  "${ROOT_PATH}/nndeploy/source/task/detect/*.cc"
  )
if(NNDEPLOY_ENABLE_OPENCV)
  file(GLOB TMP_OPENCV_SOURCE
    "${ROOT_PATH}/nndeploy/source/task/detect/opencv/*.h"
    "${ROOT_PATH}/nndeploy/source/task/detect/opencv/*.cc"
  )
  list(APPEND TMP_SOURCE ${TMP_OPENCV_SOURCE})
endif()
list(APPEND SOURCE ${TMP_SOURCE})

# TMP_OBJECT

# TARGET
# add_library(${TMP_BINARY} ${NNDEPLOY_LIB_TYPE} ${TMP_SOURCE} ${TMP_OBJECT})

# TMP_DIRECTORY
# set_property(TARGET ${TMP_BINARY} PROPERTY FOLDER ${TMP_DIRECTORY})

# TMP_DEPEND_LIBRARY
list(APPEND DEPEND_LIBRARY ${TMP_DEPEND_LIBRARY}) 

# TMP_SYSTEM_LIBRARY
list(APPEND SYSTEM_LIBRARY ${TMP_SYSTEM_LIBRARY}) 

# TMP_THIRD_PARTY_LIBRARY
list(APPEND THIRD_PARTY_LIBRARY ${TMP_THIRD_PARTY_LIBRARY}) 

# install

# unset
unset(TMP_SOURCE)
unset(TMP_OBJECT)
unset(TMP_BINARY)
unset(TMP_DIRECTORY)
unset(TMP_DEPEND_LIBRARY)
unset(TMP_SYSTEM_LIBRARY)
unset(TMP_THIRD_PARTY_LIBRARY)
