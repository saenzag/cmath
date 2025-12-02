
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

  // Types
  typedef Vec2<int> Vec2i;
  typedef Vec2<unsigned int> Vec2u;
  typedef Vec2<float> Vec2f;
  typedef Vec2<double> Vec2d;

} // !namespace cmath

#endif // !#define __CMATH_VEC2_H__ 1