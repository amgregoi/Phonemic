/*
 * Phonemic
 */
 
#ifndef _PHONEMIC_H
#define _PHONEMIC_H
 
#include <sifteo.h>
#include "assets.gen.h"
#include "pairings.h"
#include "word_families.h"
#include "word_pictures.h"
#include "word_sounds.h"
 
using namespace Sifteo;
 
extern AssetSlot MainSlot;
extern PhonemeGraphemePair pairs[];
extern WordFamily wordFamilies[];

enum PhonemicState {
	TITLE,
	PLAY,
	WORD_FOUND
};

static void playSfx(const AssetAudio& sfx) {
    static int i=0;
    AudioChannel(i).play(sfx);
    i = 1 - i;
}

struct PhonemicCube {
	CubeID cid;
	VideoBuffer vid;
	short symbol;
    const AssetImage *images[2];
	const AssetAudio *sound;
};


class Phonemic {
public:
	Phonemic();
	
	void title();
	void init();
	void run();
	void cleanup();
	
	static Random random;
	unsigned int wordFamilyId = 0;

private:
	PhonemicCube cubes[CUBE_ALLOCATION];
	PhonemicState state;
	unsigned int level;
	unsigned int word;
    unsigned int cubeCount;
    BG1Mask border = 
        BG1Mask::filled(vec(0,0), vec(16,2)) |
        BG1Mask::filled(vec(0,2), vec(2,12)) |
        BG1Mask::filled(vec(0,14), vec(16,2)) |
        BG1Mask::filled(vec(14,2), vec(2,12));
    AudioChannel::AudioChannel sounding = AudioChannel::AudioChannel(2);
    
	void nextWord();
    void checkForWord(unsigned id);
    void soundOut(unsigned id);
    void allSmiles();
    bool noNeighbors();
    unsigned leftmostNeighbor(unsigned id);
    
	void onConnect(unsigned id);
	void onTouch(unsigned id);
	void onNeighborAdd(unsigned firstId, unsigned firstSide, unsigned secondID, unsigned secondSide);
	void onNeighborRemove(unsigned firstId, unsigned firstSide, unsigned secondID, unsigned secondSide);
};

#endif