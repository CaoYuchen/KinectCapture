#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <windows.h>
#include <vector>

std::string type2str(int type);

int main()
{
	std::vector<cv::String> files;
	cv::String dir_name = "..\\..\\Dataset\\depth\\*.bmp";
	cv::glob(dir_name, files);


	for (int i = 0; i < files.size(); i++)
	{
		//std::cout << filename << std::endl;
		cv::Mat bmp8 = cv::imread(files[i].c_str());
		//cv::imshow("bmp8",bmp8);
		//cv::waitKey(6000);
		//std::cout << files[i].c_str() << std::endl;

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
	
		
		std::stringstream stream;
		std::string outfile;
		stream << files[i].c_str() << ".png";
		stream >> outfile;

		std::cout << i << std::endl;

		std::vector<int> compression_params;
		compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
		compression_params.push_back(9);
		cv::imwrite(outfile, bmp16, compression_params);
		
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


