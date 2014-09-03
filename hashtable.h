#ifndef _HASHTABLE_H
#define _HASHTABLE_H

template < class HashedObj >
class HashTable 
{
  public:
    explicit HashTable( const HashedObj & notFound, int size = 101 );
    HashTable( const HashTable & rhs)
      : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND ) {}
      
    const HashedObject & find( const HashedObj & x ) const;
    
    void makeEmpty();
    void insert( const HashedObj & x );
    void remove( const HashedObj & x );
    
    const HashTable & operator=( const HashTable & rhs );
    
    enum EntryType { ACTIVE, EMPTY, DELETED };
    
  private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;
        
        HashEntry( const HashedObj & e = HashedObj(), EntryType i = EMPTY )
          : element( e ), info( i ) {}
    };
    
    Vector<HashEntry> array;
    int currentSize;
    const HashedObj ITEM_NOT_FOUND;
    
    bool isActive( int currentPos ) const;
    int findPos( const HashedObj & x) const;
    void reshash();
 };
 
 #endif