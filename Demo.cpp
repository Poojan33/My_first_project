#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>


using namespace std;
using namespace cv;
int corner_slider = 5;
Mat gray_img,img;
void on_trackbar(int, void*)
{
	if (gray_img.empty())
		return;
	int max_corner = max(1, corner_slider);
	setTrackbarPos("No of Corners", "Corner Image", max_corner);
	vector <Point2d> corners;
	float quality = 0.01;
	goodFeaturesToTrack(gray_img, corners, max_corner, quality, 10);
	Mat temp = img.clone();
	for (int i = 0; i < corners.size();i++)
	{
		circle(temp, corners[i], 4, (0, 0, 255), -1);
	}
	imshow("Corner Image", temp);

}
int main()
{
	img = imread("one.jfif");
	cvtColor(img, gray_img, COLOR_BGR2GRAY);
	namedWindow("Original Image", WINDOW_NORMAL);
		namedWindow("Corner Image", WINDOW_NORMAL);
	imshow("Original Image", img);
	imshow("Corner Image", img);
	createTrackbar("No of Corners", "Corner Image", &corner_slider, 250, on_trackbar);
	while (char(waitKey(1))!= 'q'){}
	return 0;
}
