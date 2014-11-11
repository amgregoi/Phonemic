
#include <sifteo.h>
#include "assets.gen.h"
#include "pairings.h"

#define PAIR_DEF(p, g) {&Phoneme_##p, {&Grapheme_##g[0], &Grapheme_##g[1]}}
#define CHUNK_DEF(s, i) {&ChunkSound_##s, {&ChunkImage_##i[0], &ChunkImage_##i[1]}}
PhonemeGraphemePair pairs[] = {

    // consonant sounds
    //==================
	PAIR_DEF(a, a),
	PAIR_DEF(o, a),
	PAIR_DEF(e, e),
	
    PAIR_DEF(b, b),
    //PAIR_DEF(b, bb),
    
    PAIR_DEF(d, d),
    //PAIR_DEF(d, dd),
    //PAIR_DEF(d, ed),
    
    PAIR_DEF(f, f),
    //PAIR_DEF(f, ph),
    
    PAIR_DEF(g,g),
    //PAIR_DEF(g,gg),
    
    PAIR_DEF(h,h),
    
    PAIR_DEF(j,j),
    //PAIR_DEF(j,g),
    //PAIR_DEF(j,ge),
    //PAIR_DEF(j,dge),
    
    PAIR_DEF(k,c),
    PAIR_DEF(k,k),
    //PAIR_DEF(k,ck),
    //PAIR_DEF(k,ch),
    //PAIR_DEF(k,cc),
    //PAIR_DEF(k,que),
    PAIR_DEF(k,K), // needed for proper name Ken
        
    PAIR_DEF(l,l),
    //PAIR_DEF(l,ll),
    
    PAIR_DEF(m,m),
    //PAIR_DEF(m,mm),
    //PAIR_DEF(m,mb),
    
    PAIR_DEF(n,n),
    //PAIR_DEF(n,nn),
    //PAIR_DEF(n,kn)
    //PAIR_DEF(n,gn),
    
    PAIR_DEF(p,p),
    //PAIR_DEF(p,pp),
    
    PAIR_DEF(r,r),
    //PAIR_DEF(r,rr),
    //PAIR_DEF(r,wr),
    
    PAIR_DEF(s,s),
    //PAIR_DEF(s,se),
    //PAIR_DEF(s,ss),
    //PAIR_DEF(s,c),
    //PAIR_DEF(s,ce),
    //PAIR_DEF(s,sc),
    PAIR_DEF(s,S), // needed for proper name Sam
    
    PAIR_DEF(t,t),
    //PAIR_DEF(t,tt),
    //PAIR_DEF(t,ed),
    
    PAIR_DEF(v,v),
    //PAIR_DEF(v,ve),
    
    PAIR_DEF(w,w),
    
    PAIR_DEF(y,y),
    PAIR_DEF(y,i),
    
    PAIR_DEF(z,z),
    //PAIR_DEF(z,zz),
    //PAIR_DEF(z,ze),
    //PAIR_DEF(z,s),
    //PAIR_DEF(z,se),
    //PAIR_DEF(z,x),
    
    // consonant digraphs
    //======================
    //PAIR_DEF(th_not_voiced, th),
    
    PAIR_DEF(th_voiced, th),
    
    //PAIR_DEF(ng, n),
    
    PAIR_DEF(sh, sh),
    //PAIR_DEF(sh, ss),
    //PAIR_DEF(sh, ch),
    //PAIR_DEF(sh, ti),
    //PAIR_DEF(sh, ci),
    
    PAIR_DEF(ch, ch),
    //PAIR_DEF(ch, tch),
    
    //PAIR_DEF(zh, ge),
    //PAIR_DEF(zh, s),
    
    PAIR_DEF(wh, wh),
    
    PAIR_DEF(kw, qu),
    
    // short vowel sounds
    //=====================
    //TODO: SHORT VOWELS
    
    
    // short vowel sounds
    //=====================
    //TODO: LONG VOWELS
    
    
    // other vowel sounds
    //=====================
    //TODO: OTHER VOWELS
    
    
    // vowel dipthong sounds
    //=====================
    //TODO: VOWEL DIPTHONGS
    
    
    // vowels influenced by r sounds
    //=====================
    //TODO: VOWELS INFLUENCED BY R
    
    // chunks (compound phonemes for word families)
    //=====================
    CHUNK_DEF(ab, ab),
    CHUNK_DEF(ad, ad),
    CHUNK_DEF(ag, ag),
    CHUNK_DEF(am, am),
    CHUNK_DEF(an, an),
    CHUNK_DEF(ap, ap),
    CHUNK_DEF(at, at),
    CHUNK_DEF(ed, ed),
    CHUNK_DEF(ell, ell),
    CHUNK_DEF(en, en),
    CHUNK_DEF(et, et),
    CHUNK_DEF(ig, ig),
    CHUNK_DEF(id, id),
    CHUNK_DEF(in, in),
    CHUNK_DEF(ill, ill),
    CHUNK_DEF(ip, ip),
    CHUNK_DEF(it, it),
    CHUNK_DEF(ob, ob),
    CHUNK_DEF(og, og),
    CHUNK_DEF(op, op),
    CHUNK_DEF(ot, ot),
    CHUNK_DEF(ub, ub),
    CHUNK_DEF(ug, ug),
    CHUNK_DEF(um, um),
    CHUNK_DEF(un, un),
    
};