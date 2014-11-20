#ifndef _WORD_SOUNDS_
#define _WORD_SOUNDS_

#include <sifteo/string.h>
#include "assets.gen.h"

const int NUMBER_SOUNDS = 16;
 
using namespace Sifteo;

struct WordSound {
    const Sifteo::AssetAudio *sound;
};
 
#endif
