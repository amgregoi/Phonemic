#include "hashtable.h"

/** 
  * Construct hash table
  */
template <class HashedObj>
HashTable<HashedObj>::HashTable( const HashedObj & notFound, int size )
  : ITEM_NOT_FOUND( notFound), array( nextPrime( size ) )
{
    makeEmpty();
}

/** 
  * Make the hashtable logically empty
  */
template <class HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
    currentSize = 0;
    for( int i = 0; i < array.size(); i++ )
        array[ i ].info = EMPTY;
}

/** 
  * Find item x in the hashtable.
  * Return matching item or ITEM_NOT_FOUND if not found.
  */
template <class HashedObj>
const HashedObj & HashTable<HashedObj>::find( const HashedObj & x ) const
{
    int currentPos = findPos( x );
    return isActive( currentPos ) ? array[ currentPos ].element : ITEM_NOT_FOUND;
}

/**
  * Method that performs quadratic probing resolution.
  * Return the position where the search for x terminates.
  */
template <class HashedObj>
int HashTable<HashedObj>::findPos( const HashedObj & x ) const
{
    int collisionNum = 0;
    int currentPos = hash( x, array.size() );
    
    while( array[ currentPos ].info != EMPTY &&
           array[ currentPos ].element != x )
    {
        currentPos += 2 * ++collisionNum - 1;
        if( currentPos >= array.size( ) )
            currentPos -= array.size( );
    }
    
    return currentPos;
}

/**
  * Return true if currentPos exists and is active.
  */
template <class HashedObj>
bool HashTable<HashedObj>::isActive( int currentPos ) const
{
    return array[ currentPos ].info == ACTIVE;
}

/**
  * Insert item x into the hash table.  If the item is
  * already present, then do nothing.
  */
template <class HashedObj>
void HashTable<HashedObj>::insert( const HashedObj & x )
{
    // Insert x as active
    int currentPos = findPos( x );
    if( isActive( currentPos ))
        return;
    array[ currentPos ] = HashEntry( x, ACTIVE );
    
    if( ++currentSize > array.size() / 2 )
        rehash();
}

/**
  * Remove item x from the hash table.
  */
template<class HashedObj>
void HashTable<HashedObj>::remove( const HashedObj & x )
{
    int currentPos = findPos( x );
    if( isActive( currentPos ) )
        array[ currentPos ].info = DELETED;
}

/** 
  * Expand the hash table.
  */
template <class HashedObj>
void HashTable<HashedObj>::rehash()
{
    vector<HashEntry> oldArray = array;
    
    // create new double-sized empty table
    array.resize( nextPrime( 2 * oldArray.size() ) );
    for( int j = 0; j < array.size( ); j++)
        array[j].info = EMPTY;
        
    // copy table over
    currentSize = 0;
    for( int i = 0; i < oldArray.size( ); i++ )
        if( oldArray[i].info == ACTIVE )
            insert( oldArray[i].element );
}