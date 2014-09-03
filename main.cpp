/*
 * Phonemic tool
 */
 
 #include "phonemic.h"
 
 // METADATA
 static Metadata M = Metadata()
	.title("Phonemic")
	.package("com.sifteo.phonemic", "0.2.1")
	.icon(Icon)
	.cubeRange(1, CUBE_ALLOCATION);
	
AssetSlot gMainSlot = AssetSlot::allocate()
    .bootstrap(BootstrapAssets);
	
// NEED A MENU:
//  + Word Families
//    - \e\
//    - \f\
//    ... 
//  + Free Play
//  + Exit

// NEED CLASSES?:
//  + Phenome
//    - image
//    - sound
//  + Cube
//    - onTap() -> Play neighborhood sounds in sequence
//    - onShake() -> Switch phoneme
//    - onNeighborAdd() -> check for word
//  + Recognizer?
//    - Evaluate a neighborhood for word status
//    - Provide new (random) phenomes to cubes
 
 
 
 void main()
 {
	static Phonemic phonemic;
	
	//while(1) {
		phonemic.title();
		phonemic.init();
		phonemic.run();
		phonemic.cleanup();
	//}
 }