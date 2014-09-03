#ifndef _PHONEMES_
#define _PHONEMES_

#define PHONEME(symbol) _p_##symbol##_

// Phonemes drawn from: http://www.boardman.k12.oh.us/bdms/phonological/44Phonemes.pdf
enum Phoneme {
    // consonant sounds
    PHONEME(b),
    PHONEME(d),
    PHONEME(f),
    PHONEME(g),
    PHONEME(h),
    PHONEME(j),
    PHONEME(k),
    PHONEME(l),
    PHONEME(m),
    PHONEME(n),
    PHONEME(p),
    PHONEME(r),
    PHONEME(s),
    PHONEME(t),
    PHONEME(v),
    PHONEME(w),
    PHONEME(y),
    PHONEME(z),
    
    // consonant digraphs
    PHONEME(_th_),  // not voiced
    PHONEME(th),    // voiced
    PHONEME(ng),
    PHONEME(sh),
    PHONEME(ch),
    PHONEME(zh),
    PHONEME(wh),    // with breath
    
    // short vowel sounds
    PHONEME(a),
    PHONEME(e),
    PHONEME(i),
    PHONEME(o),
    PHONEME(u),
    
    // long vowel sounds
    PHONEME(A),
    PHONEME(E),
    PHONEME(I),
    PHONEME(O),
    PHONEME(U),
    
    // other vowel sounds
    PHONEME(oo),
    PHONEME(OO),
    
    // Vowel diphthongs
    PHONEME(ow),
    PHONEME(oy),
    
    // vowel sounds influenced by r
    PHONEME(ar),
    PHONEME(Ar),
    PHONEME(ir),
    PHONEME(or),
    PHONEME(ur),
};

struct PhonemePair {
    const Phoneme phoneme;
    const Sifteo::AssetAudio *sound;
};

#endif
	