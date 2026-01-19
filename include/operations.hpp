
#ifndef __CMATH_OPERATIONS_HPP__
#define __CMATH_OPERATIONS_HPP__ 1

#include <vector/vec2.hpp>
#include <vector/vec3.hpp>
#include <matrix/mat4.hpp>

namespace cmath {

    template<typename T, typename U>
    Mat4<T> Translate(const Mat4<T>& mat, const Vec3<U>& vec)
    {
        Mat4<T> result = mat;

        result.m03 += vec.x;
        result.m13 += vec.y;
        result.m23 += vec.z;

        return result;
    }

    template<typename T, typename U>
    Mat4<T> Scale(const Mat4<T>& mat, const Vec3<U>& vec)
    {
        Mat4<T> result = mat;

        result.m00 *= vec.x;
        result.m11 *= vec.y;
        result.m22 *= vec.z;

        return result;
    }

    template<typename T, typename U>
    Mat4<T> Rotate(const Mat4<T>& mat, float angle, const Vec3<U>& axis)
    {
        Mat4<T> result = mat;

        U c = cos(angle);
        U s = sin(angle);
        U one_c = 1 - c;

        U x = axis.x;
        U y = axis.y;
        U z = axis.z;

        Mat4<T> rotation(
            c + x * x * one_c,      x * y * one_c - z * s,  x * z * one_c + y * s, 0,
            y * x * one_c + z * s,  c + y * y * one_c,      y * z * one_c - x * s, 0,
            z * x * one_c - y * s,  z * y * one_c + x * s,  c + z * z * one_c,     0,
            0,                       0,                       0,                      1
        );

        result *= rotation;
        return result;
    }

    template<typename T, typename U>
    Mat4<T> LookAt(const Vec3<T>& eye, const Vec3<T>& center, const Vec3<T>& up)
    {
        Vec3<T> f = (center - eye).Normalized();
        Vec3<T> s = Cross(f, up).Normalized();
        Vec3<T> u = Cross(s, f);

        Mat4<T> result = Identity<T>();
        result.m00 = s.x;
        result.m01 = s.y;
        result.m02 = s.z;
        result.m10 = u.x;
        result.m11 = u.y;
        result.m12 = u.z;
        result.m20 = -f.x;
        result.m21 = -f.y;
        result.m22 = -f.z;
        result.m03 = -Dot(s, eye);
        result.m13 = -Dot(u, eye);
        result.m23 = Dot(f, eye);

        return result;
    }

    template<typename T>
    Mat4<T> Perspective(float fov, float aspect, float near, float far)
    {
        Mat4<T> result;
        float tanHalfFov = tan(fov / 2.0f);

        result.m00 = 1.0f / (aspect * tanHalfFov);
        result.m11 = 1.0f / (tanHalfFov);
        result.m22 = -(far + near) / (far - near);
        result.m23 = -(2.0f * far * near) / (far - near);
        result.m32 = -1.0f;
        result.m33 = 0.0f;

        return result;
    }

};

#endif // __CMATH_OPERATIONS_HPP__