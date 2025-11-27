
#ifndef __CMATH_VEC2_H__
#define __CMATH_VEC2_H__ 1

namespace cmath{
  template<typename T>
  struct Vec2
  {
    Vec2() : x(T(0)), y(T(0)) {};
    Vec2(T x, T y) : x(x), y(y) {};
    Vec2(T v) : x(v), y(v) {};
    
    ~Vec2() = default;

    T& operator[](int i) {return a[i];}
    const T& operator[](int i) {return a[i];}

  //////////////////////
  //     OPERATOR     //
  //////////////////////

  //////////////////////
  //       DATA       //
  //////////////////////
    union {
      struct { T x, y; };
      struct { T u, v; };
      struct { T a[2]; };
    };

  }; // !Vector2

} // !namespace cmath

#endif // !#define __CMATH_VEC2_H__ 1