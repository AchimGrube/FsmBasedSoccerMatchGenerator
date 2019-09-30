namespace Helper
{
	template<typename T>
	static int sign(T value)
	{
		return (T(0) < value) - (value < T(0));
	}
}