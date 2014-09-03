#ifndef _GRAPHEMES_
#define _GRAPHEMES_

#define GRAPHEME(symbol) _g_##symbol##_

enum Grapheme {
    GRAPHEME(c),
    GRAPHEME(d),
    GRAPHEME(g),
	GRAPHEME(j),
	GRAPHEME(n),
	GRAPHEME(r),
	GRAPHEME(s)
};

struct GraphemePair {
    const Grapheme grapheme;
    const Sifteo::AssetImage *image;
};

#endif
	