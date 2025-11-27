
#ifndef __CMATH_VEC3_H__
#define __CMATH_VEC3_H__ 1

namespace cmath{
  template<typename T>
  struct Vec3
  {
    Vec3() : x(T(0)), y(T(0)), z(T(0)) {};
    Vec3(T x, T y, T z) : x(x), y(y), z(z) {};
    Vec3(T v) : x(v), y(v), z(v) {};
    
    ~Vec3() = default;

    T& operator[](int i) {return a[i];}
    const T& operator[](int i) {return a[i];}

  //////////////////////
  //     OPERATOR     //
  //////////////////////

  //////////////////////
  //       DATA       //
  //////////////////////
    union {
      struct { T x, y, z; };
      struct { T r, g, b; };
      struct { T a[3]; };
    };

  }; // !Vector3

} // !namespace cmath

#endif // !#define __CMATH_VEC3_H__ 1
