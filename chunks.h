#ifndef _CHUNKS_
#define _CHUNKS_

#define CHUNK(symbol) _c_##symbol##_

enum Chunk {
    CHUNK(ab) = 100,
};

struct ChunkSet {
    //const Grapheme *graphemes;
	//const Phoneme *phonemes;
	const char *symbol;
	const Chunk chunk;
    const Sifteo::AssetImage *image;
	const Sifteo::AssetAudio *sound;
};

#endif
	