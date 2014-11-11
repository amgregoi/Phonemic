#ifndef _PHONEMES_
#define _PHONEMES_

#define PAIR(phoneme, grapheme) _pair_##phoneme##_##grapheme##_

// Phonemes drawn from: http://www.boardman.k12.oh.us/bdms/phonological/44Phonemes.pdf
enum pairings{

    // consonant sounds
    //==================
    PAIR(b, b),
    //PAIR(b, bb),
    
    PAIR(d, d),
    //PAIR(d, dd),
    //PAIR(d, ed),
    
    PAIR(f, f),
    //PAIR(f, ph),
    
    PAIR(g,g),
    //PAIR(g,gg),
    
    PAIR(h,h),
    
    PAIR(j,j),
    //PAIR(j,g),
    //PAIR(j,ge),
    //PAIR(j,dge),
    
    PAIR(k,c),
    PAIR(k,k),
    //PAIR(k,ck),
    //PAIR(k,ch),
    //PAIR(k,cc),
    //PAIR(k,que),
    PAIR(k,K), // needed for proper name Ken
        
    PAIR(l,l),
    //PAIR(l,ll),
    
    PAIR(m,m),
    //PAIR(m,mm),
    //PAIR(m,mb),
    
    PAIR(n,n),
    //PAIR(n,nn),
    //PAIR(n,kn)
    //PAIR(n,gn),
    
    PAIR(p,p),
    //PAIR(p,pp),
    
    PAIR(r,r),
    //PAIR(r,rr),
    //PAIR(r,wr),
    
    PAIR(s,s),
    //PAIR(s,se),
    //PAIR(s,ss),
    //PAIR(s,c),
    //PAIR(s,ce),
    //PAIR(s,sc),
    PAIR(s,S), // needed for proper name Sam
    
    PAIR(t,t),
    //PAIR(t,tt),
    //PAIR(t,ed),
    
    PAIR(v,v),
    //PAIR(v,ve),
    
    PAIR(w,w),
    
    PAIR(y,y),
    PAIR(y,i),
    
    PAIR(z,z),
    //PAIR(z,zz),
    //PAIR(z,ze),
    //PAIR(z,s),
    //PAIR(z,se),
    //PAIR(z,x),
    
    // consonant digraphs
    //======================
    //PAIR(th_not_voiced, th),
    
    PAIR(th_voiced, th),
    
    //PAIR(ng, n),
    
    PAIR(sh, sh),
    //PAIR(sh, ss),
    //PAIR(sh, ch),
    //PAIR(sh, ti),
    //PAIR(sh, ci),
    
    PAIR(ch, ch),
    //PAIR(ch, tch),
    
    //PAIR(zh, ge),
    //PAIR(zh, s),
    
    PAIR(wh, wh),
    
    PAIR(kw, qu),
    
    
    // short vowel sounds
    //=====================
    //TODO: SHORT VOWELS
	
	PAIR(a, a),
	PAIR(o, a),
	PAIR(e, e),
    
    
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
    PAIR(ab, ab),
    PAIR(ad, ad),
    PAIR(ag, ag),
    PAIR(am, am),
    PAIR(an, an),
    PAIR(ap, ap),
    PAIR(at, at),
    PAIR(ed, ed),
    PAIR(ell, ell),
    PAIR(en, en),
    PAIR(et, et),
    PAIR(ig, ig),
    PAIR(id, id),
    PAIR(in, in),
    PAIR(ill, ill),
    PAIR(ip, ip),
    PAIR(it, it),
    PAIR(ob, ob),
    PAIR(og, og),
    PAIR(op, op),
    PAIR(ot, ot),
    PAIR(ub, ub),
    PAIR(ug, ug),
    PAIR(um, um),
    PAIR(un, un),
    
};

struct PhonemeGraphemePair {
    const Sifteo::AssetAudio *phoneme;
    const Sifteo::AssetImage *grapheme[2];
};

#endif
	