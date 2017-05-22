#include<iostream>
#include<csignal>
#include <opencv2/opencv.hpp>

void testfunc(){
	printf("test\n");
	cv::Mat ret = (cv::Mat)(cv::Mat_<double>(3,3)<< 1,2,3,4,5,6,7,8,9);
	float a = 0.5;
	float b = 0.2;
	cv::Mat res = ret * a + b;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j<3;j++){
		 printf("val = %f ",(float)res.at<double>(i,j));
		}
	}
}
bool stop = false;
void sigIntHandler(int signal){
	stop = true;
}

int main(int argc,char** argv){
//	testfunc();
std::signal(SIGINT,sigIntHandler);
	cv::Mat frame;
	cv::VideoCapture cap(0);
if(!cap.isOpened()){
	printf("\ncam not init correctly!\n");
	return -1;
}
while(true){
	
	if(!cap.read(frame))
		break;
	cv::Mat src = cv::Mat(frame);
	cv::imshow("win",src);
	cv::namedWindow("win",CV_WINDOW_AUTOSIZE);
     //cv::moveWindow("win",100,100);
	if(cv::waitKey(30) == 27){
		printf("cam quit correctly!\n");	
		cap.release();
		break;
	}
}
return 0;
}
