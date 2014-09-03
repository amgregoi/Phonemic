/*
 * Phonemic 
 */
 
#include <sifteo.h>
#include <sifteo/audio.h>
#include "phonemic.h"
 
#define LAST_LEVEL 24
 
Random gRandom;
 
/**
  * Constructs a new Phonemic app
  */  
Phonemic::Phonemic()
{

}


/**
  * Display title screen
  */
void Phonemic::title()
{

}


/**
  * Initializes the Phonemic app
  */
void Phonemic::init()
{
	Events::neighborAdd.set(&Phonemic::onNeighborAdd, this);
	Events::neighborRemove.set(&Phonemic::onNeighborRemove, this);
	Events::cubeTouch.set(&Phonemic::onTouch, this);
	Events::cubeConnect.set(&Phonemic::onConnect, this);
	
	// Handle already-connected cubes
	int i = 0;
	for (CubeID cube : CubeSet::connected())
	{
		onConnect(cube);
		cubes[cube].cid = cube;
		i++;
	}
		
	level = gRandom.randint(0, LAST_LEVEL-1);
	word = -1;
	nextWord();
}


/**
  * Moves to the next word
  */
void Phonemic::nextWord()
{
    // Advance the word (and level)
	word++;
	if(word >= 8) {
		level++;
		word = 0;
	}
    if(level > LAST_LEVEL) {
        level = 0;
        word = 0;
    }
    
    // Test for game over
    // TODO: check for end-of-game
    int length = 0;
    while(length < MAX_WORD_SIZE && wordFamilies[level].words[word][length] != -1)
        length++;
        
	int i = 0;
	for(CubeID cube: CubeSet::connected())
	{
        // Reverse the order of the cubes every other word
        int j = i;
        if(word % 2 == 0) j = length - i - 1;
		if(i < length) {
			cubes[cube].symbol = wordFamilies[level].words[word][j];
            cubes[cube].images[0] = pairs[wordFamilies[level].words[word][j]].grapheme[0]; 
            cubes[cube].images[1] = pairs[wordFamilies[level].words[word][j]].grapheme[1]; 
			cubes[cube].vid.bg0.image(vec(0,0), *cubes[cube].images[0]);
			cubes[cube].sound = pairs[wordFamilies[level].words[word][j]].phoneme; 
		} else {
			cubes[cube].symbol = -1;
            cubes[cube].images[0] = &Sleep;
            cubes[cube].images[1] = &Smile;
            cubes[cube].vid.bg0.image(vec(0,0), *cubes[cube].images[0]);
            cubes[cube].sound = &SfxBuzzer;
		}	
		i++;
	}
	state = PLAY;
}

/**
  * Helper method to set all cubes to smiley faces
  */
void Phonemic::allSmiles() {
    for(CubeID cube: CubeSet::connected())
	{
        cubes[cube].vid.bg0.image(vec(0,0), Smile);
    }
}


/**
  * Helper method to determine if any cubes are neighboured
  */
bool Phonemic::noNeighbors() {
    for(CubeID cube: CubeSet::connected())
	{
        Neighborhood hood = Neighborhood(cube);
        if(hood.hasCubeAt(LEFT) || hood.hasCubeAt(RIGHT))
            return false;
    }
    return true;
}


/**
  * Helper method to sounds out the sequence of cubes.
  */
void Phonemic::soundOut(unsigned id) {
    // Wait for audio channel to be clear
    if(sounding.isPlaying()) return;
    
    // Highlight the current cube
    cubes[id].vid.bg0.image(vec(0,0), *cubes[id].images[1]);
    System::paint();
    System::finish();
        
    // Play the current cube's sound
    sounding.play(*cubes[id].sound);
    while(sounding.isPlaying()) {
        System::yield();
    }
    
    // Return the cube to its normal appearance
    cubes[id].vid.bg0.image(vec(0,0), *cubes[id].images[0]);
    
    // Play any cube connected to the right
    Neighborhood hood = Neighborhood(id);
    if(hood.hasCubeAt(RIGHT)) soundOut(hood.cubeAt(RIGHT));
}


