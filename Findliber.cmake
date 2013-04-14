find_path(liber_INCLUDE_DIRS liberOut.h /gpfs/home/bxk267/work/LL_Research/Libraries/LLVisu/liber "$ENV{NAMER_ROOT}")

find_library(liber_LIBRARIES liber /gpfs/home/bxk267/work/LL_Research/Libraries/LLVisu/liber "$ENV{NAMER_ROOT}")

set(liber_FOUND TRUE)
 
if (NOT liber_INCLUDE_DIRS)
  set(liber_FOUND FALSE)
endif (NOT liber_INCLUDE_DIRS)

if (NOT liber_LIBRARIES)
  set(liber_FOUND FALSE)
endif (NOT liber_LIBRARIES)
