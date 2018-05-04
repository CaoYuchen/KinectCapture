#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

std::string type2str(int type);

int main()
{
	const int fileNumber = 1;

	for (int i = 0; i < fileNumber; i++)
	{
		std::stringstream stream;
		std::string filename;
		stream << "..\\..\\Dataset\\depth\\" << i << ".bmp";
		stream >> filename;

		//std::cout << filename << std::endl;
		cv::Mat bmp8 = cv::imread(filename);
		//cv::imshow("bmp8",bmp8);
		//cv::waitKey(6000);

		cv::Mat mv[4];
		cv::Mat temp;
		bmp8.convertTo(temp, CV_16UC1);
		cv::split(temp, mv);

		cv::Mat bmp16(424, 512, CV_16UC1);
		bmp16 = mv[0] * 256 + mv[1];
		//std::string type = type2str(mv[0].type());
		//std::cout << type;
		//while(1)
		//cv::imshow("bmp16", bmp16);
		//cv::waitKey(6000);

		stream.clear();
		std::string outfile;
		stream << "..\\..\\Dataset\\depth16\\" << i << ".png";
		stream >> outfile;
		cv::imwrite(outfile, bmp16);
	}
	return 0;
}


std::string type2str(int type) {
	std::string r;

	uchar depth = type & CV_MAT_DEPTH_MASK;
	uchar chans = 1 + (type >> CV_CN_SHIFT);

	switch (depth) {
	case CV_8U:  r = "8U"; break;
	case CV_8S:  r = "8S"; break;
	case CV_16U: r = "16U"; break;
	case CV_16S: r = "16S"; break;
	case CV_32S: r = "32S"; break;
	case CV_32F: r = "32F"; break;
	case CV_64F: r = "64F"; break;
	default:     r = "User"; break;
	}

	r += "C";
	r += (chans + '0');

	return r;
}