/**
  * Helper method to locate the leftmost cube 
  * in a series of neighboured cubes.
  */
unsigned Phonemic::leftmostNeighbor(unsigned id) {
    // Find leftmost cube
	Neighborhood hood = Neighborhood(id);
	CubeID leftmostID = id;
	while(hood.hasCubeAt(LEFT)) {
		leftmostID = hood.cubeAt(LEFT);
		hood = Neighborhood(leftmostID);
	}
    return leftmostID;
}


/** 
  * Helper method to decide if a series of cubes
  * spells the current word.
  */
void Phonemic::checkForWord(unsigned id) {

    // Find leftmost cube
	CubeID nextID = leftmostNeighbor(id);
    Neighborhood hood = Neighborhood(nextID);
    	
	// Find the sequence of symbols spelled by
    // the sequence of cubes
    int wordAttempt[MAX_WORD_SIZE];
    wordAttempt[0] = cubes[nextID].symbol;
    int i = 1;
    while(hood.hasCubeAt(RIGHT)) {
    	nextID = hood.cubeAt(RIGHT);
	    hood = Neighborhood(nextID);
    	wordAttempt[i] = cubes[nextID].symbol;
        i++;
	}
    wordAttempt[i] = -1;
        
    // Check for a match
	bool match = true;
    for(int i = 0; i < MAX_WORD_SIZE; i++) {
        if(wordFamilies[level].words[word][i] != wordAttempt[i]) 
        {
            match = false;
            break;
        }
        if(wordFamilies[level].words[word][i] == -1) break;
    }
    
    // Recognize match
	if(match) {
    	sounding.play(SfxChime); 
        allSmiles();
        System::paint();
        state = WORD_FOUND;
	}
}


/**
  * Runs the Phonemic app
  */
void Phonemic::run()
{
	while(1) {
		System::paint();
	}
}


/**
  * Cleans up before shutdown
  */
void Phonemic::cleanup() 
{
	Events::neighborAdd.unset();
	Events::neighborRemove.unset();
	Events::cubeTouch.unset();
	Events::cubeConnect.unset();
}


/**
  * Event Handler for new cube connections
  */
void Phonemic::onConnect(unsigned id)
{
    // Initialize the cubes in BG0 
    // (one background layer) mode
	cubes[id].cid = id;
    cubes[id].vid.initMode(BG0_BG1);
    cubes[id].vid.attach(id);
    cubes[id].symbol = -1;
    cubes[id].images[0] = &Sleep;
    cubes[id].images[1] = &Sleep;
    cubes[id].vid.bg0.image(vec(0,0), Sleep);
    cubes[id].sound = &SfxBuzzer;
    cubeCount++;
}


/**
  * Event handler for cube touches
  */  
void Phonemic::onTouch(unsigned id) 
{
    // Touch events fire twice - when the
    // touch starts and when it ends.
    // We'll use the isTouching() test to
    // only trigger when the touch ends.
    if(!CubeID(id).isTouching())
        soundOut(id);
}


/**
  * Event handler for cube neighboring
  */
void Phonemic::onNeighborAdd(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
{	
    // Behaviour is dependent on the current app state
    if(state == PLAY)
        // Only allow left-to-right (reading order) connections
        if((firstSide == LEFT && secondSide == RIGHT)||(firstSide == RIGHT && secondSide == LEFT)) 
        {
            playSfx(SfxAttach);
            soundOut(leftmostNeighbor(firstID));
            checkForWord(firstID);
        }
}


/**
  * Event handler for when a cube is moved away from a neighbour
  */
void Phonemic::onNeighborRemove(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
{
    // When all cubes are disconnected, we 
    if(state == WORD_FOUND && noNeighbors())
        nextWord();
    
    if((firstSide == LEFT && secondSide == RIGHT) || 
	   (firstSide == RIGHT && secondSide == LEFT))
		playSfx(SfxDetach);
}