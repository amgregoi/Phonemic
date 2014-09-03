APP = phonemic

include $(SDK_DIR)/Makefile.defs

LIBS = -lstdc++

OBJS = $(ASSETS).gen.o pairings.o word_families.o phonemic.o main.o
ASSETDEPS += assets/*.png $(ASSETS).lua
#CDEPS += *.h
	
# build assets.html to proof stir-processed assets.
# comment out to disable.
ASSETS_BUILD_PROOF := yes

include $(SDK_DIR)/Makefile.rules
