
/* 
 *   Class for Quaternions algebra
 *
 *   #######################################################
 *   #  _______   __  _____ ______ _______ _ ____   _____  #
 *   #         \ |  |   ___|   ___|__   __| |    \ |       #
 *   #          \|  |  __| |  __|    | |  | |     \|       #
 *   #       |\     | |____| |       | |  | |   |\         #
 *   #  _____| \____| _____|_|       |_|  |_|___| \______  #
 *   #                                                     #
 *   #######################################################
 *
 *   Author: Giammarco Valenti
 *   giammarco.valenti@gmail.com
 * 
 */

// avoid double inclusion
#ifndef QUATERNIONS_HPP
#define QUATERNIONS_HPP

// C++ IO
#include <iostream>
// C++ IO on string
#include <sstream>
// for the exception
#include <exception>
// for the math
#include <cmath>

// to activate g++ -DDEBUG ....
#ifdef DEBUG
  #define DEBUG_MESSAGE(A) std::cout << "DEBUG: " << A << '\n'
#else
  #define DEBUG_MESSAGE(A)
#endif

#ifndef ASSERT
  #define DO_ERROR(MSG) { \
    std::ostringstream ost; \
    ost << MSG << '\n'; \
    throw std::runtime_error(ost.str()); \
  }
  #define ASSERT(COND,MSG) if ( !(COND) ) DO_ERROR(MSG)
#endif

namespace Quaternions {

  // parameterize the integer and floating point types
  typedef int    int_type;
  typedef double real_type;

//   using std::ostream; // use ostream from std namespace
//   using std::cout;    // use cout from std namespace

  class Quaternion {

  public:
    real_type c[4]; // components of the Quaternion Quaternion = el[0] + el[1]*i + el[2]*j + el[3]*k

  public:

    // default constructor
    Quaternion(){
    ///
    /// Quaternion( real_type _a )
    /// Create a zero Quaternion = 0 + 0i + 0j + 0k
    ///
      c[0] = 0;
      c[1] = 0;
      c[2] = 0;
      c[3] = 0;     
      DEBUG_MESSAGE("Quaternion() : default constructor . zero Quaternion");
    }

    // real Quaternion constructor
    Quaternion( real_type _b , real_type _c , real_type _d ){
    ///
    /// Quaternion( real_type _a )
    /// Create a vector Quaternion = 0 + ai + bj + ck
    ///
      c[0] = 0;
      c[1] = _b;
      c[2] = _c;
      c[3] = _d;     
      DEBUG_MESSAGE("Quaternion() : vector Quaternion created");
    }

    // real Quaternion constructor
    Quaternion( real_type _a ){
    ///
    /// Quaternion( real_type _a )
    /// Create a real Quaternion = a + 0i + 0j + 0k
    ///
      c[0] = _a;
      c[1] = 0;
      c[2] = 0;
      c[3] = 0;     
      DEBUG_MESSAGE("Quaternion() : real Quaternion created");
    }

    // Quaternion constructor
    Quaternion( real_type _a , real_type _b , real_type _c , real_type _d ){
    ///
    /// Quaternion( real_type _a )
    /// Create a real Quaternion = a + 0i + 0j + 0k
    ///
      c[0] = _a;
      c[1] = _b;
      c[2] = _c;
      c[3] = _d;     
      DEBUG_MESSAGE("Quaternion() : complete Quaternion created");
    }



  }; // close class

///
/// Operators definition: + ; (q1-q2) ; (-q2) ; * ; / ; 
///

  Quaternion operator+( const Quaternion & q1 , const Quaternion & q2 ){
    ///
    /// define the sum
    ///
      const real_type *c1          = q1.c; // point to the memory
      const real_type *c2          = q2.c;
      real_type cr[4]        = { c1[0]+c2[0] , 
                                 c1[1]+c2[1] ,
                                 c1[2]+c2[2] ,
                                 c1[3]+c2[3]  }; 

      Quaternion result(cr[0],cr[1],cr[2],cr[3]);
      DEBUG_MESSAGE("sum of quaternions");
      return result;
  }

  Quaternion operator-( const Quaternion & q2 ){
    ///
    /// define the negative quaternion
    ///
      const real_type *c2          = q2.c;
      real_type cr[4]        = { -c2[0] , 
                                 -c2[1] ,
                                 -c2[2] ,
                                 -c2[3]  }; 

      Quaternion result(cr[0],cr[1],cr[2],cr[3]);
      DEBUG_MESSAGE("minus quaternion");
      return result;
  }

