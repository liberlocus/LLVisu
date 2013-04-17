find_path(liberVisu_INCLUDE_DIRS liberVisuOut.h /gpfs/home/bxk267/work/LL_Research/Libraries/LLVisu/liberVisu "$ENV{NAMER_ROOT}")

find_library(liberVisu_LIBRARIES liberVisu /gpfs/home/bxk267/work/LL_Research/Libraries/LLVisu/liberVisu "$ENV{NAMER_ROOT}")

set(liberVisu_FOUND TRUE)
 
if (NOT liberVisu_INCLUDE_DIRS)
  set(liberVisu_FOUND FALSE)
endif (NOT liberVisu_INCLUDE_DIRS)

if (NOT liberVisu_LIBRARIES)
  set(liberVisu_FOUND FALSE)
endif (NOT liberVisu_LIBRARIES)
