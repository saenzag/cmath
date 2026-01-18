
#ifndef __CMATH_VEC3_H__
#define __CMATH_VEC3_H__ 1

#include <math.h>

namespace cmath{
  template<typename T>
  struct Vec3
  {
    Vec3() : x(T(0)), y(T(0)), z(T(0)) {};
    Vec3(T x, T y, T z) : x(x), y(y), z(z) {};
    Vec3(T v) : x(v), y(v), z(v) {};
    
    ~Vec3() = default;

    T& operator[](int i) {return a[i];}
    const T& operator[](int i) const { return a[i]; }

  //////////////////////
  //     OPERATOR     //
  //////////////////////

    Vec3<T> operator+(const Vec3<T>& other) const
    {
      return Vec3<T>(x + other.x,  y + other.y, z + other.z);
    }

    Vec3<T> operator+=(const Vec3<T>& other)
    {
      x += other.x; y += other.y; z += other.z;
      return *this;
    }

    Vec3<T> operator+(const T& other) const
    {
      return Vec3<T>(x + other,  y + other, z + other);
    }

    Vec3<T> operator+(T&& other) const
    {
      return Vec3<T>(x + other,  y + other, z + other);
    }

    Vec3<T> operator+=(T&& other)
    {
      x += other; y += other; z += other;
      return *this;
    }

    Vec3<T> operator+=(const T& other)
    {
      x += other; y += other; z += other;
      return *this;
    }

    Vec3<T> operator-(const Vec3<T>& other) const
    {
      return Vec3<T>(x - other.x,  y - other.y, z - other.z);
    }

    Vec3<T> operator-=(const Vec3<T>& other)
    {
      x -= other.x; y -= other.y; z -= other.z;
      return *this;
    }

    Vec3<T> operator-(T&& other) const
    {
      return Vec3<T>(x - other,  y - other, z - other);
    }

    Vec3<T> operator-=(const T& other)
    {
      x -= other; y -= other; z -= other;
      return *this;
    }

    Vec3<T> operator*(const T scalar) const
    {
      return Vec3<T>(x * scalar,  y * scalar, z * scalar);
    }

    Vec3<T> operator*=(const T scalar)
    {
      x *= scalar; y *= scalar; z *= scalar;
      return *this;
    }

    Vec3<T> operator/(const T scalar) const
    {
      T inv = T(1) / scalar;
      return *this * inv;
    }

    Vec3<T> operator/=(const T scalar)
    {
      *this *= T(1) / scalar;
      return *this;
    }

    // DOT PRODUCT
    T operator*(const Vec3<T>& other) const
    {
      return Dot(*this, other);
    }

    // CROSS PRODUCT
    Vec3<T> operator^(const Vec3<T>& other) const
    {
      return Cross(*this, other);
    }

    Vec3<T> operator-() const
    {
      return Vec3<T>(-x, -y, -z);
    }

    Vec3<T> Normalized() const
    {
      const T len = Length(*this);
      if (len > T(0))
      {
        return *this / len;
      }
      return *this;
    }

    Vec3<T>& Normalize()
    {
      const T len = Length(*this);
      if (len > T(0))
      {
        *this /= len;
      }
      return *this;
    }

  //////////////////////
  //       DATA       //
  //////////////////////
    union {
      struct { T x, y, z; };
      struct { T r, g, b; };
      struct { T a[3]; };
    };

  }; // !Vector3

  //////////////////////
  //     OPERATIONS   //
  //////////////////////

  template<typename T>
  Vec3<T> Cross(const Vec3<T>& a, const Vec3<T>& b)
  {
    return Vec3<T>(
      a.y * b.z - a.z * b.y,
      a.z * b.x - a.x * b.z,
      a.x * b.y - a.y * b.x
    );
  }

  template<typename T>
  T Dot(const Vec3<T>& a, const Vec3<T>& b)
  {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }

  template<typename T>
  T SquaredLength(const Vec3<T>& v)
  {
    return Dot(v, v);
  }

  template<typename T>
  T Length(const Vec3<T>& v)
  {
    return static_cast<T>(sqrt(Dot(v, v)));
  }
  // Specialization for float
  float Length(const Vec3<float>& v)
  {
    return sqrtf(Dot(v, v));
  }

    // Types
  typedef Vec3<int> Vec3i;
  typedef Vec3<unsigned int> Vec3u;
  typedef Vec3<float> Vec3f;
  typedef Vec3<double> Vec3d;

} // !namespace cmath

#endif // !#define __CMATH_VEC3_H__ 1
