#pragma once
#include <opencv2/core/core.hpp>
#include <net.h>
#include <stdio.h>
#include <math.h>

struct Object
{
	cv::Rect_<float> rect;
	int label;
	float prob;

};


class Yolo
{
public:
	Yolo();

	int load( int target_size, const float* norm_vals, bool use_gpu = false);

	int detect(const cv::Mat& rgb, std::vector<Object>& objects, float prob_threshold = 0.25f, float nms_threshold = 0.45f);

	int draw(cv::Mat& rgb, const std::vector<Object>& objects);

private:

	ncnn::Net yolo;

	int target_size;
	float norm_vals[3];
	int image_w;
	int image_h;
	int in_w;
	int in_h;

};