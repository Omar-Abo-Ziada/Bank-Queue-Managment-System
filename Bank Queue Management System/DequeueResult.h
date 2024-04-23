#pragma once

template <typename T>
struct DequeueResult
{
public:
	bool IsSuccess;
	T Value;
};
