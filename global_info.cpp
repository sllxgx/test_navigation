#include "global_info.h"
#include "map_info/map_info.h"

using namespace pln;

void SetSlamMap(const cv::Mat& in_map, const Coor& in_tl_coor)
{
	std::shared_ptr<SlamMap> gptr_slam_map = SlamMap::getInstance();
	for (size_t i = 0; i < in_map.rows; ++i)
	{
		for (size_t j = 0; j < in_map.cols; ++j)
		{
			Coor t_wcoor = gptr_slam_map->ICoor2WCoor(Coor(j, i), in_tl_coor.x, in_tl_coor.y);
			auto t_val = in_map.at<uchar>(i, j);
			gptr_slam_map->setValue(t_wcoor.x, t_wcoor.y, t_val);
		}
	}
	cv::Mat t_slam_map;
	gptr_slam_map->get_grid_map(t_slam_map);
	cv::imwrite("temp_slam_map.png", t_slam_map);
}

void SetNaviMap(std::shared_ptr<NaviMapBase> ptr_navi_map)
{
	int t_width = 0;
	ptr_navi_map->getNodeWidth(Coor(0, 0), t_width);
}