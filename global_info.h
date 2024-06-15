#pragma once
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

static const int kMapMaxSize = 1600;
static const int kGMapMinSize = 160;
static const int kGMapMinBound = 79;
static const int kGMapMaxBound = 799;
static const int kGMapMaxBoundMinus = -800;

namespace pln
{
	typedef cv::Point Coor;
	typedef cv::Rect Boundary;
}

struct QuadtreeNode
{
	QuadtreeNode(const pln::Coor& in_pos, const uint8_t& in_data, const bool& in_flag = false)
		: pos(in_pos), data(in_data), isleaf(in_flag) {}

	QuadtreeNode(const QuadtreeNode& in_node)
	{
		pos = in_node.pos;
		data = in_node.data;
		isleaf = in_node.isleaf;
	}

	QuadtreeNode() : QuadtreeNode(pln::Coor(0, 0), 0) {}

	bool isleaf;
	uint8_t data;
	pln::Coor pos;
};

void SetSlamMap(const cv::Mat& map, const pln::Coor& tl_coor);

#include <navi_map_update/navi_map_update.h>
void SetNaviMap(std::shared_ptr<NaviMapBase> ptr_navi_map);