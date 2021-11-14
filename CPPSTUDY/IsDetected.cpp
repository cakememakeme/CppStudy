#include <iostream>
#include <cmath>

//각도랑 좌표랑 방향벡터 주고 해당 각도 내에 타겟있는지
//sin cos tan arccos arcsin arctan 사용가능
bool IsDetected(const float mon_pos_x, const  float mon_pos_y, const float mon_view_x, const float mon_view_y, const float mon_detect_degree, const float target_pos_x, const float target_pos_y)
{
	const float PI = 3.141592f;
	const float toDegree = PI / 180.0f;
	const float toRadian = 180.0f / PI;

	const float target_to_mon_x = mon_pos_x - target_pos_x;
	const float target_to_mon_y = mon_pos_y - target_pos_y;

	const float dot = (target_to_mon_x * mon_view_x) + (target_to_mon_y * mon_view_y);

	const float theta = acosf(dot) * toDegree;

	if (theta <= mon_detect_degree)
	{
		return true;
	}
	else
	{
		return false;
	}
	
	return true;
}

// 1번
bool IsRanged(const int base_pos_x, const int base_pos_y, const int target_pos_x, const int target_pos_y, const int range)
{
	const int dist_x = target_pos_x - base_pos_x;
	const int dist_y = target_pos_y - base_pos_y;
	// int 오버플로 주의?
	const bool is_range = (dist_x * dist_x) + (dist_y * dist_y) <= (range * range);
	
	return is_range;
}

int main()
{
	
	return 0;
}