  Quaternion operator-( const Quaternion & q1 , const Quaternion & q2 ){
    ///
    /// define the substraction
    ///
      const real_type *c1          = q1.c; // point to the memory
      const real_type *c2          = q2.c;
      real_type cr[4]        = { c1[0]-c2[0] , 
                                 c1[1]-c2[1] ,
                                 c1[2]-c2[2] ,
                                 c1[3]-c2[3] , }; 

      Quaternion result(cr[0],cr[1],cr[2],cr[3]);
      DEBUG_MESSAGE("subtraction of quaternions");
      return result;
  }

  Quaternion operator*( const Quaternion & q1 , const Quaternion & q2 ){
    ///
    /// define the multiplication
    ///
      const real_type *c1          = q1.c; // point to the memory
      const real_type *c2          = q2.c;
      real_type cr[4]        =     {  c1[0]*c2[0] -  c1[1]*c2[1] -  c1[2]*c2[2] -  c1[3]*c2[3]  , 
                                      c1[0]*c2[1] +  c1[1]*c2[0] +  c1[2]*c2[3] -  c1[3]*c2[2]  ,  
                                      c1[0]*c2[2] -  c1[1]*c2[3] +  c1[2]*c2[0] +  c1[3]*c2[1]  ,  
                                      c1[0]*c2[3] +  c1[1]*c2[2] -  c1[2]*c2[1] +  c1[3]*c2[0]   };

      Quaternion result(cr[0],cr[1],cr[2],cr[3]);
      DEBUG_MESSAGE("multiplication of quaternions");
      return result;
  }

  Quaternion operator/( const Quaternion & q1 , const Quaternion & q2 ){ 
    ///
    /// define the division
    ///
      const real_type *c1 = q1.c; // point to the memory
      const real_type *c2 = q2.c;

      const real_type mod2 = sqrt(c2[0]*c2[0] + c2[1]*c2[1] + c2[2]*c2[2] + c2[3]*c2[3]); // norm

      real_type cr[4]        =     { ( c1[0]*  c2[0]  -  c1[1]*(-c2[1]) -  c1[2]*(-c2[2]) -  c1[3]*(-c2[3]) ) / mod2 , 
                                     ( c1[0]*(-c2[1]) +  c1[1]*c2[0]    +  c1[2]*(-c2[3]) -  c1[3]*(-c2[2]) ) / mod2 ,  
                                     ( c1[0]*(-c2[2]) -  c1[1]*(-c2[3]) +  c1[2]*c2[0]    +  c1[3]*(-c2[1]) ) / mod2 ,  
                                     ( c1[0]*(-c2[3]) +  c1[1]*(-c2[2]) -  c1[2]*(-c2[1]) +  c1[3]*c2[0]    ) / mod2  };

      Quaternion result(cr[0],cr[1],cr[2],cr[3]);
      DEBUG_MESSAGE("division of quaternions");
      return result;
  }

  Quaternion conj( const Quaternion & q1 ){ 
    ///
    /// define the coniugate
    ///
      Quaternion result(q1.c[0],-q1.c[1],-q1.c[2],-q1.c[3]);
      DEBUG_MESSAGE("conjugate of quaternion");
      return result;
  }

  real_type norm( const Quaternion & q1 ){
    ///
    /// define the norm
    ///
    DEBUG_MESSAGE("norm of quaternion");
    return ( sqrt( q1.c[0]*q1.c[0] + q1.c[1]*q1.c[1] + q1.c[2]*q1.c[2] + q1.c[3]*q1.c[3] ) );
  }

  real_type normSquare( const Quaternion & q1 ){
    ///
    /// define the square of the norm
    ///
    DEBUG_MESSAGE("norm square of quaternion");
    return ( q1.c[0]*q1.c[0] + q1.c[1]*q1.c[1] + q1.c[2]*q1.c[2] + q1.c[3]*q1.c[3] );
  }
  
  real_type normalise( const Quaternion & q1 ){
    ///
    /// define the norm
    ///
    DEBUG_MESSAGE("normalise quaternion");
    real_type norma = sqrt(q1.c[0]*q1.c[0] + q1.c[1]*q1.c[1] + q1.c[2]*q1.c[2] + q1.c[3]*q1.c[3]);

    const real_type *c2          = q2.c;

    real_type cr[4]        = { c2[0]/norma  , 
                               c2[1]/norma  ,
                               c2[2]/norma  ,
                               c2[3]/norma  }; 

    Quaternion result(cr[1],cr[1],cr[2],cr[3]);

    return ( q1.c[0]*q1.c[0] + q1.c[1]*q1.c[1] + q1.c[2]*q1.c[2] + q1.c[3]*q1.c[3] );
  }

} // close namespace




#endif