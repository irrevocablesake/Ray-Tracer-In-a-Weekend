#include <cstdlib> 

inline double generateRandom(){
    return std::rand() / ( RAND_MAX + 1.0 );
}

inline double generateRandom( double min, double max ){
    return min + ( max - min ) * generateRandom();
} 