
#ifndef __CMATH_MAT4_HPP__
#define __CMATH_MAT4_HPP__ 1

namespace cmath {

template<typename T>
struct Mat4
{
	static_assert(sizeof(Mat4<T>) == 16 * sizeof(T), "Mat4 size incorrect");

	union
	{
		T data[16];
		struct
		{
			T m00, m01, m02, m03;
			T m10, m11, m12, m13;
			T m20, m21, m22, m23;
			T m30, m31, m32, m33;
		};
	};
  

	Mat4() : data{	
								T(0), T(0), T(0), T(0),
								T(0), T(0), T(0), T(0),
								T(0), T(0), T(0), T(0),
								T(0), T(0), T(0), T(0)
							}
    {
    }

};

template<typename T>
static Mat4<T> Identity()
{
	Mat4<T> result;

	result.m00 = T(1);
	result.m11 = T(1);
	result.m22 = T(1);
	result.m33 = T(1);

	return result;
}

template<typename T>
static Mat4<T> Ortho(T left, T right, T bottom, T top, T nearVal, T farVal)
{
	static_assert(left == right || bottom == top || nearVal == farVal, "Invalid ortho parameters");

	Mat4<T> result;

	result.m00 = T(2) / (right - left);
	result.m11 = T(2) / (top - bottom);
	result.m22 = T(-2) / (farVal - nearVal);
	result.m03 = -(right + left) / (right - left);
	result.m13 = -(top + bottom) / (top - bottom);
	result.m23 = -(farVal + nearVal) / (farVal - nearVal);
	result.m33 = T(1);

	return result;
}

typedef Mat4<float> Mat4f;
typedef Mat4<double> Mat4d;

} // namespace cmath

#endif // __CMATH_MAT4_HPP__